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
#ifndef __vt100_h__
#define __vt100_h__

#include <stdio.h>

void vt100_cursor_home( void );
void vt100_cursor_set(int row, int column);
void vt100_cursor_up( void );
void vt100_cursor_down( void );
void vt100_cursor_fwd( void );
void vt100_cursor_back( void );
void vt100_cursor_save( void );
void vt100_cursor_load( void );
void vt100_erase_fwdeol( void );
void vt100_erase_bwdsol( void );
void vt100_erase_line( void );
void vt100_erase_down( void );
void vt100_erase_up( void );
void vt100_erase_screen( void );

#endif
