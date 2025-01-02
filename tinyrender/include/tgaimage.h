#pragma once
#include <cstdint>
#include <fstream>
#include <vector>

#pragma pack(push, 1)
/**
 * @brief Structure representing the header of a TGA image file.
 *
 * This structure contains all the necessary fields to describe the header
 * of a TGA (Targa) image file. The fields are initialized to default values.
 */
struct TGAHeader {
  std::uint8_t idlength = 0;        /**< Length of the ID field */
  std::uint8_t colormaptype = 0;    /**< Type of the color map */
  std::uint8_t datatypecode = 0;    /**< Data type code */
  std::uint16_t colormaporigin = 0; /**< Color map origin */
  std::uint16_t colormaplength = 0; /**< Length of the color map */
  std::uint8_t colormapdepth = 0;   /**< Depth of the color map */
  std::uint16_t x_origin = 0;       /**< X-origin of the image */
  std::uint16_t y_origin = 0;       /**< Y-origin of the image */
  std::uint16_t width = 0;          /**< Width of the image */
  std::uint16_t height = 0;         /**< Height of the image */
  std::uint8_t bitsperpixel = 0;    /**< Bits per pixel */
  std::uint8_t imagedescriptor = 0; /**< Image descriptor */
};
#pragma pack(pop)

struct TGAColor {
  TGAColor() : bgra{0, 0, 0, 0} {}
  TGAColor(const std::uint8_t R, const std::uint8_t G, const std::uint8_t B,
           const std::uint8_t A)
      : bgra{B, G, R, A} {}

  std::uint8_t bgra[4] = {0, 0, 0, 0};
  std::uint8_t bytespp = 4;
  std::uint8_t &operator[](const int i) { return bgra[i]; }
};

struct TGAImage {
  enum Format { GRAYSCALE = 1, RGB = 3, RGBA = 4 };

  TGAImage() = default;
  TGAImage(const int w, const int h, const int bpp);
  bool read_tga_file(const std::string filename);
  bool write_tga_file(const std::string filename, const bool vflip = true,
                      const bool rle = true) const;
  void flip_horizontally();
  void flip_vertically();
  TGAColor get(const int x, const int y) const;
  void set(const int x, const int y, const TGAColor &c);
  int width() const;
  int height() const;

private:
  bool load_rle_data(std::ifstream &in);
  bool unload_rle_data(std::ofstream &out) const;

  int w = 0;
  int h = 0;
  std::uint8_t bpp = 0;
  std::vector<std::uint8_t> data = {};
};
