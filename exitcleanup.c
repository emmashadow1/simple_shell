i#include "shell.h"
#include "alias.h"
#include "shellvars.h"

char ***getenviron();
ShellVar **getspecial();
ShellVar **getvars();
AliasData **getalist();

/**
 * exitcleanup - cleans up various vars before exiting
 * @av: argument list to free (if any)
 * Return: void
 */
