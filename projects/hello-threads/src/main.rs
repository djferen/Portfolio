use std::sync::atomic::{AtomicBool, Ordering};
use std::thread;
use std::vec;

// This ready flag indicates whether the threads should begin to run.
static READY: AtomicBool = AtomicBool::new(false);

// This winner flag indicates if a thread was able to win the race condition.
static WINNER: AtomicBool = AtomicBool::new(false);

fn count1m(id: i32) {
    // Wait for the ready to run signal.
    while !READY.load(Ordering::Relaxed) {}

    // Run for a while and don't optimize the loop.
    for _ in 0..1000000 {
        // Do something that doesn't get optimized away.f
    }

    // Safely declare the winning thread.
    WINNER.store(true, Ordering::Relaxed);

    println!("thread #{} exit!", id);
}

fn main() {
    let mut threads = vec![];

    println!("spawning 10 threads that count to 1 million...");
    for i in 1..=10 {
        threads.push(thread::spawn(move || count1m(i)));
    }

    //  threads.
    READY.store(true, Ordering::Relaxed);

    // Exited thread bodies and merge back to "parent".
    for thread in threads {
        thread.join().unwrap();
    }
}
