#include "menu.h"
#include <stdio.h>
#include <string.h>

const Lang langs[] = {
    {"-1", "--pt", "Bom dia"},      // Português
    {"-2", "--en", "Good morning"}, // Inglês
    {"-3", "--es", "Buen día"},     // Espanhol
    {"-4", "--it", "Buongiorno"},   // Italiano
    {"-5", "--fr", "Bonjour"},      // Francês
};

#define N_LANGS (sizeof(langs) / sizeof(langs[0]))

void print_help(void) {
  printf("Uso: ./bomdia <OPÇÃO>\n"
         "Selecione o idioma à ser printado, use apenas 1 OPÇÃO:\n"
         "-1,   --pt: bomdia em português\n"
         "-2,   --en: bomdia em inglês\n"
         "-3,   --es: bomdia em espanhol\n"
         "-4,   --it: bomdia em italiano\n"
         "-5,   --fr: bomdia em francês\n"
         "-h, --help: Printa esse guia\n"
         "Criado por Kauan Allyson para a disciplina de Linguagem de "
         "Programação I na UVA\n");
}

void handle_args(int argc, char *argv[]) {
  if (argc != 2) {
    print_help();
    return;
  }
  const char *flag = argv[1];

  if (strcmp(flag, "-h") == 0 || strcmp(flag, "--help") == 0) {
    print_help();
    return;
  }

  for (size_t i = 0; i < N_LANGS; i++) {
    if (strcmp(flag, langs[i].short_flag) == 0 ||
        strcmp(flag, langs[i].long_flag) == 0) {
      printf("%s\n", langs[i].bomdia);
      return;
    }
  }

  fprintf(stderr, "Opção desconhecida: %s\n\n", flag);
  print_help();
}
