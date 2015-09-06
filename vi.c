#include <stdio.h>

char cmdmodebuf[200];

int main( int argc, char **argv, char **envp)
{
	tty_initialize();
	tty_command_mode( cmdmodebuf, 200 );
	tty_cleanup();
	fprintf(stderr, cmdmodebuf );
}
