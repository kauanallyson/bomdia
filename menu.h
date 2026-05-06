#include <stdio.h>
#ifndef MENU_H
#define MENU_H

void print_help();
void handle_opcao(const char *opcao);

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
void handle_opcao(const char *opcao) {
  switch (opcao[1]) {
  case '1':
    printf("Bom dia\n");
    break;
  case '2':
    printf("Good morning\n");
    break;
  case '3':
    printf("Buen dia\n");
    break;
  case '4':
    printf("Buongiorno\n");
    break;
  case '5':
    printf("Bonjour\n");
    break;
  default:
    print_help();
  }
}
#endif // MENU_IMPLEMENTATION

#endif // MENU_H
