#pragma once

#include <LiquidCrystal.h>

// https://anotherproducer.com/online-tools-for-musicians/bpm-calculator/

class Dialog {
private:
  LiquidCrystal &m_screen;
  const int M_WIDTH;
  const int M_HEIGHT;
  int m_cadence;
  int m_flipdelay;
  int m_outdelay;

public:
  Dialog() = delete;

  Dialog(LiquidCrystal &screen, int width, int height);

  Dialog(LiquidCrystal &screen, int width, int height, int typingCadence,
         int pagingDelay);

  Dialog(LiquidCrystal &screen, int width, int height, int typingCadence,
         int pagingDelay, int endingDelay);

  // default destructor

  void write(char message[]) {
    const int SCR_SIZE = M_WIDTH * M_HEIGHT;
    // const int MSG_SIZE = sizeof(message) / sizeof(message[0]) - 1;
    int iMsg, iScr, x, y, page, prevPage;
    prevPage = 0;
    for (iMsg = 0; message[iMsg] != 0; ++iMsg) {
      iScr = iMsg % SCR_SIZE;
      x = iScr % M_WIDTH;
      y = iScr / M_WIDTH;
      page = iMsg / SCR_SIZE;
      if (message[iMsg] == 0x20) {
        continue;
      }
      if (page == prevPage) {
        delay(m_cadence);
      } else {
        delay(m_flipdelay);
        m_screen.clear();
      }
      m_screen.setCursor(x, y);
      m_screen.write(message[iMsg]);
      prevPage = page;
    }
    delay(m_outdelay);
    m_screen.clear();
  }
};

inline Dialog::Dialog(LiquidCrystal &screen, int width, int height)
    : m_screen(screen), M_WIDTH(width), M_HEIGHT(height), m_cadence(60),
      m_flipdelay(2000), m_outdelay(2000) {}

Dialog::Dialog(LiquidCrystal &screen, int width, int height, int typingCadence,
               int pagingDelay)
    : m_screen(screen), M_WIDTH(width), M_HEIGHT(height),
      m_cadence(typingCadence), m_flipdelay(pagingDelay),
      m_outdelay(pagingDelay) {}

Dialog::Dialog(LiquidCrystal &screen, int width, int height, int typingCadence,
               int pagingDelay, int endingDelay)
    : m_screen(screen), M_WIDTH(width), M_HEIGHT(height),
      m_cadence(typingCadence), m_flipdelay(pagingDelay),
      m_outdelay(endingDelay) {}
