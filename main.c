#include "shell.h"

/**
 * main - defines entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success else 1 for error
 */
int main(int argc, char **argv)
{
	info_t info[] = { INFO_INIT };
	int f_data = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (f_data)
		: "r" (f_data));

	if (argc == 2)
	{
		f_data = open(argv[1], O_RDONLY);
		if (f_data == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can't open ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = f_data;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
}
