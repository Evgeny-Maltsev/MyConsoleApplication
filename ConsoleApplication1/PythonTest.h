#pragma once

// we call Python over PyRun_SimpleFile
void SimpleWay(int argc, char *argv[], char * envp[]);
void EmbeddedWay(int argc, char *argv[], char * envp[]);

