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
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include "vt100.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
struct termios tty_cmd_termios;
struct winsize tty_winsize;
void tty_initialize()
{
	int fd = fileno(stdin);
	struct termios options;
	if (tcgetattr(fd, &options) == -1){
		fprintf(stderr, "Could not terminal options: %s\n", strerror( errno ));
		exit (EXIT_FAILURE);
	}
	tty_cmd_termios = options;	
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG | ICANON);
	options.c_cc[VMIN] = 1;
	options.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSANOW, &options) == -1){
		fprintf( stderr, "Could not set attributes for terminal: %s!\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	vt100_erase_screen();
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &tty_winsize);
}



void tty_cleanup()
{
        int fd = fileno(stdin);
        if (tcsetattr(fd, TCSANOW, &tty_cmd_termios) == -1){
                fprintf( stderr, "Could not restore attributes for terminal: %s!\n", strerror(errno));
                exit(EXIT_FAILURE);
        }
}

int   tty_get_width( void )
{
	return tty_winsize.ws_col;
}

int   tty_get_height( void )
{
	return tty_winsize.ws_row;
}

char tty_read_input( void )
{
	return getc(stdin);
}

void tty_write_char( char c )
{
	putchar( c );
	fflush(stdout);	
}

void tty_erase_char ( void )
{
	printf("\b \b");
	fflush(stdout);
}

void tty_error ( const char *error )
{
	vt100_cursor_save();
	vt100_cursor_set( tty_winsize.ws_row, 1 );
	vt100_erase_line();
	printf( "%s", error );
	fflush( stdout );
	vt100_cursor_load();
}

void tty_command_mode( char *buffer, size_t maxbuf)
{
	char c;
	int wid;
	int bufptr = 0;
	vt100_cursor_save ();
	vt100_cursor_set( tty_winsize.ws_row, 1 );
	vt100_erase_line();
	tty_write_char(':');
	wid = tty_winsize.ws_col - 1;
	maxbuf--;
	if ( maxbuf < wid )
		wid = maxbuf;
	while ( ( c = tty_read_input() ) != '\r' ) {
		if ( c >= ' ' && c < 0x7F ) {
			if ( bufptr == wid ) {
				tty_write_char( '\a' );
			} else {
				buffer[bufptr++] = c;
				tty_write_char( c );
			}
			
		} else if ( c == '\b' || c == 0x7F ) {
			if ( bufptr == 0 ) {
				tty_write_char( '\a' );
			} else {
				tty_erase_char();
				bufptr--;
			}
		} else if ( c == '\r' || c == '\n' ) {
			break;
		}
	} 
	buffer[bufptr] = 0;
	vt100_cursor_set( tty_winsize.ws_row, 1 );
	vt100_erase_line();
	vt100_cursor_load();
}
