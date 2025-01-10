# PROJECT: SIMPLE SHELL



### Description



The shell is the Linux command line interpreter. It provides an interface between the user and the kernel and executes commands.

It consists in creating an interactive system for command line interpretation. Interpretation takes place in several
stages:
- a prompt for command lines
- option management
- and their execution, if the command exists.




### Build With



* [![language.C]][c.url]




## File Descriptions



* [AUTHORS](AUTHORS) - It lists the contributors of this project

* [man_1_simple_shell](man_1_simple_shell) - The Manual describing usage of the simple_shell

* [shell.h](shell.h) - The header file used in this project





## Requirement



### General

- Allowed editors: vi, vim, emacs

- All files were compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`

- Betty coding style is followed.



### Installation

Designed to run on `Ubuntu 20.04 LTS`, the simple_shell can be installed as follows:

* Clone the current repository with the command:```git clone "https://github.com/stephenmakenziwaweru/simple_shell.git"```

* Create an executable using: ```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```

* Run the executable either in interative mode `./hsh` or non-interactive mode `echo "pwd" | ./hsh`

  
## Synopsis


**Step 1: Interactive Mode** Before launching our program, we have the possibility to interact with the interactive mode or not. If the interactive mode is launched, we move on to step 2. The non-interactive mode allows command execution without direct access to the shell.

![image](https://github.com/user-attachments/assets/3b6a6339-e4cd-4ef2-9829-84d41be1f56e)



**Step 2: The Main Loop** Our shell starts with setting up a main loop. At each iteration of this loop, the shell displays a prompt (for example, "$ "), waits for the user’s input, and reads the command entered.

**Step 3: Order Analysis** The program implements a function to analyze the command entered by the user. This function divides the command line into tokens (words) based on spaces. The first token is usually the command name, and the following are the arguments.

**Step 4: Creating the Child Process** When a command is entered, the shell creates a new child process using the `fork()` system call. The child process will execute the command using the system call `execvp()`, while the parent process will wait for the child to complete. The associated commands allow the processing of several basic commands such as `ls', 'cat', 'echo', and their options

## flowchart
![flowchart simple shell](https://github.com/user-attachments/assets/f32e9885-9931-4aa1-bfba-9430f2957376)

## Special thanks
We strongly thank our SWE Axel. Without whom this project would not have seen the light of day
