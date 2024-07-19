#include <vector>
#include <algorithm>
/*
This is the function you need to implement. Quick reference:
- input rows: 0 <= y < ny
- input columns: 0 <= x < nx
- element at row y and column x is stored in in[x + y*nx]
- for each pixel (x, y), store the median of the pixels (a, b) which satisfy
  max(x-hx, 0) <= a < min(x+hx+1, nx), max(y-hy, 0) <= b < min(y+hy+1, ny)
  in out[x + y*nx].
*/
void mf(int ny, int nx, int hy, int hx, const float *in, float *out) {
  auto maximum_window_size = (hy * 2 + 1) * (hx * 2 + 1);
  std::vector<float> window;
  window.reserve(maximum_window_size);

  for (int y = 0; y < ny; ++y) {
    auto ibegin = std::max(0, y - hy); 
    auto ibound = std::min(y + hy + 1, ny);
    for (int x = 0; x < nx; ++x) {
      auto jbegin = std::max(0, x - hx);
      auto jbound = std::min(x + hx + 1, nx);
      window.clear();
      for (auto i = ibegin; i < ibound; ++i) {
        for (auto j = jbegin; j < jbound; ++j) {
          window.push_back(in[i*nx + j]);
        }
      }
     
      if (window.size() % 2 == 1) {
        auto median_position = begin(window) + window.size() / 2;
        std::nth_element(begin(window), median_position, end(window));
        out[y*nx + x] = *median_position;
      } else {
        auto median_position1 = begin(window) + window.size() / 2;
        auto median_position2 = begin(window) + window.size() / 2 - 1;
        std::nth_element(begin(window), median_position1, end(window));
        std::nth_element(begin(window), median_position2, end(window));
        out[y*nx + x] = (*median_position1 + *median_position2) / 2.0;
      }
    }
  }
}
