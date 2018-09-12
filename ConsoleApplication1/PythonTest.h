#pragma once

// we call Python over PyRun_SimpleFile
// one more (changed on GitHub) (inserted) comment
void SimpleWay(int argc, char *argv[], char * envp[]);
void EmbeddedWay(int argc, char *argv[], char * envp[]);

