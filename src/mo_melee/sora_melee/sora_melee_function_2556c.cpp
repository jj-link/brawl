#include <types.h>
#pragma force_active on
struct Getter { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual s16 get(); };
struct Observer { virtual void attach(s16, s32); s16 id; s16 type; s16 link; };
struct Module { u8 pad[0x80]; void* object; };
struct Owner { u8 pad[0xD8]; Module* module; };
struct Object {
 void* ptr0; u8 flag4; u8 pad5[3]; void* ptr8; Observer obs1; Observer obs2; void* ptr24;
 s32 field28; s32 field2C; s32 field30; s32 field34; u8 flag38 : 4; u8 : 4; u8 pad39[3];
 s32 field3C; float field40; s32 field44; s32 field48; float field4C; u8 flag50; u8 pad51[3]; Owner* owner;
};
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" u8 lbl_27_data_28A0[];
extern "C" u8 lbl_27_data_2BD0[];
extern "C" const float lbl_27_rodata_3C0;
extern "C" const float lbl_27_rodata_3C4;
extern "C" Object* fn_27_2556C(Object* self, Owner* owner, s32 arg2, s32 arg3, s32 arg4) {
 self->flag4 = 0;
 self->ptr8 = (void*)lbl_27_data_2BD0;
 self->ptr0 = (void*)(lbl_27_data_2BD0 + 8);
 s16 id = ((Getter*)((u8*)owner->module->object + 8))->get();
 self->obs1.id = -1; self->obs1.type = 4; self->obs1.link = -1;
 *(void***)&self->obs1 = __vt__21soStatusEventObserver;
 self->obs1.attach(id, -1);
 id = ((Getter*)((u8*)owner->module->object + 8))->get();
 Observer* o2 = &self->obs2;
 o2->id = -1; o2->type = 5; o2->link = -1;
 *(void***)o2 = __vt__22soAnimCmdEventObserver;
 o2->attach(id, -1);
 self->ptr8 = (void*)lbl_27_data_28A0;
 self->ptr0 = (void*)(lbl_27_data_28A0 + 8);
 *(void**)&self->obs1 = (void*)(lbl_27_data_28A0 + 0x270);
 *(void**)&self->obs2 = (void*)(lbl_27_data_28A0 + 0x280);
 self->ptr24 = (void*)(lbl_27_data_28A0 + 0x294);
 self->field28 = arg2; self->field3C = 0; self->field40 = lbl_27_rodata_3C0;
 self->field44 = arg4; self->field48 = arg3; self->field4C = lbl_27_rodata_3C4;
 self->flag50 = (u8)(((self->flag50 & 0xFFFFFF1F) | 0x10) & 0xFFFFFFF7);
 self->owner = owner; self->field2C = 0; self->field30 = 0; self->field34 = 0;
 self->flag38 = 0;
 return self;
}