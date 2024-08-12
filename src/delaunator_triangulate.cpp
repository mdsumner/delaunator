#include <cpp11.hpp>
#include "cpp11/matrix.hpp"
using namespace cpp11;

namespace writable = cpp11::writable;


#include "delaunator.hpp.cpp"


[[cpp11::register]]
integers delaunator_triangulate_cpp(std::vector<double> coords) {
  //triangulation happens here
  delaunator::Delaunator d(coords);
 // Rprintf("%lu\n", d.triangles.size() );
  writable::integers x(d.triangles.size());

  for(std::size_t i = 0; i < d.triangles.size(); i+=3) {
   x[i] = d.triangles[i];
   x[i + 1] = d.triangles[i + 1];
   x[i + 2] = d.triangles[i + 2];
  }


 return x;
}


integers example_cpp() {
/* x0, y0, x1, y1, ... */
  std::vector<double> coords = {-1, 1, 1, 1, 1, -1, -1, -1};

  //triangulation happens here
  delaunator::Delaunator d(coords);

  for(std::size_t i = 0; i < d.triangles.size(); i+=3) {
    Rprintf(
      "Triangle points: [[%f, %f], [%f, %f], [%f, %f]]\n",
      d.coords[2 * d.triangles[i]],        //tx0
      d.coords[2 * d.triangles[i] + 1],    //ty0
      d.coords[2 * d.triangles[i + 1]],    //tx1
      d.coords[2 * d.triangles[i + 1] + 1],//ty1
      d.coords[2 * d.triangles[i + 2]],    //tx2
      d.coords[2 * d.triangles[i + 2] + 1] //ty2
    );
  }
  writable::integers x(1);
  x[0] = 1;
  return x;
}
