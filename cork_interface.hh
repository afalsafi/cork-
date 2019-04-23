#include "file_formats/files.h"
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
extern "C" {
#include "cork.h"
}
#include "tetgen/tetgen_interface.hh"

using face_t = std::array<uint, 3>;
using point_t = std::array<double, 3>;
using vector_t = Eigen::Vector3f;
using poly_t = Eigen::Matrix3Xf;
constexpr float tolerance = 1e-3;

// namespace muSpectre {
// namespace Cork {
/**
 * This functionmakes a corktirmesh list of nodes of a polyhedron
 */
void CorkTriMesh_maker(const std::vector<point_t> &precipitate_vertices,
                       const std::vector<face_t> &faces, CorkTriMesh *out);
/**
 * this function calulate the average noemal vector of triangle composing a
 * Corktrimesh
 */
vector_t average_normal_calculator(const CorkTriMesh &in);

/**
 * this function returns the normal vetor of a triangular facet
 * it should be noted that the order of the facet nodes has influence on
 * the sign of the normal vector
 */
vector_t face_normal_calculator(const std::vector<point_t> &vertices,
                                const face_t &face);

/**
 * this function returns the area of a triangular facet
 */
double face_area_calculator(const std::vector<point_t> &vertices,
                           const face_t &face);
/**
 * this function returns the distance of a plane and a point
 */
inline float point_plane_distance_calculator(const Eigen::Ref<vector_t> &point,
                                             const Eigen::Ref<vector_t> &normal,
                                             float constant) {
  return (normal.dot(point) + constant) / normal.norm();
}

/**
 * this function return the "d" constnat in the locus of a plane with the
 * equation "ax+by+cz+d = 0"
 */
auto face_constant_calculator(const std::vector<point_t> &vertices,
                              const face_t &face, vector_t normal) -> double;
/**
 * this function returns a point inside a convex polyhedron considering the
 * fact that any line connecting two points in a convex space lies inside the
 * space
 */
vector_t a_point_polyhedron_claculator(const std::vector<point_t> &vertices);
/**
 * this function returns the volume of a convex corktrimesh
 * the faces of the the corktrimesh sould be arranged such that their
 * right-hand normal vector point to the inside of the polyhedron
 */
double volume_calculator(const CorkTriMesh &in);
/**
 * these function create a "out" CorkTrimesh consists of the facets that belong
 * to "in0" and does not belong to "in1"
 */
void diff_of_faces(const CorkTriMesh &in0, const CorkTriMesh &in1,
                   CorkTriMesh *out);

/**
 * these function create a "out" CorkTrimesh consists of the facets that belong
 * to both "in0" and "in1"
 */
void intersect_of_faces(const CorkTriMesh &in0, const CorkTriMesh &in1,
                        CorkTriMesh *out);
/**
 * This function retruns a list of cube vertices given one of its corner's
 * coordinates and the vector connecting that to its farthest corner
 */
std::vector<point_t> cube_vertice_maker(point_t origin, point_t size);

/**
 * This function returns a corktrimesh given a set of points and correspondent
 * faces to them
 */
void corktrimesh_maker_from_node_faces(
    const std::vector<point_t> &precipitate_vertices,
    const std::vector<face_t> &faces, CorkTriMesh *out);
// } // namespace Cork

#endif /* CORK_INTERFACE_H */
