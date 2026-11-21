#include <types.h>
#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_20878[];
extern char lbl_27_data_128[];
extern char lbl_27_data_15218[];
extern char lbl_27_data_46658[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_data_466B8[];
extern char lbl_27_data_81A0[];
extern const float lbl_27_rodata_7C14;
extern char __RTTI__11soEventUnit[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(void*, void*);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual s16 slot7();
    virtual void slot8();
};

struct SystemVTable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 check(long);
};

struct ManagerVTable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 check(long);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* get(long);
};

struct UnitVTable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 result();
};

struct Entry {
    s32 a;
    s32 b;
    u8 c;
    s32 d;
    f32 e;

    void reset() {
        a = -1;
        b = 0;
        c = 0;
        d = 0;
        e = lbl_27_rodata_7C14;
    }
};

struct StackHeader {
    void* vtable;
    u8* data;
    s32 topIndex : 5;
    s32 lastIndex : 5;
    s32 size : 5;
    u32 isFull : 1;
    Entry elements[8];
};

extern "C" void* fn_27_37EEF0(void* self, void* arg1, s32 arg2, f32 farg0) {
    s16 evt;
    acCmdInterpreter* interpreter;
    s32 result;
    soArrayVector<acCmdInterpreterStackData, 8>* stack;
    s32 eid;
    s16 temp;
    u8 resetMode;
    struct Blk {
        s16 capacity;
        void* ranges[2];
    } blk;
    StackHeader* stackHeader;
    ManagerVTable* manager;
    ManagerVTable* manager2;
    UnitVTable* unit;
    char* base = (char*)self;
    char* ctx;
    char* obj;
    Entry* p;

    *(s32*)(base + 0x04) = 0;
    *(void**)(base + 0x00) = lbl_27_data_20878;
    *(s32*)(base + 0x08) = arg2;
    *(s32*)(base + 0x0C) = 0x203;
    if (arg2 == 0)
        *(s32*)(base + 0x0C) = 0;

    stackHeader = (StackHeader*)(base + 0x14);
    stackHeader->vtable = lbl_27_data_15218;
    stackHeader->data = (u8*)lbl_27_data_15218 + 0x48;
    stackHeader->topIndex = 0;
    stackHeader->lastIndex = 0;
    stackHeader->size = 0;
    stackHeader->isFull = false;
    p = &stackHeader->elements[0];
    do {
        p->reset();
        p++;
    } while (p < &stackHeader->elements[8]);

    *(void**)(base + 0xD0) = self;
    *(void**)(base + 0xC0) = lbl_27_data_46658;
    stack = (soArrayVector<acCmdInterpreterStackData, 8>*)(base + 0x14);
    *(void**)((char*)stack + 0xC0) = lbl_27_bss_D8C;
    *(void**)(base + 0xD8) = lbl_27_bss_D8C;

    result = 0;
    resetMode = result;
    ctx = *(char**)((char*)arg1 + 0xD8);
    obj = *(char**)(ctx + 0x80);
    evt = ((Object_vptr_0*)(obj + 8))->slot7();

    interpreter = (acCmdInterpreter*)(base + 0xDC);
    new (interpreter) acCmdInterpreter(stack, 1, 0, &resetMode, farg0);

    *(void**)((char*)interpreter + 0x34) = lbl_27_data_466B8;
    *(s16*)((char*)interpreter + 0x38) = evt;
    *(s16*)((char*)interpreter + 0x3A) = 5;
    *(s32*)((char*)interpreter + 0x3C) = result;
    eid = evt;

    if (eid > 0 && eid > -1) {
        if (((SystemVTable*)getInstance__13soEventSystemFv())->check(eid) != 0) {
            manager = (ManagerVTable*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), *(s16*)((char*)interpreter + 0x38));
            if (manager->check(*(s16*)((char*)interpreter + 0x3A)) == 0) {
                *(s32*)((char*)interpreter + 0x3C) = result;
            } else {
                temp = *(s16*)((char*)interpreter + 0x3A);
                manager2 = (ManagerVTable*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((char*)interpreter + 0x38));
                if (manager2->check(temp) == 0) {
                    result = 0;
                } else {
                    unit = (UnitVTable*)__dynamic_cast(
                        manager2->get(temp), 0, lbl_27_data_128,
                        __RTTI__11soEventUnit, 0);
                    if (unit == 0)
                        result = 0;
                    else
                        result = unit->result();
                }
                *(s32*)((char*)interpreter + 0x3C) = result;
            }
        }
    }

    *(void**)interpreter = lbl_27_data_81A0;
    *(void**)((char*)interpreter + 0x34) = lbl_27_data_81A0 + 0x20;
    *(s32*)((char*)interpreter + 0x40) = 7;
    *(s32*)((char*)interpreter + 0x44) = 0;
    *(s32*)((char*)interpreter + 0x48) = 0;
    *(s32*)((char*)interpreter + 0x4C) = 0;

    blk.capacity = 0x80;
    blk.ranges[0] = base + 0xDC;
    blk.ranges[1] = base + 0xC0;
    ((Object_vptr_0*)*(void**)(*(char**)((char*)arg1 + 0xD8) + 0x6C))
        ->slot1(blk.ranges, &blk.capacity);

    return self;
}
