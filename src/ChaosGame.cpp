#include <Rcpp.h>
#include <vector>
#include <math.h>

using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericMatrix ChaosGame(const int n_vertex, const double distance, const double iterations)
{
  Rcpp::NumericMatrix ret(600, 600);
  
  std::vector<int> points_x;
  std::vector<int> points_y;

  int actual_x = 0;
  int actual_y = 0;

  int start_x = 200;
  int start_y = 200;

  for (int i = 0; i < n_vertex; i++)
  {
    points_x.push_back((int) (280 + 275 * cos((i * 2 * M_PI / n_vertex) + n_vertex - (0.4))));
    points_y.push_back((int) (290 + 275 * sin((i * 2 * M_PI / n_vertex) + n_vertex - (0.4))));
    
    ret(points_x[i], points_y[i]) = 1;
  }

  points_x.push_back(280);
  points_y.push_back(290);

  for (int i = 0; i < iterations; i++)
  {
    int index = rand() % (n_vertex);

    actual_x = points_x[index];
    actual_y = points_y[index];

    int new_x = actual_x - (int) floor(((actual_x - start_x) * distance));
    int new_y = actual_y - (int) floor(((actual_y - start_y) * distance));
    
    ret(new_x, new_y) = 1;

    start_x = new_x;
    start_y = new_y;
  }

  return ret;
}
