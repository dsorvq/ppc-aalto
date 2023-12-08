#include <vector>
#include <algorithm>

struct Result {
  float avg[3];
};

/*
This is the function you need to implement. Quick reference:
- x coordinates: 0 <= x < nx
- y coordinates: 0 <= y < ny
- horizontal position: 0 <= x0 < x1 <= nx
- vertical position: 0 <= y0 < y1 <= ny
- color components: 0 <= c < 3
- input: data[c + 3 * x + 3 * nx * y]
- output: avg[c]
*/
Result calculate(int ny, int nx, const float *data, int y0, int x0, int y1, int x1) {
  double r = 0, g = 0, b = 0;
  for (int i = y0; i < y1; ++i) {
    for (int j = x0; j < x1; ++j) {
      int id = i * nx * 3 + j * 3;
      r += data[id + 0];
      g += data[id + 1];
      b += data[id + 2];
    }
  }
  
  int n = (y1 - y0) * (x1 - x0);
  return {static_cast<float>(r / n), static_cast<float>(g / n), static_cast<float>(b / n)};
}
