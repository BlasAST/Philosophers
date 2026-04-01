*This project has been created  as part of the 42 curriculum by bsiguenc*

# Description
Philosophers is a project that consists of the implementation of a program that receives specific data and through this creates a number of philosophers (threads) equal to a number of forks (mutexes). The philosophers must eat with two forks, one in each hand, and no one should be using them, so they must take turns to eat (use the mutex).

The goal of carrying out this project is to learn how to manage a multithreaded environment by sharing a common memory space, ensuring the proper management of resources and their debugging.

With this project we have learned:

* Thread management: Creation, execution, and waiting of multiple simultaneous execution flows
* Mutual Exclusion (Mutex): Protection of critical sections of code to avoid Data Races
* Deadlock Prevention
* Time Accuracy: Correct system handling when sharing the CPU and maintaining an accurate clock


# Instructions
## Installation
For the installation of this project, it is necessary to clone the repository [Philosophers](https://github.com/BlasAST/Philosophers) executing the following command:

```
git clone https://github.com/BlasAST/Philosophers

```

In case your goal is the development of the same project, you will need to have a Linux environment for the project to work since it depends on this operating system.

Next, you should install the C language to compile the project's source code, and it will be compiled using Makefile to be able to create the executable.

```

sudo apt update && sudo apt upgrade -y && sudo apt install build-essential && sudo apt install make

```

To check its correct installation.

C:
```

cc -version

```
Make:
```

make --version

```

## Compilation

For the compilation of the project we will use **make**, which will be responsible for linking and building all the files necessary for the creation of the executable, which will also be generated.

Make allows you to have multiple instructions with different objectives:

For the cleaning of all object files (.o) generated during compilation
```
make clean

```

For the complete cleanup of the project (the .o files and the executable)
```
make fclean
```

For a recompilation of the project (run make fclean and make again with a single command)
```
make re
```


## Execute
After compiling the project and obtaining the executable, we can use it by launching
```
./philo
```

...

To complete the project execute
```
Control + C
``` 
Or with a set number of meals
# Resources
For the proper development of the project, research has been conducted on documentation, manuals, standards, and AI
* References:
	* [Multithreading in C](https://www.geeksforgeeks.org/c/multithreading-in-c/)
	* [pthreads](https://www.man7.org/linux/man-pages/man7/pthreads.7.html)
	* [CONCURRENCIA](https://www.youtube.com/watch?v=8KFvrgbuWxY)
	* [Procesos](https://jrgil20.github.io/S.O.Tarea1-Procesos/)
	* [gettimeofday](https://www.delftstack.com/es/howto/c/gettimeofday-in-c/)
	* More

On the other hand, artificial intelligence has been used for concept clarification, explanation or clarification of necessary information, error correction after several attempts to solve it, and for the development and review of documentation.