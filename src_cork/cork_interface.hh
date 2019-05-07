/**
 * @file   cork_interface.hh
 *
 * @author Ali Falsafi <ali.falsafi@epfl.ch>
 *
 * @date   23 Apr 2019
 *
 * @brief This interface is used to interact with cork package for calculating
 * intesecting voulme and normal vector of the corrspondent interface
 *
 * Copyright © 2017 Till Junge
 *
 * µSpectre is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3, or (at
 * your option) any later version.
 *
 * µSpectre is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <sstream>
using std::ostream;
using std::string;
using std::stringstream;

#ifndef CORK_INTERFACE_HH
#define CORK_INTERFACE_HH
#include "cork.hh"
#include "tetgen/tetgen_interface.hh"

namespace corkpp {
  using face_t = std::array<uint, 3>;
  using point_t = std::array<double, 3>;
  using vector_t = Eigen::Vector3f;
  using poly_t = Eigen::Matrix3Xf;
  constexpr float tolerance = 1e-4;

  /**
   * This function recieves to set of vertices "vertices_pre" &
   * "vertices_precipitate" and it does:
   * 1. it computes its triangulized facets
   * 2. by passing triangulated facets and vertice coordinates it will
   * 2a. calculate their intersection volume
   * 2b. calculate the average normal vector of the facets of
   * "vertices_precipitate" that lie inside "vertices_pixel"
   */

  auto calculate_intersection_volume_normal(
      const std::vector<point_t> vertices_precipitate,
      const std::vector<point_t> vertices_pixel)
      ->  std::array<REAL, 4>;

  auto
  calculate_intersection_normal(const std::vector<point_t> vertices_precipitate,
                                const std::vector<point_t> vertices_pixel)
      -> std::array<REAL, 3>;
  /**
   * This function recieves to set of vertices "vertices_pre" &
   * "vertices_precipitate" and it does:
   * 1. it computes its triangulized facets
   * 2. by passing triangulated facets and vertice coordinates it will
   * 2a. calculate their intersection volume
   * "vertices_precipitate" that lie inside "vertices_pixel"
   */

  auto
  calculate_intersection_volume(const std::vector<point_t> vertices_precipitate,
                                const std::vector<point_t> vertices_pixel)
      -> REAL;

  /**
   * This function makes a corktirmesh list of nodes of a polyhedron
   */
  void CorkTriMesh_maker(const std::vector<point_t> & precipitate_vertices,
                         const std::vector<face_t> & faces, CorkTriMesh * out);
  /**
   * this function calulate the average noemal vector of triangle composing a
   * Corktrimesh
   */
  vector_t average_normal_calculator(const CorkTriMesh & in);

  /**
   * this function returns the normal vetor of a triangular facet
   * it should be noted that the order of the facet nodes has influence on
   * the sign of the normal vector. If the triangle sets passed to this
   * function are output of tetgen package we know that the order of the
   * vertices indeices will make the calculated normal vector pointing outward
   */
  vector_t face_normal_calculator(const std::vector<point_t> & vertices,
                                  const face_t & face);

  /**
   * this function returns the area of a triangular facet
   */
  double face_area_calculator(const std::vector<point_t> & vertices,
                              const face_t & face);
  /**
   * this function returns the distance of a plane and a point
   */
  inline float
  point_plane_distance_calculator(const Eigen::Ref<vector_t> & point,
                                  const Eigen::Ref<vector_t> & normal,
                                  float constant) {
    return (normal.dot(point) + constant) / normal.norm();
  }

  /**
   * this function return the "d" constnat in the locus of a plane with the
   * equation "ax+by+cz+d = 0"
   */
  auto face_constant_calculator(const std::vector<point_t> & vertices,
                                const face_t & face, vector_t normal) -> double;
  /**
   * this function returns a point inside a convex polyhedron considering the
   * fact that any line connecting two points in a convex space lies inside
   * the space
   */
  vector_t a_point_polyhedron_claculator(const std::vector<point_t> & vertices);
  /**
   * this function returns the volume of a convex corktrimesh
   * the faces of the the corktrimesh sould be arranged such that their
   * right-hand normal vector point to the inside of the polyhedron
   */
  double volume_calculator(CorkTriMesh & in);
  /**
   * these function create a "out" CorkTrimesh consists of the facets that
   * belong to "in0" and does not belong to "in1"
   */
  void diff_of_faces(const CorkTriMesh & in0, const CorkTriMesh & in1,
                     CorkTriMesh & out, REAL pixel_size = 1);

  /**
   * these function create a "out" CorkTrimesh consists of the facets that
   * belong to both "in0" and "in1"
   */
  void intersect_of_faces(const CorkTriMesh & in_diff,
                          const CorkTriMesh & in_intersect, CorkTriMesh & out,
                          REAL pixel_size = 1.0);
  /**
   * This function retruns a list of cube vertices given one of its corner's
   * coordinates and the vector connecting that to its farthest corner
   */
  std::vector<point_t> cube_vertice_maker(point_t origin, point_t size);

  /**
   * This function returns a corktrimesh given a set of points and
   * correspondent faces to them
   */
  void corktrimesh_maker_from_node_faces(
      const std::vector<point_t> & precipitate_vertices,
      const std::vector<face_t> & faces, CorkTriMesh & out);
}  // namespace corkpp

#endif /* CORK_INTERFACE_H */
// }  // namespace corkpp
