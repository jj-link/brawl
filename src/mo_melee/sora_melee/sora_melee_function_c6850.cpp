#include <types.h>
#include <gf/gf_task.h>
#include <sr/sr_common.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_186A0[];
extern float lbl_27_rodata_EF0;
extern float lbl_27_rodata_EF4;
void __dt__6gfTaskFv(gfTask*, int);
}
struct SubObj {
virtual void f0(); virtual void f1(); virtual void f2();
virtual void f3(); virtual void f4(); virtual void f5();
virtual void f6(); virtual void f7(); virtual void f8();
};
struct Obj {
char pad0[0x3C];
void* m3C; void* m40;
s32 m44; s32 m48; s32 m4C;
SubObj m50;
char pad54[0x28];
float m7C; float m80; float m84; float m88;
char pad8C; s8 m8D; s8 m8E;
};
extern "C" Obj* fn_27_C6850(Obj* p, s32 arg1) {
if (p != nullptr) {
p->m40 = (void*)lbl_27_data_186A0;
p->m3C = (void*)(lbl_27_data_186A0 + 8);
p->m44 = -1; p->m48 = 0; p->m4C = 0;
p->m50.f8();
float ef1;
float ef0;
ef0 = lbl_27_rodata_EF0;
ef1 = lbl_27_rodata_EF4;
p->m8D = 0; p->m8E = 0;
p->m80 = ef0; p->m7C = ef0;
p->m88 = ef1; p->m84 = ef1;
__dt__6gfTaskFv((gfTask*)p, 0);
if (arg1 > 0) { ::operator delete(p); }
}
return p;
}
