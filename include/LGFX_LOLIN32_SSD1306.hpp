#pragma once

#define LGFX_USE_V1

#include <LovyanGFX.hpp>

class LGFX : public lgfx::LGFX_Device
{
  lgfx::Panel_SSD1306 _panel_instance;

  lgfx::Bus_I2C _bus_instance;

  public:
    LGFX(void)
    {
    {
      auto cfg = _bus_instance.config();
      cfg.i2c_port         =      0;
      cfg.freq_write       = 400000;
      cfg.freq_read        = 400000;
      cfg.pin_sda          =      5;
      cfg.pin_scl          =      4;
      cfg.i2c_addr         =   0x3C;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs           =    -1;
      cfg.pin_rst          =    -1;
      cfg.pin_busy         =    -1;
      cfg.panel_width      =   128;
      cfg.panel_height     =    64;
      cfg.offset_x         =     0;
      cfg.offset_y         =     0;
      cfg.offset_rotation  =     0;
      cfg.dummy_read_pixel =     8;
      cfg.dummy_read_bits  =     1;
      cfg.readable         =  true;
      cfg.invert           = false;
      cfg.rgb_order        = false;
      cfg.dlen_16bit       = false;
      cfg.bus_shared       =  true;
      _panel_instance.config(cfg);
    }
    setPanel(&_panel_instance);
    }
};
