#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class FileSystem {
 private:
  struct Node {
    string name;
    // Can be extended to store additional file information (size, type)
    bool isDirectory;
    unordered_map<string, Node*> children;
  };

  Node* root;
  Node* current;

 public:
  FileSystem() {
    root = new Node{"/", true, {}};
    current = root;
  }

  ~FileSystem() {
    // Implement recursive deletion to avoid memory leaks
    delete root;
  }

  void listDirectory() {
    if (!current->isDirectory) {
      cout << "Not a directory." << endl;
      return;
    }

    if (current->children.empty()) {
      cout << "Directory is empty." << endl;
      return;
    }

    cout << "Contents of " << current->name << ":" << endl;
    for (const auto& [name, node] : current->children) {
      cout << name << (node->isDirectory ? " (dir)" : "") << endl;
    }
  }

  void isDirectory(const string& path) {

    // Split path based on separators (e.g., '/')
    vector<string> tokens;
    string token;
    for (char c : path) {
      if (c == '/') {
        if (!token.empty()) {
          tokens.push_back(token);
        }
        token = "";
      } else {
        token += c;
      }
    }
    if (!token.empty()) {
      tokens.push_back(token);
    }

    Node* temp = current;
    for (const string& dir : tokens) {
      if (temp->isDirectory && temp->children.count(dir)) {
        temp = temp->children[dir];
      } else {
        cout << "Directory not found: " << path << endl;
        return false;
      }
    }

    return true;
  }

  void changeDirectory(const string& path) {
    if (path == "/") {
      current = root;
      return;
    }

    // Split path based on separators (e.g., '/')
    vector<string> tokens;
    string token;
    for (char c : path) {
      if (c == '/') {
        if (!token.empty()) {
          tokens.push_back(token);
        }
        token = "";
      } else {
        token += c;
      }
    }
    if (!token.empty()) {
      tokens.push_back(token);
    }

    Node* temp = current;
    for (const string& dir : tokens) {
      if (temp->isDirectory && temp->children.count(dir)) {
        temp = temp->children[dir];
      } else {
        cout << "Directory not found: " << path << endl;
        return;
      }
    }

    current = temp;
  }

};
