/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:10:23 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 17:58:47 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif /* BUFFER_SIZE */

# ifndef FD_LIMIT
#  define FD_LIMIT 256
# endif /* FD_LIMIT */

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_conversion
{
	char			*flags;
	unsigned int	length;
	int				precision;
}	t_conversion;

/**
 * @brief Allocate memories and initialize to 0 the memory area.
 * @param num The number of elements.
 * @param size The size of each element.
 * @return The pointer to the memory area.
 * @note This function is equivalent to malloc(num * size) 
 * and then memset(ptr, 0, num * size).
*/
void			*ft_calloc(size_t num, size_t size);

/**
 * @brief Set the first n bytes of the memory area 
 * pointed by s to the value of c.
 * @param s The pointer to the memory area.
 * @param c The value to be set.
 * @param n The number of bytes to be set.
 * @return The pointer to the memory area.
*/
void			*ft_memset(void *s, int c, size_t n);

/**
 * @brief Set the first n bytes of the memory area pointed by s to 0.
 * @param s The pointer to the memory area.
 * @param n The number of bytes to be set.
 * @return The pointer to the memory area.
 * @note This function is equivalent to ft_memset(s, 0, n).
*/
void			ft_bzero(void *s, size_t n);

/**
 * @brief Copy n bytes from the memory area 
 * pointed by src to the memory area pointed by dest.
 * @param dest The pointer to the destination memory area.
 * @param src The pointer to the source memory area.
 * @param n The number of bytes to be copied.
 * @return The pointer to the destination memory area.
 * @note The memory areas must not overlap.
*/
void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copy n bytes from the memory area 
 * pointed by src to the memory area pointed by dest in reverse order.
 * @param dest The pointer to the destination memory area.
 * @param src The pointer to the source memory area.
 * @param n The number of bytes to be copied.
 * @return The pointer to the destination memory area.
*/
void			*ft_memrcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copy n bytes from the memory area 
 * pointed by src to the memory area pointed by dest until char c is found.
 * @param dest The pointer to the destination memory area.
 * @param src The pointer to the source memory area.
 * @param c The char to be found.
 * @param n The number of bytes to be copied.
 * @return The pointer to the byte after the char c 
 * in the destination memory area.
*/
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

/**
 * @brief Move n bytes from the memory area 
 * pointed by src to the memory area pointed by dest.
 * @param dest The pointer to the destination memory area.
 * @param src The pointer to the source memory area.
 * @param n The number of bytes to be moved.
 * @return The pointer to the destination memory area.
 * @note The memory areas may overlap.
*/
void			*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Locate the first occurrence of c in the memory area pointed by s.
 * @param s The pointer to the memory area.
 * @param c The char to be found.
 * @param n The number of bytes to be searched.
 * @return The pointer to the byte found or NULL if the char is not found.
*/
void			*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compare the first n bytes of the memory areas pointed by s1 and s2.
 * @param s1 The pointer to the first memory area.
 * @param s2 The pointer to the second memory area.
 * @param n The number of bytes to be compared.
 * @return An integer less than, equal to, or greater than 0 
 * if the first n bytes of s1 is found, respectively, 
 * to be less than, to match, or be greater than the first n bytes of s2.
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Get the length of the string.
 * @param s The pointer to the string.
 * @return The length of the string.
 * @note The length of a C string is determined 
 * by the terminating null-character: 
 * A C string is as long as the number of characters between the beginning 
 * the string and the terminating null character 
 * (without including the terminating null character itself).
*/
size_t			ft_strlen(const char *s);

/**
 * @brief Allocate memory for a copy of the string and copy the string.
 * @param s The pointer to the string.
 * @return The pointer to the copy of the string.
 * @note The copy is made in a way that ensures that if the function 
 * allocating memory fails, the original string is unchanged.
*/
char			*ft_strdup(const char *s);

/**
 * @brief Copy the string pointed by src to the buffer pointed by dest.
 * @param dest The pointer to the destination buffer.
 * @param src The pointer to the source string.
 * @return The pointer to the destination buffer.
 * @note The strings may not overlap.
 * @note The copy is made ensuring that the destination buffer 
 * is always null-terminated.
*/
int				ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Append the string pointed by src 
 * to the end of the string pointed by dest.
 * @param dest The pointer to the destination string.
 * @param src The pointer to the source string.
 * @return The length of the string that would have been created if 
 * enough space had been available in case of success, 
 * otherwise the length of dest.
 * @note The strings may not overlap.
 * @note The copy is made ensuring that the destination 
 * string is always null-terminated.
 * @note If size is less than or equal to the length of dest, 
 * the string pointed by dest will not be changed.
*/
int				ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Locate the first occurrence of the character c 
 * in the string pointed by s.
 * @param s The pointer to the string.
 * @param c The char to be found.
 * @return The pointer to the byte found or NULL 
 * if the char is not found.
*/
char			*ft_strchr(const char *s, int c);

/**
 * @brief Locate the first occurrence of the character c
 * in the string pointed by and return his index.
 * @param s The pointer to the string.
 * @param c The char to be found.
 * @return The index to the character found or -1
 * if the char is not found.
*/
int				ft_strchr_i(const char *s, int c);

/**
 * @brief Locate the last occurrence of the character c 
 * in the string pointed by s.
 * @param s The pointer to the string.
 * @param c The char to be found.
 * @return The pointer to the byte found or 
 * NULL if the char is not found.
*/
char			*ft_strrchr(const char *s, int c);

char			*ft_strnchr(const char *s, int c, int n);
char			*ft_strdelchr(char *s, int c);

/**
 * @brief Locate the first occurrence of the string needle 
 * in the string haystack before the first n bytes.
 * @param str The pointer to the string haystack.
 * @param substr The pointer to the string needle.
 * @param n The number of characters to be searched.
 * @return The pointer to the byte found or NULL 
 * if the string is not found.
 * @note If needle is an empty string, haystack is returned.
*/
char			*ft_strnstr(const char *str, const char *substr, size_t n);

/**
 * @brief Compare the two strings s1 and s2 
 * up to n bytes.
 * @param s1 The pointer to the first string.
 * @param s2 The pointer to the second string.
 * @param n The number of bytes to be compared.
 * @return An integer less than, equal to, or greater than 0 
 * if s1 is found, respectively, to be less than, to match, 
 * or be greater than s2.
*/
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Check if the char c is an ascii character.
 * @param c The char to be checked.
 * @return 1 if the char is an ascii character, otherwise 0.
 * @note An ascii character is any char between 0 and 127 inclusive.
*/
int				ft_isascii(int c);

/**
 * @brief Check if the char c is a printable character.
 * @param c The char to be checked.
 * @return 1 if the char is a printable character, otherwise 0.
 * @note A printable character is any char between 32 and 126 inclusive.
*/
int				ft_isprint(int c);

/**
 * @brief Check if the char c is a lowercase letter.
 * @param c The char to be checked.
 * @return 1 if the char is a lowercase letter, otherwise 0.
 * @note A lowercase letter is any char between 97 and 122 inclusive.
*/
int				ft_islower(int c);

/**
 * @brief Check if the char c is an uppercase letter.
 * @param c The char to be checked.
 * @return 1 if the char is an uppercase letter, otherwise 0.
 * @note An uppercase letter is any char between 65 and 90 inclusive.
*/
int				ft_isupper(int c);

/**
 * @brief Check if the char c is a letter.
 * @param c The char to be checked.
 * @return 1 if the char is a letter, otherwise 0.
 * @note A letter is any char between 65 and 90 
 * inclusive or between 97 and 122 inclusive.
*/
int				ft_isalpha(int c);

/**
 * @brief Check if the char c is a digit.
 * @param c The char to be checked.
 * @return 1 if the char is a digit, otherwise 0.
 * @note A digit is any char between 48 and 57 inclusive.
*/
int				ft_isdigit(int c);

/**
 * @brief Check if the char c is a letter or a digit.
 * @param c The char to be checked.
 * @return 1 if the char is a letter or a digit, otherwise 0.
 * @note A letter or a digit is any char between 48 and 57 inclusive, 
 * between 65 and 90 inclusive or between 97 and 122 inclusive.
 * @note This function is equivalent to ft_isalpha(c) || ft_isdigit(c).
*/
int				ft_isalnum(int c);

/**
 * @brief Check if the char c is a space character.
 * @param c The char to be checked.
 * @return 1 if the char is a space character, otherwise 0.
 * @note A space character is any char between 9 and 13 inclusive or 32.
*/
int				ft_isspace(int c);

/**
 * @brief Convert the char c to lowercase.
 * @param c The char to be converted.
 * @return The lowercase char.
 * @note If the char c is not an uppercase letter, the char c is returned.
*/
int				ft_tolower(int c);

/**
 * @brief Convert the char c to uppercase.
 * @param c The char to be converted.
 * @return The uppercase char.
 * @note If the char c is not a lowercase letter, the char c is returned.
*/
int				ft_toupper(int c);

/**
 * @brief Convert the string s to integer.
 * @param s The pointer to the string.
 * @return The integer converted.
 * @note The string may begin with an arbitrary amount of white space 
 * (as determined by ft_isspace(c)) followed by 
 * a single optional '+' or '-' sign.
 * @note If the first sequence of non-whitespace characters in str 
 * is not a valid integral number, or if no such sequence 
 * exists because either str is empty or it contains only 
 * whitespace characters, no conversion is performed and zero is returned.
 * 
*/
int			ft_atoi(const char *s);

long	ft_atol(const char *s);

/**
 * @brief Convert the string s to integer.
 * @param str The pointer to the string.
 * @param base The string creating the base.
 * @return The integer converted.
 */
long			ft_atol_base(char *str, char *base);

/**
 * @brief Convert the string s in hexadecimal to integer.
 * @param s The pointer to the string.
 * @return The integer converted.
 */
unsigned long	ft_atohex(char *str);

/**
 * @brief Convert the integer n to string.
 * @param n The integer to be converted.
 * @return The string converted.
 * @note The string is ended by a '\0'.
*/
char			*ft_itoa(int n);

/**
 * @brief Create a substring of the string s.
 * @param s The pointer to the string.
 * @param start The start index of the substring.
 * @param len The length of the substring.
 * @return The substring created.
*/
char			*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Create a new string with the result of the concatenation
 * of the strings s1 and s2.
 * @param s1 The pointer to the first string.
 * @param s2 The pointer to the second string.
 * @return The new string created or NULL if the allocation fails.
*/
char			*ft_strjoin(const char *s1, const char *s2);

/**
 * @brief Create a new string removing contains in the string set
 * from the beginning and the end of the string s1.
 * @param s1 The pointer to the string.
 * @param set The pointer to the string set.
 * @return The new string created or NULL if the allocation fails.
*/
char			*ft_strtrim(const char *s1, const char *set);

/**
 * @brief Transform the string removing the elements in set
 * from the beginning and the end.
 * @param s1 The pointer to the string.
 * @param set The pointer to the string set.
 * @return A reference to s1.
 */
char			*ft_str_in_trim(char *s1, const char *set);

/**
 * @brief Create an array of strings obtained by splitting the string s
 * using the char c as a delimiter.
 * @param s The pointer to the string.
 * @param c The char delimiter.
 * @return The array of strings created or NULL if the allocation fails.
 * @note The array of strings is ended by a NULL pointer.
 * @note If the string s does not contain the delimiter c,
 * the array of strings contains a single string which is a copy of s.
*/
char			**ft_split(const char *s, char c);

/**
 * @brief Create a new string obtained by applying the function f
 * to each character of the string s.
 * @param s The pointer to the string.
 * @param f The function to be applied.
 * @return The new string created or NULL if the allocation fails.
 * @note The function f takes as parameters the index of the character
 * and its value.
*/
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/**
 * @brief Apply the function f to each character of the string s.
 * @param s The pointer to the string.
 * @param f The function to be applied.
 * @note The function f takes as parameters the index of the character
 * and its value.
*/
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Print the char c to the specified file descriptor.
 * @param c The char to be printed.
 * @param fd The file descriptor.
*/
int				ft_putchar_fd(char c, int fd);

/**
 * @brief Print the string s to the specified file descriptor.
 * @param s The pointer to the string.
 * @param fd The file descriptor.
 * @note The string s must be ended by a '\0'.
*/
int				ft_putstr_fd(const char *s, int fd);

/**
 * @brief Print the number n to the specified file descriptor.
 * @param n The number to be printed.
 * @param fd The file descriptor.
 * @note If the number n is negative, the '-' sign is printed before the number.
*/
int				ft_putnbr_fd(int n, int fd);

/**
 * @brief Print the unsigned number n to the specified file descriptor.
 * @param n The unsigned number to be printed.
 * @param fd The file descriptor.
*/
int				ft_putunbr_fd(unsigned int n, int fd);

/**
 * @brief Print the string s to the specified file descriptor
 * followed by a '\n'.
 * @param s The pointer to the string.
 * @param fd The file descriptor.
 * @note The string s must be ended by a '\0'.
*/
int				ft_putendl_fd(const char *s, int fd);

/**
 * @brief Get the absolute value of the integer n.
 * @param n The integer.
 * @return The absolute value of the integer n.
 * @note If the integer n is positive, the integer n is returned.
*/
unsigned int	ft_abs(int n);

/**
 * @brief Get the maximum value between the integers a and b.
 * @param a The first integer.
 * @param b The second integer.
 * @return The maximum value between the integers a and b.
 * @note If the integers a and b are equal, the integer a is returned.
*/
int				ft_max(int a, int b);

/**
 * @brief Get the minimum value between the integers a and b.
 * @param a The first integer.
 * @param b The second integer.
 * @return The minimum value between the integers a and b.
 * @note If the integers a and b are equal, the integer a is returned.
*/
int				ft_min(int a, int b);

/**
 * @brief Get the maximum value between the floats a and b.
 * @param a The first float.
 * @param b The second float.
 * @return The maximum value between the floats a and b.
 * @note If the floats a and b are equal, the float a is returned.
*/
float			ft_maxf(float a, float b);

/**
 * @brief Get the maximum value between the double a and b.
 * @param a The first double.
 * @param b The second double.
 * @return The maximum value between the double a and b.
 * @note If the double a and b are equal, the double a is returned.
*/
double			ft_mind(double a, double b);

/**
 * @brief Get the minimum value between the double a and b.
 * @param a The first double.
 * @param b The second double.
 * @return The minimum value between the double a and b.
 * @note If the double a and b are equal, the double a is returned.
*/
double			ft_maxd(double a, double b);

/**
 * @brief Get the minimum value between the floats a and b.
 * @param a The first float.
 * @param b The second float.
 * @return The minimum value between the floats a and b.
 * @note If the floats a and b are equal, the float a is returned.
 */
float			ft_minf(float a, float b);

/**
 * @brief Get the number of digits of the integer n.
 * @param n The integer.
 * @return The number of digits of the integer n.
 * @note If the integer n is negative, the '-' adds 1 to the number of digits.
*/
int				ft_nbrlen(int n);

/**
 * @brief Get the number of digits of the unsigned integer n.
 * @param n The unsigned integer.
 * @return The number of digits of the unsigned integer n.
*/
int				ft_unbrlen(unsigned int n);

/**
 * @brief Create a new node of a linked list.
 * @param content The content of the node.
 * @return The new node created or NULL if the allocation fails.
 * @note The next pointer of the node is initialized to NULL.
*/
t_list			*ft_lstnew(void *content);

/**
 * @brief Add a new node at the beginning of a linked list.
 * @param lst The pointer to the first node of the linked list.
 * @param new The pointer to the new node to be added.
 * @note The pointer to the first node of the linked list is updated.
*/
void			ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Get the number of nodes in a linked list.
 * @param lst The pointer to the first node of the linked list.
 * @return The number of nodes in the linked list.
 * @note If the linked list is empty, 0 is returned.
*/
int				ft_lstsize(t_list *lst);

/**
 * @brief Get the last node of a linked list.
 * @param lst The pointer to the first node of the linked list.
 * @return The pointer to the last node of the linked list.
 * @note If the linked list is empty, NULL is returned.
*/
t_list			*ft_lstlast(t_list *lst);

/**
 * @brief Add a new node at the end of a linked list.
 * @param lst The pointer to the first node of the linked list.
 * @param new The pointer to the new node to be added.
 * @note If the list is empty, the pointer to the first node of the
 * linked list is updated.
*/
void			ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Delete a single node of a linked list.
 * @param lst The pointer to the node to be deleted.
 * @param del The function to be applied to the content of the node.
*/
void			ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Delete all the nodes of a linked list.
 * @param lst The pointer to the first node of the linked list.
 * @param del The function to be applied to the content of the nodes.
 * @note The pointer to the first node of the linked list is updated.
 * @note The function del is applied to the content of each node.
*/
void			ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Apply the function f to the content of each node of a linked list.
 * @param lst The pointer to the first node of the linked list.
 * @param f The function to be applied to the content of the nodes.
 * @note The function f takes as a parameter the content of a node.
*/
void			ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Create a new linked list obtained by applying the function f
 * to the content of each node of a linked list.
 * @param lst The pointer to the first node of the linked list.
 * @param f The function to be applied to the content of the nodes.
 * @param del The function to be applied in case of failure.
 * @return The new linked list created or NULL if the allocation fails.
 * @note The function f takes as a parameter the content of a node.
 * @note The function del is applied to the content of each node in case
*/
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/**
 * @brief Print the format string in the standard output.
 * Replacing the flags using the following paramters.
 * @param format The string used to print text and convert the parameters.
 * @return The number of bytes printed into the standard output.
 */
int				ft_printf(const char *format, ...);

/**
 * @brief Read a line from a file descriptor.
 * @param fd The file descriptor.
 * @return The line read from the file descriptor.
 * @note The line is ended by a '\\n'.
*/
char			*get_next_line(int fd);

int    ft_count_words(const char *str);


/* Utility ft_printf functions. */

int				eval_conversion(const char *format, int *pos, va_list arg);
int				eval_char(va_list arg, t_conversion *data);
int				eval_string(va_list arg, t_conversion *data);
int				eval_pointer(va_list arg, t_conversion *data);
int				eval_decimal(va_list arg, t_conversion *data);
int				eval_unsigned(va_list arg, t_conversion *data);
int				eval_hexlow(va_list arg, t_conversion *data);
int				eval_hexup(va_list arg, t_conversion *data);
int				eval_percentage(t_conversion *data);

int				print_hex(unsigned long int n, char letter);
void			get_lengths(char *flags, va_list arg,
					unsigned int *length, int *prec);
int				ft_conversion(const char *format, int *pos, va_list arg,
					t_conversion *data);
int				padding(int length, char c);
int				ft_hexlen(unsigned long n);
int				check_flags(char *flags, char *valid_flags);
int				ignore_flags(char *flags);
void			add_n(int *n_print, int res);
void			print_sign(int d, int *n_print, char *flags);
void			print_sign_u(int *n_print, char *flags);
int				has_sign(char *flags);

#endif /* LIBFT_H */
