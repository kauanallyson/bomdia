#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  const char *short_flag;
  const char *long_flag;
  const char *saudacao;
} Lang;

const Lang langs[] = {
    {"-1", "--pt", "Bom Dia!"},         // Português
    {"-2", "--en", "Good Morning!"},    // Inglês
    {"-3", "--es", "Buen día!"},        // Espanhol
    {"-4", "--fr", "Bonjour!"},         // Francês
    {"-5", "--it", "Buongiorno!"},      // Italiano
    {"-6", "--co", "좋은 아침이에요!"}, // Coreano
    {"-7", "--ja", "おはよう!"},        // Japonês
    {"-8", "--ru", "Доброе утро!"}      // Russo
};

void print_help(void) {
  printf("Uso: ./bomdia <OPÇÃO>\n"
         "Selecione o idioma à ser printado, use apenas 1 OPÇÃO:\n"
         "-h,    --help: Printa esse guia\n"
         "-v, --version: Mostra a versão do programa\n"
         "-1,      --pt: Bomdia em português\n"
         "-2,      --en: Bomdia em inglês\n"
         "-3,      --es: Bomdia em espanhol\n"
         "-4,      --fr: Bomdia em francês\n"
         "-5,      --it: Bomdia em italiano\n"
         "-6,      --co: Bomdia em coreano\n"
         "-7,      --ja: Bomdia em japonês\n"
         "-8,      --ru: Bomdia em russo\n"
         "Criado por Kauan Allyson para a disciplina de Linguagem de "
         "Programação I na UVA\n");
}

void print_version(void) { printf("bomdia\nVersão: 1.0\n"); }

void handle_error(int argc) {
  if (argc == 1) {
    fprintf(stderr, "ERRO 01 - Nenhuma opção foi selecionada.\n"
                    "Selecione pelo menos uma opção.\n"
                    "-h ou --help para ver as opções disponíveis.\n");
    exit(1);
  }
  if (argc > 2) {
    fprintf(stderr, "ERRO 02 - Mais de uma opção foi selecionada.\n"
                    "Selecione apenas uma opção.\n"
                    "-h ou --help para ver as opções disponíveis.\n");
    exit(1);
  }
}

void handle_flag(char *argv[]) {
  const char *flag = argv[1];

  if (strcmp(flag, "-h") == 0 || strcmp(flag, "--help") == 0) {
    print_help();
    return;
  }

  if (strcmp(flag, "-v") == 0 || strcmp(flag, "--version") == 0) {
    print_version();
    return;
  }

  size_t langs_length = sizeof(langs) / sizeof(langs[0]);
  for (size_t i = 0; i < langs_length; i++) {
    if (strcmp(flag, langs[i].short_flag) == 0 ||
        strcmp(flag, langs[i].long_flag) == 0) {
      printf("%s\n", langs[i].saudacao);
      return;
    }
  }

  fprintf(stderr,
          "ERRO 03 - Opção desconhecida: %s\n"
          "-h ou --help para ver as opções disponíveis.\n",
          flag);
}
