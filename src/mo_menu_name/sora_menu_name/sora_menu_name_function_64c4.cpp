#include <mu/mu_msg.h>
#include <cstring>
#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
extern float lbl_16_rodata_268;
void fn_8004D674(void*, int, void*);
int fn_8004D9A8(void*, int);
void* fn_8004DA80(void*, unsigned char);
void fn_16_7154(void*, void*);
void fn_800B5854(void*, int, int, int, int);
}
struct Data45 { unsigned char a[8]; unsigned char b, c, d, e; unsigned char f[16]; unsigned char g, h, i, j; unsigned char k[13]; };
struct Local { unsigned char flags : 1; unsigned char rest : 7; unsigned char pad; unsigned char name[12]; Data45 data; unsigned char tail; };
struct Self {
 char pad0[0x70]; MuObject* object;
 char pad74[0xe0]; MuMsg* msg;
 char pad158[0x2ac]; int index; void* target;
 char pad40c[0x4c]; void* message;
 char pad45c[0x18]; unsigned char flag;
};
extern "C" void fn_16_64C4(Self* self) {
 void* global = g_GameGlobal;
 self->msg->printIndex(6, 3, self->message);
 self->object->setFrameVisible(lbl_16_rodata_268);
 Local local;
 memset(&local, 0, 0x3c);
 fn_8004D674(global, self->index, local.name);
 local.flags = fn_8004D9A8(global, self->index);
 local.data = *(Data45*)fn_8004DA80(global, (unsigned char)self->index);
 self->flag = 0;
 fn_16_7154(self->target, &local);
 fn_800B5854(self->object, 3, 0x11, 1, 0);
}