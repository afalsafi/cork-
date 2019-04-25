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

// namespace corkpp {
int main(int argc, char * argv[]) {
  std::vector<corkpp::point_t> vertices0;
  corkpp::point_t origin0{0.0, 0.0, 0.0};
  corkpp::point_t size0{1.0, 1.0, 1.0};
  vertices0 = corkpp::cube_vertice_maker(origin0, size0);

  std::vector<corkpp::point_t> vertices1;
  corkpp::point_t origin1{0.5, 0.5, 0.5};
  corkpp::point_t size1{1.0, 1.5, 1.0};
  vertices1 = corkpp::cube_vertice_maker(origin1, size1);

  auto && vol_norm = corkpp::calculate_normal_volume(vertices0, vertices1);

  for (uint i = 0; i < vol_norm.size(); ++i) {
    std::cout << vol_norm[i] << std::endl;
  }

  return 0;
}
