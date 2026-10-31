#include <so/status/so_status_event_presenter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;

extern "C" u8 lbl_27_data_A608[];
extern "C" u8 lbl_27_data_15970[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];

struct Getter {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s16 get();
};

struct FinalModuleObject {
    virtual void f0();
};

struct Module {
    u8 pad[0x80];
    void* observerObject;
    u8 pad84[0x0C];
    FinalModuleObject* finalObject;
};

struct Owner {
    u8 pad[0xD8];
    Module* module;
};

extern "C" void* fn_27_A9804(
    void* self, Owner* owner, s32 a2, s32 a3, s32 a4, s32 a5
) {
    u8* s = (u8*)self;

    s[4] = 0;
    *(void**)s = lbl_27_data_A608;

    s16 id = ((Getter*)((u8*)owner->module->observerObject + 8))->get();

    soStatusEventObserver* status =
        (soStatusEventObserver*)(s + 8);
    status->m_manageID = -1;
    status->m_unitID = 4;
    status->m_sendID = -1;
    *(void***)status = __vt__21soStatusEventObserver;
    status->addObserver(id, -1);

    id = ((Getter*)((u8*)owner->module->observerObject + 8))->get();

    soAnimCmdEventObserver* anim =
        (soAnimCmdEventObserver*)(s + 0x14);
    anim->m_manageID = -1;
    anim->m_unitID = 5;
    anim->m_sendID = -1;
    *(void***)anim = __vt__22soAnimCmdEventObserver;
    anim->addObserver(id, -1);

    s[0x1E] = 0;
    *(void**)s = lbl_27_data_15970;
    *(void**)(s + 8) = lbl_27_data_15970 + 0x38;
    *(void**)(s + 0x14) = lbl_27_data_15970 + 0x48;
    *(void**)(s + 0x20) = owner;
    *(s32*)(s + 0x24) = a2;
    *(s32*)(s + 0x28) = a3;
    *(s32*)(s + 0x2C) = a4;
    *(s32*)(s + 0x30) = a5;

    owner->module->finalObject->f0();

    return self;
}
