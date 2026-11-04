#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on
extern "C" {
int sprintf(char*, const char*, ...);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_800B3C5C(void*, const void*, int);
void fn_800B7F38(void*, int, float);
void fn_800B7AA4(void*, int, float);
void fn_800B6838(void*, void*);
extern char lbl_804569E0[];
extern char lbl_8059E0A0[8];
extern float lbl_805A2248;
}
struct Model { char pad[12]; void* scene; };
struct S {
    char pad0[0x48]; int field48;
    char pad4c[0x118-0x4c]; Model* previous[1]; Model* models[5];
    char pad130[0xb68-0x130]; void* scene;
    char padb6c[0x1090-0xb6c]; int index; int base; char flag;
    char pad1099[0x12b0-0x1099]; int current; int count;
    char pad12b8[0x12cc-0x12b8]; char position[0x14];
    int mode; char pad12e4; char active; char pad12e6[2]; int value;
};
extern "C" void fn_800BD3C8(S* self, int mode) {
    char buf[8];
    int index;
    self->mode = mode;
    self->active = 1;
    self->field48 = 0;
    self->value = self->base + self->index * 4;
    switch (mode) {
    case 0:
        self->flag = 0;
        index = self->current;
        break;
    case 2:
        index = self->current;
        fn_800B3C5C(self->models[index], lbl_804569E0, 1);
        fn_800B7F38(self->models[self->current], 0x11, lbl_805A2248);
        fn_800B7AA4(self->models[self->current], 0x11, lbl_805A2248);
        break;
    case 1:
        index = self->count - 1;
        fn_800B3C5C(self->previous[self->count], lbl_804569E0 + 0x28, 1);
        break;
    }
    sprintf(buf, lbl_8059E0A0, self->value);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->models[index]->scene, buf);
    fn_800B6838(self->models[index], self->position);
}