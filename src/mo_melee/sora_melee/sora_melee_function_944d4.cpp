#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" void OSReport(const char*, ...);
extern "C" char lbl_27_data_142DC[];
extern "C" char lbl_27_data_90D0[];

struct Target {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void reset();
    virtual void f20();
    virtual s16 getKey();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void apply(s32);
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50();
    virtual void f54();
    virtual void f58();
    virtual void f5c();
    virtual void f60();
    virtual void f64();
    virtual void f68();
    virtual void f6c();
    virtual void f70(s32);
    virtual u32 test();
};

struct ListInterface {
    virtual void unused();
    virtual Target** at(s32);
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void applyAll(s32);
};

struct List {
    void* vtable;
    void* secondary;
    u32 flags;
    char storage[96];
};

struct Entry {
    char pad0[4];
    s16 key;
    s16 f6;
    s16 f8;
};

class EntryList {
public:
    virtual void unused();
    virtual Entry* at(s32);
    virtual void f10();
    virtual s32 count();
};

class Class_14370 {
public:
    virtual void fn_27_93100();
    virtual void fn_27_9329C();
    virtual void fn_27_932A0();
    virtual void fn_27_93778();
    virtual void fn_27_95264();
    virtual void fn_27_93860();
    virtual void fn_27_94198();
    virtual void fn_27_942B4();
    virtual void fn_27_943C4();
    virtual void fn_27_944D4();
    virtual void fn_27_94748();
    virtual void fn_27_9483C();
    virtual void fn_27_94930();
    virtual void fn_27_94E00();
    virtual void fn_27_94C38();
    virtual void fn_27_93B80();
    virtual void fn_27_93F8C();
    virtual void fn_27_94A40();
    virtual s32 fn_27_94000();
    virtual void fn_27_940C8();
    virtual void fn_27_96C50();
    virtual void fn_27_96CEC();
    virtual void fn_27_96D0C();
    virtual void fn_27_96D20();
    virtual void fn_27_96D8C();
    virtual void fn_27_96E6C();
    virtual void fn_27_96F58(List*, s32, s32);
    virtual void fn_27_973EC();

    char pad4[0x28];
    ListInterface* unk2C;
    char pad30[4];
    EntryList* unk34;
};

extern "C" void fn_27_944D4(Class_14370* self, s32 arg1, s32 arg2, s32 arg3) {
    List list;
    s32 j;
    Target* t25;
    s16 key;
    s32 i;
    Target* t22;

    if (self->fn_27_94000() == 0) {
        OSReport(lbl_27_data_142DC);
        return;
    }
    list.vtable = lbl_27_data_90D0;
    list.secondary = lbl_27_data_90D0 + 0x48;
    list.flags &= 0x1fff;
    self->fn_27_96F58(&list, arg1, arg3);

    for (i = 0; i < (s32)((list.flags << 12) & 0xfe000000) >> 26; i++) {
        if ((*((ListInterface*)&list)->at(i))->test() == 1) {
            t22 = *self->unk2C->at(i);
            t25 = *self->unk2C->at(i);
            s32 count = self->unk34->count();
            for (j = 0; j < count; j++) {
                s16 id = t25->getKey();
                Entry* e = self->unk34->at(j);
                if (id != -1) {
                    key = e->key;
                    if (id == key) {
                        if (soEventSystem::getInstance()->getInstanceManager().isContain(key) == 1) {
                            soEventSystem::getInstance()->getManager(e->key)->eraseObserver(e->f6, e->f8);
                        }
                        e->f8 = -1;
                        e->key = -1;
                    }
                }
            }
            self->unk2C->applyAll(i);
            t25->f70(1);
            t22->reset();
        } else {
            Target* t = *((ListInterface*)&list)->at(i);
            t->apply(arg2);
        }
    }
}
