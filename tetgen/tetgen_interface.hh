#ifndef TETGEN_INTERFACE_HH
#define TETGEN_INTERFACE_HH
#include "tetgen.h"
#include <array>
#include <vector>


using point_t = std::array<REAL, 3> ;
using face_t = std::array<uint, 3> ;

#include "tetgen.h" // Defined tetgenio, tetrahedralize().
// }
#include <iostream>
#include <string.h>

void make_faces_from_nodes(const std::vector<point_t> &precipitate_vertices,
                           std::vector<face_t> &facets);

#endif /* TETGEN_INTERFACE_HH */

