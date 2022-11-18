/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
	{
		str[s1_len] = s2[i];
		s1_len++;
	}
	str[s1_len] = '\0';
	return (str);
}
*/

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!s || start < 0)
		return (NULL);
	str_len = ft_strlen(s);
	if ((size_t)start >= str_len)
		return (ft_strdup(""));
	if (len > str_len)
		str = (char *)malloc((str_len - start + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
*/
