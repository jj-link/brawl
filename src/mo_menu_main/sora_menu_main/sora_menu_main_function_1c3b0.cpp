#pragma force_active on
#include <types.h>
#include <mu/mu_object.h>
extern "C" {
extern unsigned char lbl_2_rodata_6D0[];
void fn_2_1C8AC(void*, int);
void fn_2_1C598(void*);
void fn_2_1D270(void*);
void fn_2_1C6F0(void*, int);
}
struct Class_728_base { char pad[0x3c]; };
class Class_728 : public Class_728_base {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
virtual void slot24(); virtual void fn_2_36914(); virtual void fn_2_36908();
virtual void fn_2_361C4(int, int);
};
struct Arg1 {
virtual void m00(); virtual void m01(); virtual void m02(); virtual void m03();
virtual void m04(); virtual void m05(); virtual void m06(); virtual void m07();
virtual void m08(); virtual void m09(); virtual void m10(); virtual void m11(int, void*);
u8 pad[0xe0]; s32 e4;
};
struct ObjBc { u8 pad[0x10]; void* u10; void* f14; };
struct Objects { u8 pad[0x1bc]; ObjBc* bc; MuObject* arrow; MuObject* items[4]; };
struct P650 { u8 pad[0x24]; void* p; };
struct Self {
u8 pad[0x64c]; Objects* objects; P650* p650; Arg1* a654; Class_728* a658;
u8 pad65c[8]; s32 f664; u8 pad668[4];
unsigned char flag : 1; unsigned char otherFlags : 7; u8 pad66d[3];
s32 f670; s32 f674; s32 f678; s32 f67c; s32 f680; s32 f684;
};
extern "C" void fn_2_1C3B0(Self* self, Arg1* arg1) {
const float* rb = (const float*)lbl_2_rodata_6D0;
self->f670 = 4;
self->a654 = arg1;
self->f674 = 3;
self->f678 = 0;
self->f67c = 0;
self->f680 = 0;
self->f684 = 0;
self->flag = 0;
self->a658->fn_2_361C4(0x22, 0);
arg1->m11(arg1->e4, self->objects->bc->u10);
arg1->m11(arg1->e4, self->p650->p);
self->f664 = 0;
((MuObject*)self->objects->bc)->setFrameTex(rb[0]);
((MuObject*)self->objects->bc)->m_modelAnim->m_anmObjTexPatRes->SetUpdateRate(rb[1]);
fn_2_1C8AC(self, 1);
if (self->f674 != 0) {
self->objects->arrow->setFrameMatCol(rb[1]);
self->objects->arrow->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(rb[1]);
self->f674 = 0;
}
fn_2_1C598(self);
fn_2_1D270(self);
fn_2_1C6F0(self, self->f684);
if (self->f67c > 0) {
int selected = self->f680;
int i = 0;
int offset = 0;
do {
((MuObject**)((char*)self->objects + offset + 0x1c4))[0]->setFrameMatCol(i == selected ? rb[2] : rb[1]);
((MuObject**)((char*)self->objects + offset + 0x1c4))[0]->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(rb[1]);
++i;
offset += 4;
} while (i < 4);
}
}
