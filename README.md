# ListVSArray

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Why `std::vector` is Faster](#why-stdvector-is-faster)

## Introduction
The purpose of this project is to provide a detailed comparison between the `insert` and `erase` functions of `std::vector` and `std::list` in C++.

## Build and Run
To clone and run this project, you'll need [Git](https://git-scm.com) and [Visual Studio](https://visualstudio.microsoft.com/) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/ListVSArray

# Go into the repository
$ cd ListVSArray
```

Open the `ListVSArray.sln` file in Visual Studio and build the solution. Then, run the project.

## Why `std::vector` is Faster
In this project, we observe that `std::vector` generally performs faster than `std::list` for the `insert` and `erase` operations. This is because `std::vector` stores elements in contiguous memory, which allows for better cache locality and faster access times. Although `std::vector` may require shifting elements during insertion and deletion, the overall performance benefits from the reduced overhead of pointer manipulation and better memory access patterns compared to `std::list`, which uses a doubly linked list structure.
This project compares the performance of the `insert` and `erase` functions for `std::vector` and `std::list` in C++.
