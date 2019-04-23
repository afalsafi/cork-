// +-------------------------------------------------------------------------
// | main.cpp
// |
// | Author: Ali Falsafi
// +-------------------------------------------------------------------------
// | COPYRIGHT:
// |    Copyright Gilbert Bernstein 2013
// |    See the included COPYRIGHT file for further details.
// |
// |    This file is part of the Cork library.
// |
// |    Cork is free software: you can redistribute it and/or modify
// |    it under the terms of the GNU Lesser General Public License as
// |    published by the Free Software Foundation, either version 3 of
// |    the License, or (at your option) any later version.
// |
// |    Cork is distributed in the hope that it will be useful,
// |    but WITHOUT ANY WARRANTY; without even the implied warranty of
// |    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// |    GNU Lesser General Public License for more details.
// |
// |    You should have received a copy
// |    of the GNU Lesser General Public License
// |    along with Cork.  If not, see <http://www.gnu.org/licenses/>.
// +-------------------------------------------------------------------------

// This file contains a command line program that can be used
// to exercise Cork's functionality without having to write
// any code.


#include "cork.hh"
#include "cork_interface.hh"

int main(int argc, char *argv[]) {
  std::vector<point_t> vertices0;
  std::vector<face_t> faces0;
  point_t origin0{0.0, 0.0, 0.0};
  point_t size0{1.0, 1.0, 1.0};
  vertices0 = cube_vertice_maker(origin0 ,size0);
  make_faces_from_nodes(vertices0, faces0);

  std::vector<point_t> vertices1;
  std::vector<face_t> faces1;
  point_t origin1{0.5, 0.5, 0.5};
  point_t size1{1.0, 1.5, 1.0};
  vertices1 = cube_vertice_maker(origin1 ,size1);
  // vertices1.pop_back();
  make_faces_from_nodes(vertices1, faces1);
  CorkTriMesh in0;
  CorkTriMesh in1;
  CorkTriMesh intersection;
  CorkTriMesh difference;
  CorkTriMesh intersection_and_difference;
  corktrimesh_maker_from_node_faces(vertices0, faces0, &in0);
  corktrimesh_maker_from_node_faces(vertices1, faces1, &in1);
  
  computeIntersection(in0, in1, &intersection);
  computeDifference(in0, in1, &difference);
  intersect_of_faces(intersection, difference, &intersection_and_difference);

  auto &&vol = volume_calculator(intersection);
  auto && normal = average_normal_calculator(intersection_and_difference);
  std::cout << "the normal vector is:" << std::endl <<normal << std::endl;
  std::cout << "the volume is:" << std::endl <<vol << std::endl;

  // delete[] in0.vertices;
  // delete[] in0.triangles;
  // delete[] in1.vertices;
  // delete[] in1.triangles;
  // delete[] intersection.vertices;
  // delete[] intersection.triangles;
  // delete[] difference.vertices;
  // delete[] difference.triangles;
  // delete[] intersection_and_difference.vertices;
  // delete[] intersection_and_difference.triangles;
  return 0;
}


