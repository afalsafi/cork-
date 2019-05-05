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

#include "cork.hh"
#include "cork_interface.hh"

int main(int argc, char * argv[]) {

  std::vector<corkpp::point_t> vertices0;
  std::vector<corkpp::face_t> faces0;
  corkpp::point_t origin0{0.0, 0.0, 0.0};
  corkpp::point_t size0{1.0, 1.0, 1.0};
  vertices0 = corkpp::cube_vertice_maker(origin0, size0);
  corkpp::make_faces_from_nodes(vertices0, faces0);

  std::vector<corkpp::point_t> vertices1;
  // vertices1.push_back({0.00, 0.00, 0.00});
  // vertices1.push_back({0.00, 0.65, 0.00});
  // vertices1.push_back({0.50, 0.50, 0.00});
  // vertices1.push_back({0.65, 0.00, 0.00});
  // vertices1.push_back({0.00, 0.00, 1.00});
  // vertices1.push_back({0.00, 0.65, 1.00});
  // vertices1.push_back({0.50, 0.50, 1.00});
  // vertices1.push_back({0.65, 0.00, 1.00});



  vertices1.push_back({0.00, 0.00, 0.00});
  vertices1.push_back({0.75, 0.00, 0.00});
  vertices1.push_back({0.00, 0.75, 0.00});
  vertices1.push_back({0.00, 0.00, 0.75});
  vertices1.push_back({0.50, 0.50, 0.50});


  std::vector<corkpp::face_t> faces1;
  // corkpp::point_t origin1{0.5, 0.5, 0.5};
  // corkpp::point_t size1{1.0, 1.5, 1.0};
  // vertices1 = corkpp::cube_vertice_maker(origin1, size1);
  // vertices1.pop_back();
  corkpp::make_faces_from_nodes(vertices1, faces1);
  corkpp::CorkTriMesh in0;
  corkpp::CorkTriMesh in1;
  corkpp::CorkTriMesh intersection;
  corkpp::CorkTriMesh difference;
  corkpp::CorkTriMesh intersection_and_difference;
  corkpp::corktrimesh_maker_from_node_faces(vertices0, faces0, in0);
  corkpp::corktrimesh_maker_from_node_faces(vertices1, faces1, in1);

  corkpp::computeIntersection(in0, in1, intersection);
  corkpp::computeDifference(in0, in1, difference);
  corkpp::intersect_of_faces(intersection, difference,
                             intersection_and_difference);

  auto && vol = volume_calculator(intersection);
  auto && normal = average_normal_calculator(intersection_and_difference);
  std::cout << "the normal vector is:" << std::endl << normal << std::endl;
  std::cout << "the volume is:" << std::endl << vol << std::endl;

  return 0;
}


