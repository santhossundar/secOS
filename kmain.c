#include "framebuffer.c"
#include "serialport.c"

void kmain(){

       	char buffer[] = "Hello! It works ...";
       	write(buffer,sizeof(buffer));

	serial_configure(SERIAL_COM1_BASE, Baud_115200);
  	serial_write(SERIAL_COM1_BASE, buffer, sizeof(buffer));
  	
}