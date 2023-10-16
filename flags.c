#

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @m: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *m)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_m;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_m = *m + 1; format[curr_m] != '\0'; curr_m++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_m] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*m = curr_m - 1;

	return (flags);
}
