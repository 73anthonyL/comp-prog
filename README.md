# Competitive Programming

A lightweight archive of my competitive programming practice, C++ templates, and algorithm notes. This repo is not meant to be a full open-source project; it is a public snapshot of how I practice problem solving, build reusable patterns, and improve my C++ fluency.

## What is in this repo

```text
.
├── snippets/              # Reusable C++ patterns and templates
└── summer2024archive/     # Archived practice solutions from summer 2024
└── reboot/                # reboot my algorithmic programming skills (starting summer 2026)
```

## Highlights

- **Language:** C++
- **Focus areas:** data structures, graph/tree algorithms, number theory, binary search, implementation, and contest-style problem solving
- **Reusable snippets:** DSU, segment tree, binary search on answer, number theory helpers, and a base C++ template
- **Archived solutions:** a mix of CSES, USACO, and Codeforces-style practice problems

## How to read this repo

This repository is organized as a personal learning archive. The `snippets/` folder contains small reusable building blocks that I can copy into contest solutions. The `summer2024archive/` folder keeps older practice solutions so I can track progress over time.

Some archived files may reflect practice-state work rather than polished final submissions. I keep them here because the goal of the repo is to show consistent learning and algorithmic growth, not to package a production library.

## Compile a solution

Most standalone solution files can be compiled with a standard C++17 command:

```bash
g++ -std=c++17 -O2 -Wall -Wextra summer2024archive/Weird_Algorithm.cpp -o main
./main
```

For quick local testing, I usually compile one file at a time rather than building the whole repository.

## Topics covered

| Area | Examples |
|---|---|
| Data structures | DSU, segment tree, tree queries |
| Graphs and trees | subtree queries, distance queries, company queries |
| Math | number theory, parity, combinatorics, bit strings |
| Search | binary search on answer, constructive logic |
| Implementation | contest templates, input/output patterns, debugging macros |

## Why this repo exists

I use this repository to document my competitive programming practice and keep a clean record of the algorithms I am learning. It is meant to give profile visitors a quick look at my problem-solving style, C++ experience, and long-term technical development.

## Repository upkeep

I try to keep this repo simple and readable:

- Keep reusable code in `snippets/`
- Keep older solved problems in clearly named archive folders
- Avoid committing local build files, editor folders, or macOS metadata
- Use clear commit messages when adding or cleaning solutions
- Keep the README focused on what the repo is and how to navigate it

