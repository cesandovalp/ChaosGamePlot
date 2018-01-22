#' RunChaosGame
#'
#' This function allows you to plot some fractals using the chaos game method.
#' @param n_vertex The number of vertex for the polygon.
#' @param distance The distance between points.
#' @param iterations The number of iterations/points for the method.
#' @return A matrix of black/white pixels.
#' @export
#' @examples
#' pixel_matrix = ChaosGamePlot::RunChaosGame(5, .4, 100**3)
RunChaosGame = function(n_vertex, distance, iterations) {
  result = ChaosGame(n_vertex, distance, iterations)
  par(mar=c(0, 0, 0, 0))
  image(result, useRaster=TRUE, axes=FALSE, col = c(0, 1))
  result
}
