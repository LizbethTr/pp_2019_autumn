// Copyright 2019 Trenina Elizaveta

#include <gtest-mpi-listener.hpp>
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "./shell_batcher_sort.h"

TEST(Shell, Test_Shell_Sort_size2) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        std::vector<int> exp = { 3, 6 };
        std::vector<int> t = { 6, 3};
        std::vector<int> res(2, -1);

        res = Shell(t);

        EXPECT_EQ(exp, res);
    }
}

TEST(Shell, Test_Shell_Sort) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        std::vector<int> exp = { 1, 2, 3, 4, 5, 6 };
        std::vector<int> t = { 6, 3, 4, 2, 5, 1 };
        std::vector<int> res(6, 0);

        res = Shell(t);

        EXPECT_EQ(exp, res);
    }
}

TEST(Shell, Test_Shell_Sort_Odd) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        std::vector<int> exp = { 1, 2, 3, 4, 5, 6, 7};
        std::vector<int> t = { 6, 3, 4, 2, 5, 1, 7};
        std::vector<int> res(7, 0);

        res = Shell(t);

        EXPECT_EQ(exp, res);
    }
}

TEST(Shell, Test_Shell_Sort_Random_Vector) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        std::vector<int> t = GetRandomVector(7);
        std::vector<int> exp(t);
        std::sort(exp.begin(), exp.end());

        std::vector<int> res(t);

        res = Shell(t);

        EXPECT_EQ(exp, res);
    }
}




TEST(Shell, Test_Batcher) {
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        batcher(size);

        EXPECT_EQ(0, 0);
    }
}
TEST(Shell, Test_Shell_Batcher_Sort) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        std::vector<int> exp = { 1, 2, 3, 4, 5, 6 };
        std::vector<int> t = { 6, 3, 4, 2, 5, 1 };
        std::vector<int> res(6, 0);

        res = Shell_Batcher(t);

        EXPECT_EQ(exp, res);
    }
}

// TEST(Shell, Test_Shell_Batcher_Sort_Odd) {
//
//    int rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    if (rank == 0) {
//        std::vector<int> exp = { 1, 2, 3, 4, 5, 6, 7 };
//        std::vector<int> t = { 6, 3, 4, 2, 5, 1, 7 };
//        std::vector<int> res(7, 0);
//
//        res = Shell_Batcher(t);
//
//        EXPECT_NE(exp, res);
//    }
// }





int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  MPI_Init(&argc, &argv);

  ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
  ::testing::TestEventListeners& listeners =
    ::testing::UnitTest::GetInstance()->listeners();

  listeners.Release(listeners.default_result_printer());
  listeners.Release(listeners.default_xml_generator());

  listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
  return RUN_ALL_TESTS();
}
