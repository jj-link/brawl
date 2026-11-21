#include <types.h>
#include <gf/gf_task_scheduler.h>

#pragma force_active on

extern "C" {
extern const f32 lbl_27_rodata_82C;
extern const char lbl_27_data_248[];
extern const char __RTTI__6gfTask[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
void* fn_27_8CD44(void*);
int fn_27_8CB9C(void*);
void fn_27_60600(void*, void*, void*, void*);
void fn_27_60824(void*, void*, void*);
}

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Words3 {
    u32 x;
    struct {
        u32 y;
        u32 z;
    } yz;
};

class TaskList {
public:
    virtual void slot0();
    virtual void* getAt(int);
    virtual void slot2();
    virtual int getCount();
};

class Module {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
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
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual Vec3 slot38(u8, u8);
    virtual void slot39();
    virtual u64 slot40();
    virtual void slot41();
    virtual void* slot42(u8, u8);
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62(u32, u32);
    virtual u32 slot63();
    virtual u32 slot64();
};

struct Self {
    char pad0[0x3c];
    void* obj3c;
    TaskList* list;
    char pad44[0x20];
    char out[0x3c];
    u32 a0;
    u32 a4;
    char padA8;
    u8 enabled;
};

struct Entry {
    char pad0[8];
    f32 f8;
    f32 fC;
    char pad10[0xc];
    u32 id;
    char pad20[0x12];
    u8 category;
    char pad33;
    u8 arg34;
    char pad35[2];
    u8 arg37;
    char rest[0x60];
    u32 result98;
};

extern "C" void fn_27_5CFB8(Self* self) {
    if (self->enabled == 1)
        return;

    int count = self->list->getCount();
    f32 threshold = lbl_27_rodata_82C;

    void* owner;
    int i = 0;
    while (i < count) {
        void* related;
        Entry* e = (Entry*)self->list->getAt(i);

        if (e->fC > threshold || e->f8 > threshold) {
            void* t = gfTaskScheduler::getInstance()->getTaskById(
                (gfTask::Category)e->category, e->id);
            void* holder = *(void**)((char*)self->obj3c + 8);
            owner = *(void**)((char*)holder + 0x28);
            void* task = __dynamic_cast(
                t, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 1);

            Module* module = (Module*)fn_27_8CD44(task);
            void* vals = module->slot42(e->arg34, e->arg37);

            *(Words3*)((char*)e + 0x3c) = *(Words3*)vals;
            *(u32*)((char*)e + 0x48) = *(u32*)((char*)vals + 12);
            *(f32*)((char*)e + 0x4c) = *(f32*)((char*)vals + 16);
            *(u32*)((char*)e + 0x50) = *(u32*)((char*)vals + 20);
            *(u32*)((char*)e + 0x54) = *(u32*)((char*)vals + 24);
            *(u32*)((char*)e + 0x58) = *(u32*)((char*)vals + 28);
            *(u32*)((char*)e + 0x5c) = *(u32*)((char*)vals + 32);
            *(f32*)((char*)e + 0x60) = *(f32*)((char*)vals + 36);
            *(f32*)((char*)e + 0x64) = *(f32*)((char*)vals + 40);
            *(f32*)((char*)e + 0x68) = *(f32*)((char*)vals + 44);
            *(u32*)((char*)e + 0x6c) = *(u32*)((char*)vals + 48);
            *(u32*)((char*)e + 0x70) = *(u32*)((char*)vals + 52);
            *(u32*)((char*)e + 0x74) = *(u32*)((char*)vals + 56);
            *(u32*)((char*)e + 0x78) = *(u32*)((char*)vals + 60);

            *(Vec3*)((char*)e + 0x80) =
                module->slot38(e->arg34, e->arg37);

            u64 pair = module->slot40();
            *(f32*)((char*)e + 0x8c) = *(f32*)&pair;
            *(f32*)((char*)e + 0x90) = *((f32*)&pair + 1);

            u32 id = module->slot63();
            if (id != 0xffffffffU) {
                id = module->slot63();
                related = gfTaskScheduler::getInstance()->getTask(id);

                if (related) {
                    void* target = __dynamic_cast(
                        related, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 1);
                    fn_27_60600(self->out, owner, task, target);
                    self->a0 = module->slot63();
                    self->a4 = module->slot64();

                    void* a = *(void**)((char*)self->obj3c + 0xd8);
                    a = *(void**)((char*)a + 0x1c);
                    ((Module*)a)->slot62(self->a0, self->a4);

                    e->result98 = fn_27_8CB9C(
                        __dynamic_cast(related, 0x3c, lbl_27_data_248,
                                       __RTTI__6gfTask, 1));
                    return;
                }

                fn_27_60824(self->out, owner, task);
            } else {
                fn_27_60824(self->out, owner, task);
            }

            e->result98 = fn_27_8CB9C(task);
        }
        ++i;
    }
}
