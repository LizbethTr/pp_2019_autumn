// Copyright 2019 Trenina Elizaveta
#ifndef MODULES_TASK_3_TRENINA_E_SHELL_BATCHER_SORT_H_
#define MODULES_TASK_3_TRENINA_E_SHELL_BATCHER_SORT_H_

#include<mpi.h>
#include <vector>

typedef struct {
    int rank1;
    int rank2;
} pair;



//void batcher(int proc_num);
//void build_Network(std::vector<int> procsVec);
//void build_Connection(std::vector<int>UpProcVec, std::vector<int>DownProcVec);

void batcher(int proc_num);
void buildNetwork(std::vector<int> procsVec);
void buildConnection(std::vector<int>UpProcVec, std::vector<int>DownProcVec);

std::vector<int> GetRandomVector(int n);

std::vector<int> Shell(std::vector<int> arr);

//std::vector<int> EvenSplit(std::vector<int> arr1, std::vector<int> arr2);
//
//std::vector<int> OddSplit(std::vector<int> arr1, std::vector<int> arr2);
//
//std::vector<int> EvenOddSplit(std::vector<int> arr1, std::vector<int> arr2);

std::vector<int> Shell_Batcher(std::vector<int> arr);

#endif  // MODULES_TASK_3_TRENINA_E_SHELL_BATCHER_SORT_H_
