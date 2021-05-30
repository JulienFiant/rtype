//
// EPITECH PROJECT, 2018
// PixelBuffer_H
// File description:
// pixel buffer for SFML header
//

#ifndef PIXELBUFFER_HPP_
#define PIXELBUFFER_HPP_

#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>
#include "../Color/Color.hpp"

class PixelBuffer
{
public:
  PixelBuffer(unsigned int width, unsigned int height);
  ~PixelBuffer();
  void reset(Color = Color(0, 0, 0, char(0)));
  void setBuffer(sf::Uint8 = 0);
  void setPixelAt(Color color, unsigned int pos);
  void setPixelAt(Color color, int x, int y);
  template <typename T>
  void setPixelAt(Color color, sf::Vector2<T> coordinates);
  unsigned int getWidth(void);
  unsigned int getHeight(void);
  sf::Vector2u getSize(void);
  sf::Uint8 *getBuffer(void);
  Color getPixelAt(unsigned int pos);
  Color getPixelAt(unsigned int x, unsigned int y);
  template <typename T>
  Color getPixelAt(sf::Vector2<T> coordinates);
//  PixelBuffer* copy(void);

private:
  unsigned int _W;
  unsigned int _H;
  sf::Uint8 *_buffer;
};

#endif /* PixelBuffer_HPP_ */
