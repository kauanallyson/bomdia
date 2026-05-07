#include <stdio.h>
#include <string.h>
#ifndef MENU_H
#define MENU_H

void print_help();
void handle_args(int argc, char *argv[]);

#ifdef MENU_IMPLEMENTATION
void print_help() {
  printf("Uso: ./bomdia <OPÇÕES>\n"
         "Selecione o idioma à ser printado, use apenas 1 OPÇÃO:\n"
         "-1 , --pt : bomdia em portugês\n"
         "-2 , --en : bomdia em inglês\n"
         "-3 , --es : bomdia em espanhol\n"
         "-4 , --it : bomdia em italiano\n"
         "-5 , --fr : bomdia em francês\n"
         "-h, --help: Printa esse guia\n"
         "Criado por Kauan Allyson para a disciplina de Linguagem de "
         "Programação I na UVA\n");
};
void handle_args(int argc, char *argv[]) {
  if (argc != 2) {
    print_help();
    return;
  }

  char *flag = argv[1];
  if (strcmp(flag, "-1") == 0 || strcmp(flag, "--pt") == 0) {
    printf("Bom dia\n");
  } else if (strcmp(flag, "-2") == 0 || strcmp(flag, "--en") == 0) {
    printf("Good morning\n");
  } else if (strcmp(flag, "-3") == 0 || strcmp(flag, "--es") == 0) {
    printf("Buen dia\n");
  } else if (strcmp(flag, "-4") == 0 || strcmp(flag, "--it") == 0) {
    printf("Buongiorno\n");
  } else if (strcmp(flag, "-5") == 0 || strcmp(flag, "--fr") == 0) {
    printf("Bonjour\n");
  } else if (strcmp(flag, "-h") == 0 || strcmp(flag, "--help") == 0) {
    print_help();
  } else {
    print_help();
  }
}
#endif // MENU_IMPLEMENTATION

#endif // MENU_H
