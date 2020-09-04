#include <sys/utsname.h>
#include <stdio.h>

int main() {

  struct utsname dadosSistema;
  uname(&dadosSistema);


  printf("%s\n", dadosSistema.sysname);
  printf("%s\n", dadosSistema.version);
  printf("%s\n", dadosSistema.machine);
  printf("%s\n", dadosSistema.nodename);
  printf("%s\n", dadosSistema.release);
  

  return 0;
}
