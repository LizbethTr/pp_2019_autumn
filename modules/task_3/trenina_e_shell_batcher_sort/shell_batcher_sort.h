// Copyright 2019 Trenina Elizaveta
#ifndef MODULES_TASK_3_TRENINA_E_SHELL_BATCHER_SORT_SHELL_BATCHER_SORT_H_
#define MODULES_TASK_3_TRENINA_E_SHELL_BATCHER_SORT_SHELL_BATCHER_SORT_H_

#include <vector>

typedef struct {
    int rank1;
    int rank2;
} pair;


std::vector<int> GetRandomVector(int n);

std::vector<int> Shell(std::vector<int> arr);

std::vector<int> Shell_Batcher(std::vector<int> arr);

#endif  // MODULES_TASK_3_TRENINA_E_SHELL_BATCHER_SORT_SHELL_BATCHER_SORT_H_
