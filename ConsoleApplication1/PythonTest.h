#pragma once

// we call Python over PyRun_SimpleFile
// one more (changed on GitHub) comment
void SimpleWay(int argc, char *argv[], char * envp[]);
void EmbeddedWay(int argc, char *argv[], char * envp[]);

