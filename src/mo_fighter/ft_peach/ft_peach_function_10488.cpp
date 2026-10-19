#include <types.h>
#pragma force_active on

struct Ft10488Object {
    char pad[0x58];
    u8 flag58;
};

struct Ft10488Record {
    char pad[0x28];
    u8 flag : 1;
};

struct Ft10488Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual u32 slot4(u32 arg);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(u32 arg);
};

struct Ft10488Modules {
    char pad[0x64];
    Ft10488Interface* iface;
};

struct Ft10488Fighter {
    char pad[0xd8];
    Ft10488Modules* modules;
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void* scheduler, int category, u32 id);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
void fn_103_10CF4(void* self, s32 index);
extern void* g_GameGlobal;
extern char lbl_103_data_28[];
extern char lbl_103_data_23A0[];

void fn_103_10488(void* unused, Ft10488Fighter* self) {
    self->modules->iface->slot19(0x22000011);
    u32 id = self->modules->iface->slot4(0x10000041);
    if (id != 0) {
        void* task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(), 0x12, id);
        if (task != 0) {
            Ft10488Object* object = (Ft10488Object*)__dynamic_cast(task, 0x3c, lbl_103_data_28, lbl_103_data_23A0, 0);
            if (object != 0 && object->flag58 == 0) {
                Ft10488Record* record = (Ft10488Record*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
                if (record->flag == 1) {
                    fn_103_10CF4(object, 3);
                } else {
                    fn_103_10CF4(object, 1);
                }
                object->flag58 = 1;
            }
        }
    }
}
}
