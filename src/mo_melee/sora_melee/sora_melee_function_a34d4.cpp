#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_A908[], lbl_27_data_15758[], lbl_27_data_59A0[], lbl_27_data_15614[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" void* __vt__21soStatusEventObserver[];

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual u32 slot6();
    virtual u32 slot7();
    virtual void slot8();
    virtual void slot9();
    virtual u32 slot10();
};

class Getter {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual int get();
};

class Observer {
public:
    virtual void addObserver(short, signed char);
    short id, type, link;
};

extern "C" void* fn_27_A34D4(void* selfp, void* accesser, u8 flag, s32 a3, s32 a4, s32 a5, s32 a6, Object_vptr_0* obj, s32 a8) {
    s32 sitId;
    char* self = (char*)selfp;
    *(u8*)(self + 4) = 0;
    *(void**)self = lbl_27_data_A908;
    *(void**)(self + 8) = lbl_27_data_15758;

    s32 idAnim;
    if (obj->slot7() == 1) {
        char* p = *(char**)((char*)accesser + 0xd8);
        p = *(char**)(p + 0x80);
        idAnim = ((Getter*)(p + 8))->get();
    } else {
        idAnim = -1;
    }

    s32 statusId = -1;
    Observer* anim = (Observer*)(self + 0xc);
    anim->id = statusId;
    anim->type = 5;
    anim->link = statusId;
    *(void**)anim = __vt__22soAnimCmdEventObserver;
    anim->addObserver((short)idAnim, -1);

    if (obj->slot6() == 1) {
        char* p = *(char**)((char*)accesser + 0xd8);
        p = *(char**)(p + 0x80);
        statusId = ((Getter*)(p + 8))->get();
    }

    sitId = -1;
    Observer* status = (Observer*)(self + 0x18);
    status->id = sitId;
    status->type = 4;
    status->link = sitId;
    *(void**)status = __vt__21soStatusEventObserver;
    status->addObserver((short)statusId, -1);

    if (obj->slot10() == 1) {
        char* p = *(char**)((char*)accesser + 0xd8);
        p = *(char**)(p + 0x80);
        sitId = ((Getter*)(p + 8))->get();
    }

    Observer* sit = (Observer*)(self + 0x24);
    sit->id = -1;
    sit->type = 8;
    sit->link = -1;
    *(void**)sit = lbl_27_data_59A0;
    sit->addObserver((short)sitId, -1);

    u8 f = *(u8*)(self + 0x45);
    *(s32*)(self + 0x30) = a3;
    *(void**)self = lbl_27_data_15614;
    *(void**)(self + 8) = lbl_27_data_15614 + 0x88;
    *(void**)(self + 0xc) = lbl_27_data_15614 + 0x94;
    *(void**)(self + 0x18) = lbl_27_data_15614 + 0xa8;
    *(void**)(self + 0x24) = lbl_27_data_15614 + 0xb8;
    *(s32*)(self + 0x34) = a4;
    *(s32*)(self + 0x38) = a5;
    *(s32*)(self + 0x3c) = a6;
    *(s32*)(self + 0x40) = a8;
    *(u8*)(self + 0x44) = flag;
    *(u8*)(self + 0x45) = (u8)((f & ~0x80) | 0x40);
    *(void**)(self + 0x48) = accesser;
    return selfp;
}
