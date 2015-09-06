#ifndef textbufh
#define textbufh

#include "cllist.h"
#define TEXTBUF_LINEBUFFER_LENGTH (200)

typedef struct {
	cllist_t link;
	int	 length;
	int	 size;
	char	*data;
} textline_t;

typedef struct {
	textline_t *text;
	int	 start_row;
	int	 start_pos;
} displine_t;

#endif
