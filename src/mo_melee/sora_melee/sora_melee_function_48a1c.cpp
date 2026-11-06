#include <so/status/so_status_event_presenter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#pragma force_active on
typedef unsigned char u8;
typedef short s16;
struct Getter {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual s16 get();
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual u32 slot2();
};
struct Object_vptr_4_base { char pad[4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public: virtual void slot0();
};
struct Object_vptr_10_base { char pad[0x10]; };
class Object_vptr_10 : public Object_vptr_10_base {
public: virtual void slot0();
};
struct Module { u8 pad[0x18]; Object_vptr_0* object18; u8 pad1c[0x64]; void* object80; };
struct Owner { u8 pad[0xd8]; Module* module; };
extern "C" u8 lbl_27_data_4448[];
extern "C" u8 lbl_27_data_4320[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" void fn_27_35C3C(void*, u32, u8, u32, u32, u32, u8);
extern "C" void* fn_27_48A1C(void* self, Owner* owner, u32 a2, u8 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u8 a9) {
    u8* s = (u8*)self;
    *(void**)s = lbl_27_data_4448;
    s16 id = ((Getter*)((u8*)owner->module->object80 + 8))->get();
    soStatusEventObserver* status = (soStatusEventObserver*)(s + 4);
    status->m_manageID = -1;
    status->m_unitID = 4;
    status->m_sendID = -1;
    *(void***)status = __vt__21soStatusEventObserver;
    status->addObserver(id, -1);
    id = ((Getter*)((u8*)owner->module->object80 + 8))->get();
    soAnimCmdEventObserver* anim = (soAnimCmdEventObserver*)(s + 0x10);
    anim->m_manageID = -1;
    anim->m_unitID = 5;
    anim->m_sendID = -1;
    *(void***)anim = __vt__22soAnimCmdEventObserver;
    anim->addObserver(id, -1);
    *(Owner**)(s + 0x1c) = owner;
    *(void**)s = lbl_27_data_4320;
    *(void**)(s + 4) = lbl_27_data_4320 + 0xa8;
    *(void**)(s + 0x10) = lbl_27_data_4320 + 0xb8;
    *(u32*)(s + 0x20) = a4;
    *(u32*)(s + 0x24) = 0;
    fn_27_35C3C(s + 0x28, a2, a3, owner->module->object18->slot2(), a8, a5, 0);
    *(u32*)(s + 0x48) = a6;
    *(u32*)(s + 0x4c) = a7;
    s[0x50] = 0;
    s[0x51] = 0;
    s[0x52] = a9;
    return self;
}