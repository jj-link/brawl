#include <so/status/so_status_event_presenter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef signed char s8;
struct Object_vptr_4_base { char pad[4]; };
class Object_vptr_4 : public Object_vptr_4_base { public: virtual void slot0(); };
struct Object_vptr_10_base { char pad[0x10]; };
class Object_vptr_10 : public Object_vptr_10_base { public: virtual void slot0(); };
struct Getter {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual s16 get();
};
struct Module { u8 pad[0x80]; void* object; };
struct Owner { u8 pad[0xd8]; Module* module; };
extern "C" u8 lbl_27_data_A418[];
extern "C" u8 lbl_27_data_16058[];
extern "C" u8 lbl_27_data_16100[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" void fn_27_AE448(void*);
extern "C" void fn_27_ACEE4(void*);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void* fn_27_ACAC4(void* self, Owner* owner, int a2, int a3, s8 a4, float f) {
 u8* s = (u8*)self;
 *(void**)s = lbl_27_data_A418;
 s16 id = ((Getter*)((u8*)owner->module->object + 8))->get();
 soStatusEventObserver* status = (soStatusEventObserver*)(s + 4);
 status->m_manageID = -1;
 status->m_unitID = 4;
 status->m_sendID = -1;
 *(void***)status = __vt__21soStatusEventObserver;
 status->addObserver(id, -1);
 id = ((Getter*)((u8*)owner->module->object + 8))->get();
 soAnimCmdEventObserver* anim = (soAnimCmdEventObserver*)(s + 0x10);
 anim->m_manageID = -1;
 anim->m_unitID = 5;
 anim->m_sendID = -1;
 *(void***)anim = __vt__22soAnimCmdEventObserver;
 anim->addObserver(id, -1);
 *(void**)s = lbl_27_data_16058;
 *(void**)(s + 4) = lbl_27_data_16058 + 0x2c;
 *(void**)(s + 0x10) = lbl_27_data_16058 + 0x3c;
 *(Owner**)(s + 0x1c) = owner;
 *(int*)(s + 0x20) = a2;
 *(int*)(s + 0x24) = a3;
 *(int*)(s + 0x28) = 0;
 *(void**)(s + 0x34) = lbl_27_data_16100;
 *(void**)(s + 0x38) = lbl_27_data_16100 + 0x48;
 *(u32*)(s + 0x3c) &= 0x1ffffff;
 __construct_array(s + 0x40, fn_27_AE448, fn_27_ACEE4, 0xc, 1);
 *(float*)(s + 0x70) = f;
 *(int*)(s + 0x6c) = 0xffff;
 *(int*)(s + 0x74) = -1;
 *(int*)(s + 0x78) = 0;
 s[0x7c] = a4;
 return self;
}