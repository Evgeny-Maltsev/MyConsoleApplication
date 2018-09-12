#pragma once

// we call Python over PyRun_SimpleFile
// one more (inserted) comment
void SimpleWay(int argc, char *argv[], char * envp[]);
void EmbeddedWay(int argc, char *argv[], char * envp[]);

