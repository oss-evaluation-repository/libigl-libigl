#ifndef IGL_ADJACENCY_MATRIX_H
#define IGL_ADJACENCY_MATRIX_H
#include "igl_inline.h"

#define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET
#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace igl 
{
  // Constructs the graph adjacency matrix  of a given mesh (V,F)
  // Templates:
  //   T  should be a eigen sparse matrix primitive type like int or double
  // Inputs:
  //   F  #F by dim list of mesh simplices
  // Outputs: 
  //   A  max(F) by max(F) cotangent matrix, each row i corresponding to V(i,:)
  //
  // Example:
  //   // Mesh in (V,F)
  //   Eigen::SparseMatrix<double> A;
  //   adjacency_matrix(F,A);
  //   // sum each row 
  //   SparseVector<double> Asum;
  //   sum(A,1,Asum);
  //   // Convert row sums into diagonal of sparse matrix
  //   SparseMatrix<double> Adiag;
  //   diag(Asum,Adiag);
  //   // Build uniform laplacian
  //   SparseMatrix<double> U;
  //   U = A-Adiag;
  //
  // See also: edges, cotmatrix, diag
  template <typename T>
  IGL_INLINE void adjacency_matrix(
    const Eigen::MatrixXi & F, 
    Eigen::SparseMatrix<T>& A);
}

#ifdef IGL_HEADER_ONLY
#  include "adjacency_matrix.cpp"
#endif

#endif
