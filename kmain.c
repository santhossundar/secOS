#include "framebuffer.c"

#define FB_GREEN     2
#define FB_DARK_GREY 8

void kmain(){

	fb_write_cell(0, 'A', FB_GREEN, FB_DARK_GREY);
  	
}