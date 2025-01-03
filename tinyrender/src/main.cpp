#include "model.h"
#include "tgaimage.h"
#include "utils.h"
#include <cmath>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
Model *model = NULL;
const int width = 2080;
const int height = 2080;

int main(int argc, char **argv) {
  if (2 == argc) {
    model = new Model(argv[1]);
  } else {
    model = new Model("obj/african_head.obj");
  }
  draw_model(model, width, height, white);
}
