#include "shell.h"

/**
 * tokenize_input - Splits the input into tokens
 * @input: The input string
 *
 * Return: Array of strings (tokens)
 */
char **tokenize_input(char *input)
{
	char **tokens, *token;
	int token_count = 0;

	tokens = malloc(sizeof(char *) * MAX_TOKENS);
	if (!tokens)
		return (NULL);

	token = strtok(input, " \t\n");
	while (token && token_count < MAX_TOKENS - 1)
	{
		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			free_args(tokens);
			return (NULL);
		}
		token_count++;
		token = strtok(NULL, " \t\n");
	}
	tokens[token_count] = NULL;

	return (tokens);
}

/**
 * free_args - Frees the argument array
 * @args: The argument array to free
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/**
 * get_command_path - Gets the full path of a command
 * @command: The command to find
 * @env: The environment variables
 *
 * Return: Full path of the command or NULL if not found
 */
char *get_command_path(char *command, char **env)
{
	char *path = NULL, *dir, *full_path, *path_copy;
	struct stat st;
	int i = 0;

	if (strchr(command, '/') && stat(command, &st) == 0)
		return (strdup(command));

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break;
		}
		i++;
	}
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
			break;
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
