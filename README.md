# Algorithms
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Algorithms is a comprehensive collection of fundamental algorithms implemented in C++, categorized into Backtracking, Divide and Conquer, Dynamic Programming, Greedy, Pattern Matching, and Sorting. This repository serves as a valuable resource for understanding and learning various algorithmic techniques.

## Table of Contents
- [Repository Structure](#repository-structure)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Project Description

The Algorithms repository provides a wide range of algorithms, each implemented in C++. The algorithms are organized into categories:

*   **Backtracking**: Graph Coloring, N-Queens
*   **Divide and Conquer**: Doubly Even Magic Square, Huffman Coding, Odd Magic Square, Singly Even Magic Square, Tower of Hanoi
*   **Dynamic Programming**: All Pairs Shortest Path (Floyd Warshall), Knapsack, Longest Common Subsequence, Longest Increasing Subsequence, Matrix Chain Multiplication, Traveling Salesman
*   **Greedy**: Job Sequence with Deadlines, Single Source Shortest Path (Bellman Ford, Dijkstra)
*   **Pattern Matching**: Robin Karp
*   **Sorting**: Bubble Sort, Bucket Sort, Counting Sort, Heap Sort, Insertion Sort, Merge Sort, Quick Sort, Radix Sort, Selection Sort, Shell Sort

## Features

*   **Comprehensive Algorithm Collection**: A wide range of algorithms, each implemented in C++.
*   **Categorized for Easy Reference**: Algorithms are organized into categories for easy reference.
*   **Example Usage**: Each algorithm includes example usage.

## Repository Structure

```plaintext
├── Backtracking/ # Backtracking algorithms
│   ├── GraphColoring.cpp
│   ├── N-Queens.cpp
│   └── README.md
├── Divide and Conquer/ # Divide and Conquer algorithms
│   ├── DoublyEvenMS.cpp
│   ├── HuffmanCoding.cpp
│   ├── OddMagicSquare.cpp
│   ├── SinglyEvenMagicS.cpp
│   ├── TowerOfHanoi.cpp
│   └── README.md
├── Dynamic Programming/ # Dynamic Programming algorithms
│   ├── All Pairs Shortest Path/
│   │   ├── FloydWarshall.cpp
│   │   └── README.md
│   ├── Knapsack.cpp
│   ├── KnapsackDPArray.cpp
│   ├── KnapsackDPArray.md
│   ├── LCS.cpp
│   ├── LIS.cpp
│   ├── LIS.md
│   ├── MatrixChainMRecursion.cpp
│   ├── MatrixChainMultiplicatio.cpp
│   ├── TravelingSalesMan.cpp
│   ├── TravelingSalesMan.md
│   └── README.md
├── Greedy/ # Greedy algorithms
│   ├── JobSequence.cpp
│   ├── JobSequence.cpp
│   ├── README.md
│   ├── BellmanFord.cpp
│   ├── BellmanFord.md
│   ├── Dijkstra.md
│   ├── Dijkstras.cpp
│   └── README.md
├── Pattern Matching/ # Pattern Matching algorithms
│   ├── README.md
│   └── RobinKarp..cpp
├── Sorting/ # Sorting algorithms
│   ├── Bubble Sort.cpp
│   ├── Bucket Sort.cpp
│   ├── Counting Sort.cpp
│   ├── HeapSort.cpp
│   ├── Insertion Sort.cpp
│   ├── Merge Sort01.cpp
│   ├── Merge Sort02.cpp
│   ├── Merge Sort03 (BEST).cpp
│   ├── Quick Sort.cpp
│   ├── README.md
│   ├── Radix Sort.cpp
│   ├── Selection Sort.cpp
│   └── Shell Sort.cpp
├── LICENSE
└── README.md
```

## Installation

This repository does not require installation. Simply clone the repository and navigate to the directory.

```bash
git clone https://github.com/username/Algorithms.git
cd Algorithms
```

## Usage

To use the algorithms, navigate to the respective directory and compile the C++ file.

```bash
# Navigate to the Sorting directory
cd Sorting

# Compile the Bubble Sort algorithm
g++ Bubble Sort.cpp -o BubbleSort

# Run the Bubble Sort algorithm
./BubbleSort
```

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository 🍴.
2. Create a new branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m "Add your feature"`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For questions or feedback, open an issue on GitHub.
