#include "shell.h"
#include "alias.h"
/**
 * getalist - static wrapper getalias list
 * Return: address alist
 *
 */
AliasData **getalist()
{
	static AliasData *alist;

	return (&alist);
}
/**
 * getalias - get alias value
 * returns original argument if not found
 * @name: name of alias
 * Return: original argument if not found, otherwise value
 */
char *getalias(char *name)
{
	AliasData *alist = *(getalist());
	AliasData *ptr = alist;

	while (ptr != NULL && _strcmp(ptr->name, name))
	{
#ifdef DEBUGMODE
		printf("Checked .%s. against .%s.\n", name, ptr->name);
#endif
		ptr = ptr->next;
	}
	if (ptr == NULL)
	{
#ifdef DEBUGMODE
		printf("Alias not found %s\n", name);
#endif
		return (name);
	}
#ifdef DEBUGMODE
	printf("Checking alias %s\n", ptr->val);
#endif

	free(name);
	return (getalias(_strdup(ptr->val)));
}
