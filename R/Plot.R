#' RunChaosGame
#'
#' This function allows you to plot some fractals using the chaos game method.
#' @param n_vertex Number of vertex for the polygon.
#' @param distance Distance between points.
#' @param iterations Number of iterations/points for the method.
#' @param rule An index for the rule to use.
#' @return A matrix of black/white pixels.
#' @export
#' @examples
#' pixel_matrix = ChaosGamePlot::RunChaosGame(5, .4, 100**3)
RunChaosGame = function(n_vertex, distance, iterations, rule = 0) {
  result = ChaosGame(n_vertex, distance, iterations, rule)
  par(mar=c(0, 0, 0, 0))
  image(result, useRaster=TRUE, axes=FALSE, col = c(0, 1))
  result
}
