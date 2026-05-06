#define MENU_IMPLEMENTATION
#include "menu.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    print_help();
    return 0;
  }
  if (argc == 2) {
      handle_opcao(argv[1]);
  }
  if (argc > 2) {
    print_help();
    return 0;
  }

  return 0;
}
