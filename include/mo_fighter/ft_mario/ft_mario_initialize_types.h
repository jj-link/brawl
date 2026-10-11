#pragma once
#include <so/so_module_accesser.h>

struct MarioMantleInitializeObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
struct MarioMantleInitializeVector { float x; float y; float z; };
struct MarioMantleInitializeFlags {
    unsigned char first : 1;
    unsigned char second : 1;
    unsigned char third : 1;
    unsigned char fourth : 1;
    unsigned char fifth : 1;
    unsigned char sixth : 1;
    unsigned char seventh : 1;
    unsigned char eighth : 1;
    unsigned char ninth : 1;
    unsigned char tenth : 1;
    unsigned char reserved : 6;
};
struct MarioMantleInitializeParam {
    int resource;
    int team;
    int teamOwner;
    int teamAnother;
    int index;
    int owner;
    int reserved0;
    int reserved1;
    MarioMantleInitializeVector position;
    float facing;
    int parameter;
    int reserved2;
    int situation;
    int status;
    int reserved3;
    int motion;
    int reserved4;
    MarioMantleInitializeFlags flags;
};
