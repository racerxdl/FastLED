/*
 * Integration into FastLED ClocklessController
 * Copyright (c) 2018 Samuel Z. Guyer
 * Copyright (c) 2017 Thomas Basler
 * Copyright (c) 2017 Martin F. Falatic
 * Copyright (c) 2020 Lucas Teske
 *
 * Emulator support
 */
/*
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include <iostream>

FASTLED_NAMESPACE_BEGIN

#define FASTLED_HAS_CLOCKLESS 1

template <int DATA_PIN, int T1, int T2, int T3, EOrder RGB_ORDER = RGB, int XTRA0 = 0, bool FLIP = false, int WAIT_TIME = 50>
class ClocklessController : public CPixelLEDController<RGB_ORDER> {

public:

protected:
  virtual void showPixels(PixelController<RGB_ORDER> & pixels) {
    while(pixels.has(1)) {
      uint32_t r = (uint32_t)pixels.loadAndScale0();
      uint32_t g = (uint32_t)pixels.loadAndScale1();
      uint32_t b = (uint32_t)pixels.loadAndScale2();
      uint32_t rgb = (r << 16) + (g << 8) + b;
      extputpixel(rgb);
      pixels.advanceData();
      pixels.stepDithering();
    }
    extendpanelupdate();
  }

  virtual void init() {
    std::cout << "INIT" << std::endl;
  }
};

FASTLED_NAMESPACE_END
