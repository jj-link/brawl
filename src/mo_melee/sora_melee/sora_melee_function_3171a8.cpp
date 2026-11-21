#include <types.h>
#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/so_array.h>
#include <so/event/so_event_system.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_20878[];
extern char lbl_27_data_15218[];
extern char lbl_27_data_46658[];
extern char lbl_27_data_466B8[];
extern char lbl_27_data_81A0[];
extern char lbl_27_data_128[];
extern char lbl_27_bss_D8C[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}
extern const float lbl_27_rodata_74BC;

struct StackEntry : acCmdInterpreterStackData {
    StackEntry() : acCmdInterpreterStackData(Invalid, 0, false, 0, lbl_27_rodata_74BC) {}
};

struct StackStorage {
    void* arrayVtable;
    void* arrayVtable2;
    s32 topIndex : 5;
    s32 lastIndex : 5;
    s32 size : 5;
    u32 isFull : 1;
    StackEntry entries[8];
    StackStorage()
        : arrayVtable(lbl_27_data_15218), arrayVtable2(lbl_27_data_15218 + 0x48),
          topIndex(0), lastIndex(0), size(0), isFull(0) {}
};

struct IGetter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

struct ISys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 check(long);
};

struct IMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 check(long);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* s10(long);
};

struct IUnit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

struct CommandKind { s16 value; char padding[2]; };
struct Registration { void* interpreter; void* addressPack; };
struct IList {
    virtual void v0();
    virtual void fill(Registration*, s16*);
};

extern "C" void* fn_27_3171A8(void* arg0, void* arg1, s32 arg2, f32 farg0) {
    char* self = (char*)arg0;
    u8 sp8;
    CommandKind commandKind;
    Registration registration;

    *(s32*)(self + 0x4) = 0;
    *(void**)(self + 0x0) = lbl_27_data_20878;
    *(s32*)(self + 0x8) = arg2;
    *(s32*)(self + 0xC) = 1;
    if (arg2 == 0) {
        *(s32*)(self + 0xC) = 0;
    }

    new (self + 0x14) StackStorage;

    *(void**)(self + 0xD0) = self;
    *(void**)(self + 0xC0) = lbl_27_data_46658;
    char* ci;
    s32 result = 0;
    StackStorage* storage = (StackStorage*)(self + 0x14);
    char* pack = (char*)(storage + 1);
    *(void**)(pack + 0x14) = lbl_27_bss_D8C;
    *(void**)(pack + 0x18) = lbl_27_bss_D8C;

    soArrayVector<acCmdInterpreterStackData, 8>* stack =
        (soArrayVector<acCmdInterpreterStackData, 8>*)storage;
    sp8 = result;
    char* ctx = *(char**)((char*)arg1 + 0xD8);
    char* obj = *(char**)(ctx + 0x80);
    s32 id = ((IGetter*)(obj + 8))->get();
    ci = self + 0xDC;
    new (ci) acCmdInterpreter(stack, 1, 0, &sp8, farg0);

    *(void**)(ci + 0x34) = lbl_27_data_466B8;
    *(s16*)(ci + 0x38) = id;
    *(s16*)(ci + 0x3A) = 5;
    *(s32*)(ci + 0x3C) = result;

    s32 eventId = (s16)id;
    if (eventId > 0 && eventId > -1) {
        if (((ISys*)soEventSystem::getInstance())->check(eventId) != 0) {
            IMgr* mgr = (IMgr*)soEventSystem::getInstance()->getManager(*(s16*)(ci + 0x38));
            if (mgr->check(*(s16*)(ci + 0x3A)) == 0) {
                result = 0;
                *(s32*)(ci + 0x3C) = result;
            } else {
                s16 temp = *(s16*)(ci + 0x3A);
                IMgr* mgr2 = (IMgr*)soEventSystem::getInstance()->getManager(*(s16*)(ci + 0x38));
                if (mgr2->check(temp) == 0) {
                    result = 0;
                } else {
                    IUnit* u = (IUnit*)__dynamic_cast(mgr2->s10(temp), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (u == 0) {
                        result = 0;
                    } else {
                        result = u->get();
                    }
                }
                *(s32*)(ci + 0x3C) = result;
            }
        }
    }

    *(void**)ci = lbl_27_data_81A0;
    *(void**)(ci + 0x34) = lbl_27_data_81A0 + 0x20;
    *(s32*)(ci + 0x40) = 5;
    *(s32*)(ci + 0x44) = 0;
    *(s32*)(ci + 0x48) = 0;
    *(s32*)(ci + 0x4C) = 0;
    commandKind.value = 16;
    registration.interpreter = self + 0xDC;
    registration.addressPack = self + 0xC0;
    IList* lst = *(IList**)(*(char**)((char*)arg1 + 0xD8) + 0x6C);
    lst->fill(&registration, &commandKind.value);
    return arg0;
}
