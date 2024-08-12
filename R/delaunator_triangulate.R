#' Delaunay triangulate with 'delaunator'
#'
#' Straightforward point-based triangulation.
#'
#' @param x x coord (or xy-coords)
#' @param y y coord (or NULL, default)
#'
#' @return matrix of triplet indices, one triangle per row
#' @export
#'
#' @importFrom grDevices xy.coords
#' @examples
#' idx <- delaunator_triangulate(xy <- cbind(1:100, rnorm(100)))
#' plot(xy, pch = "+", cex = 2, col = "firebrick")
#' polygon(xy[t(cbind(idx, NA)), ])
delaunator_triangulate <- function(x, y = NULL) {
  x <- xy.coords(x, y)
  index <- delaunator_triangulate_cpp(as.double(t(cbind(x$x, x$y))))
  matrix(index + 1L, ncol = 3L, byrow = TRUE)
}
