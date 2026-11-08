#include <it/it_manager.h>
#pragma force_active on

struct Cfg {
    float probability;
    int limit;
};

struct Ret {
    char pad[0x34];
    Cfg* cfg;
};

class Object_vptr_0 {
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
    virtual int slot16();
};

class Work {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
};

class Posture {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};

struct Modules {
    char pad0[0x0c];
    Posture* posture;
    char pad10[0x54];
    Work* work;
    char pad68[8];
    Object_vptr_0* status;
};

struct Object {
    char pad0[8];
    void* task;
    char pad0c[0xcc];
    Modules* modules;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
Ret* fn_27_3683E8(void*);
float randf__Fv();
int fn_27_2A83B8(itManager*, int, int, int, int);
void fn_27_28E48C(BaseItem*, Vec3f*, float);
}

extern char lbl_27_data_91BC0[];
extern char lbl_27_data_248[];
extern const float lbl_27_rodata_7B18;

extern "C" void fn_27_3684DC(void*, Object* object) {
    void* task = __dynamic_cast(
        object->task, 0x3c, lbl_27_data_91BC0, lbl_27_data_248, 1);

    switch (object->modules->status->slot16()) {
    case 1: {
        float probability = fn_27_3683E8(task)->cfg->probability;
        if (randf__Fv() < probability) {
            int owner = object->modules->work->slot4(0x10000000);
            int count = itManager::getInstance()->getItemNum(
                (itKind)0x58, 0, owner, -1);
            int allowed = 1;

            if (count >= fn_27_3683E8(task)->cfg->limit) {
                owner = object->modules->work->slot4(0x10000000);
                allowed = fn_27_2A83B8(
                    itManager::getInstance(), 0x58, 0, owner, -1);
            }

            if (allowed) {
                Vec3f position = object->modules->posture->slot4();
                Vec3f zero;
                zero.m_x = lbl_27_rodata_7B18;
                zero.m_y = lbl_27_rodata_7B18;
                zero.m_z = lbl_27_rodata_7B18;

                Posture* posture = object->modules->posture;
                int owner3 = object->modules->work->slot4(0x10000000);
                float lr = posture->slot9();
                BaseItem* item = itManager::getInstance()->createItem(
                    &position, lr, (itKind)0x58, 0, owner3, 0, 0,
                    0xffff, 0, 0xffff);

                if (item) {
                    float direction = object->modules->posture->slot9();
                    fn_27_28E48C(item, &zero, direction);
                }
            }
        }
        break;
    }
    }
}
