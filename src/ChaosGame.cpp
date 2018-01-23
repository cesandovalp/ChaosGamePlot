#include <Rcpp.h>
#include <vector>
#include <math.h>

using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericMatrix ChaosGame(const int n_vertex, const double distance, const double iterations, const int rule = 0)
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

  std::vector<int> index;
  index.resize(iterations + 2);
  index[0] = 0;
  index[1] = 1;

  for (int i = 0; i < iterations; i++)
  {
    if(rule == 0)
      index[i + 2] = (rand() % (n_vertex));
    else if(rule == 1)
    {
      int temp = rand() % (n_vertex);
      while(((temp - 2) % n_vertex) == index[i + 1])
        temp = rand() % (n_vertex);
      index[i + 2] = temp;
    }
    else if(rule == 2)
    {
      int temp = rand() % (n_vertex);
      while((temp - 1) % n_vertex == index[i] || (temp - 3) % n_vertex == index[i + 1])
        temp = rand() % (n_vertex);
      index[i + 2] = temp;
    }
    else if(rule == 3)
    {
      int temp = rand() % (n_vertex);
      while(temp == index[i + 1])
        temp = rand() % (n_vertex);
      index[i + 2] = temp;
    }
    else if(rule == 4)
    {
      int temp = rand() % (n_vertex);
      while((temp - 1) % n_vertex == index[i] || (temp - 4) % n_vertex == index[i + 1])
        temp = rand() % (n_vertex);
      index[i + 2] = temp;
    }

    actual_x = points_x[index[i + 2]];
    actual_y = points_y[index[i + 2]];

    int new_x = actual_x - (int) floor(((actual_x - start_x) * distance));
    int new_y = actual_y - (int) floor(((actual_y - start_y) * distance));
    
    ret(new_x, new_y) = 1;

    start_x = new_x;
    start_y = new_y;
  }

  return ret;
}
