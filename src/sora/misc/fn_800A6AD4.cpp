#include <types.h>
#pragma force_active on

extern "C" void* memset(void*, int, unsigned long);
extern "C" u8 lbl_80454F28[0x14];
extern "C" const float lbl_805A2058;
extern "C" const float lbl_805A205C;

struct Report {
    u32 f00;
    void* f04;
    u32 f08;
    u32 f0c;
    float f10;
    u8 pad14[0x30];
    float f44;
    float f48;
    float f4c;
    u8 f50;
    u8 pad51[3];
    float f54;
    float f58;
    float f5c;
    u32 f60;
    float f64;
    float f68;
    u8 buf6c[0x40];
    u32 fac;
    u32 fb0;
    u32 fb4;
    u8 fb8;
};

extern "C" Report* fn_800A6AD4(Report* self) {
    self->f04 = lbl_80454F28;
    self->f00 = 0;
    self->f08 = 0;
    self->f0c = 0;
    self->f10 = lbl_805A2058;
    self->f44 = lbl_805A205C;
    self->f48 = lbl_805A205C;
    self->f4c = lbl_805A205C;
    self->f50 = 0;
    self->f54 = lbl_805A205C;
    self->f58 = lbl_805A205C;
    self->f5c = lbl_805A205C;
    self->f60 = 0;
    self->f64 = lbl_805A205C;
    self->f68 = lbl_805A205C;
    self->fb8 = 0;
    memset(self->buf6c, 0, 0x40);
    self->fb0 = 0;
    self->fac = 0;
    self->fb4 = 0;
    return self;
}
