int	ft_iswhitespace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n'))
		return (1);
	return ((c == '\f') || (c == '\r') || (c == '\v'));
}
