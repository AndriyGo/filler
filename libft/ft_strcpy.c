char	*ft_strcpy(char *dst, const char *src)
{
	char *ret;

	ret = dst;
	while (*src)
		*(dst++) = *(src++);
	*dst = *src;
	return (ret);
}
