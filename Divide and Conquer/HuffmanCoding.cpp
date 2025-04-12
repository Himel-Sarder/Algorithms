#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman Tree Node
struct Node
{
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison for priority queue
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq; // Min-heap based on frequency
    }
};

// Build Huffman Tree and return root
Node *buildHuffmanTree(const string &text)
{
    // Count character frequencies
    unordered_map<char, unsigned> freq;
    for (char c : text)
        freq[c]++;

    // Create priority queue
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Build tree by combining nodes
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *internal = new Node('\0', left->freq + right->freq);
        internal->left = left;
        internal->right = right;
        pq.push(internal);
    }
    return pq.top();
}

// Generate Huffman Codes from tree
void generateCodes(Node *root, string code, unordered_map<char, string> &huffmanCode)
{
    if (!root)
        return;

    if (!root->left && !root->right) // Leaf node
        huffmanCode[root->data] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main()
{
    string text = "hello world";

    // Build Huffman Tree
    Node *root = buildHuffmanTree(text);

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Print codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << endl;

    // Encode original text
    string encoded;
    for (char c : text)
        encoded += huffmanCode[c];

    cout << "\nEncoded string:\n"
         << encoded << endl;

    return 0;
}
