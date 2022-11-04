#include "io.h"

#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

#define FB_GREEN     2
#define FB_DARK_GREY 8
#define BLUE       1
#define LIGHT_GREY 7

void fb_move_cursor(unsigned short pos){
        outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
        outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
        outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
        outb(FB_DATA_PORT,    pos & 0x00FF);
}

static char *fb = (char *) 0x000B8000;

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg) {
	fb[i] = c;
	fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

int write(char *buf, unsigned int len){
    	unsigned int i;
    	for(i = 0; i<len; i++){
    		fb_write_cell(i*2, *(buf+i), LIGHT_GREY, BLUE);
    		fb_move_cursor(2);
    	}
    	return i;
}