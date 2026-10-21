#include <types.h>
#pragma force_active on

extern "C" {

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);

extern char lbl_40_data_37BC[];
extern float lbl_40_rodata_25C;
extern unsigned char* g_GameGlobal;

struct Task {
    unsigned char pad0[0x2C];
    unsigned char flags;
    unsigned char pad2[0xF];
    void* p3C;
    float f40;
    int v44, v48, v4C, v50;
    unsigned char pad54[0x68];
    int vBC;
    unsigned char c0, c1;
    unsigned char padc2[2];
    float fc4;
    int vc8;
    unsigned char padcc[4];
    unsigned char d0, d1, d2;
    unsigned char padd3[9];
    int vdc, ve0;
};

Task* fn_40_174B4(Task* self, const char* name) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        self, name, 0, 13, 6, true);

    float value = lbl_40_rodata_25C;
    self->p3C = lbl_40_data_37BC;
    self->f40 = value;
    self->v44 = 0;
    self->v48 = 0;
    self->v4C = 0;
    self->v50 = 0;
    self->vBC = 0;
    self->c0 = 0;
    self->c1 = 0;
    self->fc4 = value;
    self->vc8 = 0;
    self->d0 = 0;
    self->d1 = 1;
    self->d2 = 1;
    self->vdc = 0;
    self->ve0 = 0;
    self->flags &= ~2;
    self->v44 = *(int*)(g_GameGlobal + 0x30);
    return self;
}

}
