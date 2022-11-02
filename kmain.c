#include "framebuffer.c"
#include "io.h"

#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

#define FB_GREEN     2
#define FB_DARK_GREY 8

void fb_move_cursor(unsigned short pos){
        outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
        outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
        outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
        outb(FB_DATA_PORT,    pos & 0x00FF);
}

void kmain(){

	fb_write_cell(0, 'A', FB_GREEN, FB_DARK_GREY);
	fb_move_cursor(2);
  	
}