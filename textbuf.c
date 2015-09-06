#include "cllist.h"
#include "textbuf.h"
#include <stdlib.h>

cllist_t textbuf_head;
int	 textbuf_clean = 1;

displine_t	*displines;

void textbuf_new()
{

	if ( !textbuf_clean ) {
		tty_error("Buffer not clean, add ! to force action.");
		return;
	}
	
	cllist_create( &textbuf_head );

}

textline_t *textbuf_addline( textline_t *after )
{
	textline_t *line;
	line = malloc( sizeof (textline_t) );
	assert ( line != NULL );
	line->data = malloc ( sizeof( char ) * TEXTBUF_LINEBUFFER_LENGTH );
	line->size = TEXTBUF_LINEBUFFER_LENGTH;
	line->length = 0;
	assert ( line->data != NULL );
	line->link.prev = &after->link;
	line->link.next = after->link.next
	after->link.next = &line->link;
	link->link.next->prev = &line->link;
}

int textbuf_displayline( int start_row, int r_in_l, textline_t *line )
{
	char c;
	int pos, _row, _col, max_row, max_col;
	max_row = tty_get_height() - 1;
	max_col = tty_get_width(); 
	vt100_cursor_set( row, 1 );
	_row = _col = 0;

	for ( pos = 0; pos < line->length; pos++ ) {
		c = line->buffer[pos];
	
		if ( c <= ' ' || c > 0x7F )
			c = "?";//TODO: More useful repr.
		
		if ( _row >= r_in_l )
			tty_write_char( c );
	
		_col++;

		if ( _col == max_col ) {

			_col = 0;
			_row++;
			
			if ( _row + start_row >= max_row )
				return _row;

		}	
	}

	return _row + 1;;
}
