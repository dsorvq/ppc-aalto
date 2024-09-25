#include <cmath>
/*
This is the function you need to implement. Quick reference:
- input rows: 0 <= y < ny
- input columns: 0 <= x < nx
- element at row y and column x is stored in data[x + y*nx]
- correlation between rows i and row j has to be stored in result[i + j*ny]
- only parts with 0 <= j <= i < ny need to be filled
*/
void correlate(int ny, int nx, const float *data, float *result) {
    double* mean = new double[ny];
    for (int i = 0; i < ny; ++i) {
        double sum = 0.0;
        for (int j = 0; j < nx; ++j) {
            sum += data[i * nx + j];
        }
        mean[i] = sum / nx;
    }

    for (int i = 0; i < ny; ++i) {
        for (int j = 0; j <= i; ++j) {
            double mean_i = mean[i], mean_j = mean[j];

            double covariance = 0.0, variance_i = 0.0, variance_j = 0.0;
            for (int k = 0; k < nx; ++k) {
                double diff_i = data[i * nx + k] - mean_i;
                double diff_j = data[j * nx + k] - mean_j;
                covariance += diff_i * diff_j;
                variance_i += diff_i * diff_i;
                variance_j += diff_j * diff_j;
            }

            double pcc = covariance / (std::sqrt(variance_i) * std::sqrt(variance_j));

            result[i + j * ny] = pcc;
        }
    }

    delete[] mean;
}
