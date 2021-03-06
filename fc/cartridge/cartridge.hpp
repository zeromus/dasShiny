#include "chip/chip.hpp"
#include "board/board.hpp"

struct Cartridge : Thread, property<Cartridge> {
  static void Main();
  void main();

  void load(const string &manifest);
  void unload();

  void power();
  void reset();

  readonly<bool> loaded;
  readonly<string> sha256;

  struct Information {
    string markup;
  } information;

  struct Memory {
    unsigned id;
    string name;
  };
  vector<Memory> memory;

  void serialize(serializer&);
  Cartridge();

//privileged:
  Board *board;

  uint8 prg_read(unsigned addr);
  void prg_write(unsigned addr, uint8 data);

  uint8 chr_read(unsigned addr);
  void chr_write(unsigned addr, uint8 data);

  //scanline() is for debugging purposes only:
  //boards must detect scanline edges on their own
  void scanline(unsigned y);
};

extern Cartridge cartridge;
