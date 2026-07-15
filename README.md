# Competitive Programming

A lightweight archive of my competitive programming practice, C++ templates, and algorithm notes. This repo is not meant to be a full open-source project; it is a public snapshot of how I practice problem solving, build reusable patterns, and improve my C++ fluency.

## What is in this repo

```text
.
├── snippets/              # Reusable C++ patterns and templates
├── summer2024archive/     # Archived practice solutions from summer 2024
├── reboot/                # Reboot of my algorithmic programming skills starting summer 2026
└── WORKLOG.md             # Lightweight daily/weekly practice log
```

## Highlights

- **Language:** C++
- **Focus areas:** data structures, graph/tree algorithms, number theory, binary search, implementation, and contest-style problem solving
- **Reusable snippets:** DSU, segment tree, binary search on answer, number theory helpers, and a base C++ template
- **Archived solutions:** a mix of CSES, USACO, and Codeforces-style practice problems
- **Progress tracking:** a simple work log that records what I practiced, what I learned, and what I want to revisit

## How to read this repo

This repository is organized as a personal learning archive. The `snippets/` folder contains small reusable building blocks that I can copy into contest solutions. The `summer2024archive/` folder keeps older practice solutions so I can track progress over time. The `reboot/` folder is for newer practice as I rebuild and sharpen my algorithmic programming skills.

Some archived files may reflect practice-state work rather than polished final submissions. I keep them here because the goal of the repo is to show consistent learning and algorithmic growth, not to package a production library.

## Progress log

I keep a lightweight progress log in [`WORKLOG.md`](WORKLOG.md). It is not a formal changelog; it is a simple record of practice sessions, concepts reviewed, problems attempted, and cleanup work done over time.

The goal is to make the repo show consistent effort without overcomplicating it. Entries are intentionally short and focused on actual work completed.

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
