#pragma once
#include "geometry.h"
#include "model.h"
#include "tgaimage.h"
/**
 * @brief Draw a line between two points.
 *
 * This function draws a line between two points using the Bresenham's line
 * algorithm. The line is drawn in the given image with the given color.
 *
 * @tparam T Type of the color of the image.
 * @param x0 X-coordinate of the first point.
 * @param y0 Y-coordinate of the first point.
 * @param x1 X-coordinate of the second point.
 * @param y1 Y-coordinate of the second point.
 * @param image Image where the line will be drawn.
 * @param color Color of the line.
 */
void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

void draw_model(Model *model, int width, int height, TGAColor color);
