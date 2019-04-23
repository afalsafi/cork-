#include "tetgen_interface.hh"


void make_faces_from_nodes(const std::vector<point_t> &precipitate_vertices,
                           std::vector<face_t> &facets) {
  tetgenio in, out;
  in.firstnumber = 0;
  in.numberofpoints = precipitate_vertices.size();
  in.pointlist.resize(in.numberofpoints * 3);
  for (int i = 0; i < in.numberofpoints; ++i) {
    in.pointlist[3 * i] = precipitate_vertices[i][0];
    in.pointlist[3 * i + 1] = precipitate_vertices[i][1];
    in.pointlist[3 * i + 2] = precipitate_vertices[i][2];
  }
  // std::array<int, 3> tmp_facet;
  tetrahedralize((char *)"Q", &in, &out);

  for (int i = 0; i < out.numberoftrifaces; ++i) {
    //   tmp_facet[0] = out.trifacelist[i * 3];
    //   tmp_facet[1] = out.trifacelist[i * 3 + 1];
    //   tmp_facet[2] = out.trifacelist[i * 3 + 2];
    //   facets.push_back(tmp_facet);

    facets.push_back({(uint)out.trifacelist[i * 3],
                      (uint)out.trifacelist[i * 3 + 1],
                      (uint)out.trifacelist[i * 3 + 2]});

  }
  
}
