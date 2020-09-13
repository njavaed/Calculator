# Calculator

The intent of this command line application was to implement software design patterns and ***SOLID*** principles. The resultant application is robust.

***Architecture***
1. Command Pattern
2. Composite Pattern 
3. Abstract Factory Method
4. Builder pattern

***Tech Stack***
1. MPC (Makefile Project Workspace Creator)
2. C++
3. Visual Studio Code

***Functionality***  
This project uses ***MPC***. The information about MPC can be found at https://github.com/DOCGroup/MPC . This tool generates a project based on input files. 
The source code is written in ***C++***. I use Visual Studio Code to write this program because it is my favorite code editor. The program takes input from std::cin and output to std::cout. The user can enter any equation based on following arithmetic operators:
1. +
2. -
3. /
4. %
5. *
6. (
7. ) 

Make sure the input is spaced out. For e.g. 3 + 4, 5 - 2, ( 4 * ( 3 - 2 ) )  
The program won't accept inputs that are not spaced out.   

Note: This program does not work for implied multiplication.


***How to run***  
First you need to download mpc. Add it to your path so that you are able to run mpc commands from any folder. The directions for downloading and running mpc are here https://github.com/hilljh82/jhillgotskillz/blob/master/guides/mpc/setup.md . It provides for running both on mac and windows.
If you have mpc downloaded and added to path you should be able to run:   
1. Run mwc.pl -type vc12  
2. Run make assignment4
3. Run ./assignment4


  
