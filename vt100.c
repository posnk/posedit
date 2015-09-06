/****************************************************************************
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License along
 with this program; if not, write to the Free Software Foundation, Inc.,
 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <stdio.h>

void vt100_cursor_home( void ) {
	printf( "\x1B[H" );
	fflush( stdout );
}

void vt100_cursor_set(int row, int column) {
	printf( "\x1B[%i;%iH", row, column );
	fflush( stdout );
}

void vt100_cursor_up( void ) {
	printf( "\x1B[A" );
	fflush( stdout );
}

void vt100_cursor_down( void ) {
	printf( "\x1B[B" );
	fflush( stdout );
}

void vt100_cursor_fwd( void ) {
	printf( "\x1B[C" );
	fflush( stdout );
}

void vt100_cursor_back( void ) {
	printf( "\x1B[D" );
	fflush( stdout );
}

void vt100_cursor_save( void ) {
	printf( "\x1B[s" );
	fflush( stdout );
}

void vt100_cursor_load( void ) {
	printf( "\x1B[u" );
	fflush( stdout );
}

void vt100_erase_fwdeol( void ) {
	printf( "\x1B[K" );
	fflush( stdout );
}

void vt100_erase_bwdsol( void ) {
	printf( "\x1B[1K" );
	fflush( stdout );
}

void vt100_erase_line( void ) {
	printf( "\x1B[2K" );
	fflush( stdout );
}	


void vt100_erase_down( void ) {
	printf( "\x1b[J" );
	fflush( stdout );
}

void vt100_erase_up( void ) {
	printf( "\x1b[1J" );
	fflush( stdout );
}

void vt100_erase_screen( void ) {
	printf( "\x1b[2J" );
	fflush( stdout );
}

