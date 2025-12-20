# Task Scheduler (DSA Project in C++)

## Description
A priority-based CPU task scheduler implemented using core
Data Structures and Algorithms in C++. The scheduler selects
tasks based on priority and arrival time and computes waiting
and turnaround times.

## Features
- Priority-based scheduling using Max Heap
- Dynamic user input
- Arrival and execution time handling
- Waiting and turnaround time calculation

## Data Structures Used
- Priority Queue (Heap)
- Vector
- Sorting

## Time Complexity
- Scheduling: O(n log n)
- Task Selection: O(log n)

## How to Run
```bash
g++ src/task_scheduler.cpp -o scheduler
./scheduler
