int is_digit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int is_sign(char c)
{
	return (c == '-' || c == '+');
}

int is_whitespace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

// this atoi is rewritten to behave accordingly to my needs:
// return int if format of string is correct; otherwise return 0
int ft_atoi(const char *s)
{
	if (!s)
		return 0;
	unsigned int i = 0;
	unsigned int sign = 0;
	int ret = 0;
	while (is_whitespace(s[i]) == 1)
		i++;
	if (is_sign(s[i]) == 1)
	{
		sign = s[i] == '-' ? 1 : 0;
		i++;
	}
	while (s[i] != '\0')
	{
		if (is_digit(s[i]) == 0)
			return 0;
		ret = ret * 10;
		ret = ret + s[i] - '0';
		i++;
	}
	if (sign)
		return -ret;
	return ret;
}

int is_zero(const char *s)
{
	if (!s)
		return 0;
	unsigned int i = 0;
	while (is_whitespace(s[i]) == 1)
		i++;
	if (is_sign(s[i]) == 1)
		i++;
	if (s[i] == '0' && s[i+1] == '\0')
		return 1;
	return 0;
}

int validate_args(int argc, char **argv)
{
	if (argc < 2)
	{
		return 1;
	}
	int i = 1;
	while (i < argc)
	{
		if (is_zero(argv[i]) == 0)
		{
			if (ft_atoi(argv[i]) == 0)
			{
				return 2;
			}
		}
		int j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				return 3;
			}
			j++;
		}
		i++;
	}
	return 0;
}
