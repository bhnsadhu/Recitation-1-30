#include <iostream>

#include "solution.hpp"

void PrintVector(const std::vector<int>& vect) {
  for (const int& elem : vect) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
int main() {
  // TEST CODE HERE

  // std::vector<int> rotated_right = {22, 13, 3, 4, 16, 6, 7, 32, 9, 10};
  // unsigned int no_rotations = 3;
  // std::cout << "Original vector: ";
  // PrintVector(rotated_right);
  // std::cout << "RotateRight by " << no_rotations << ": ";
  // rotated_right = RotateRight(rotated_right, no_rotations);
  // PrintVector(rotated_right);

  // std::vector<int> rotated_chunks = {22, 13, 3, 4, 16, 6};
  // unsigned int chunk_size = 3;
  // no_rotations = 1;
  // std::cout << "Original vector: ";
  // PrintVector(rotated_chunks);
  // std::cout << "RotateChunks by " << no_rotations << " with chunk size " <<
  // chunk_size << ": "; rotated_chunks = RotateChunks(rotated_chunks,
  // chunk_size, no_rotations); PrintVector(rotated_chunks);

  return 0;
}
