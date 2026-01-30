#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

std::vector<int> RotateRight(const std::vector<int>& vect,
                             unsigned int no_rotations);
std::vector<int> RotateChunks(const std::vector<int>& vect,
                              unsigned int chunk_size,
                              unsigned int no_rotations);

#endif  // SOLUTION_HPP
