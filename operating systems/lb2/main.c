
const char *cadena = "Bienvenido al GOS";

void cls()
{
	unsigned char *vidmem = (unsigned char *)0xB8000;
  	const long size = 80*25;
	long loop;

   	for (loop=0; loop<size; loop++) 
   	{
      		*vidmem++ = 0;
      		*vidmem++ = 0xA;
   	}
} 

void print(const char *_message)
{
/*
	Aqui debe resolver el inciso 3) de su laboratorio.
	Implemente esta función, de manera tal que pueda imprimir
	el contenido de la cadena de caracteres apuntada por 
	el puntero _message.
	
*/
   volatile char *video = (volatile char*)0xB8000;
    while( *_message != 0 )
    {
        *video++ = *_message++;
        *video++ = 0xff;
    }
}

int nombre()
{
  //cls();
  print(cadena);
  return 0;
}


