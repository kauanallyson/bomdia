#ifndef MENU_H
#define MENU_H

typedef struct {
  const char *short_flag;
  const char *long_flag;
  const char *bomdia;
} Lang;

void print_help();
void handle_args(int argc, char *argv[]);

#endif // MENU_H
