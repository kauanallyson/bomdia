#include "menu.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    handle_error(argc);
  }
  handle_flag(argv);
  return 0;
}
