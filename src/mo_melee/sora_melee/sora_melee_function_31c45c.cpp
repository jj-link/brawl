#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
    virtual void slot5(int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(int, int);
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual unsigned long long slot13(short*);
    virtual int slot14(int, int);
    virtual void slot15();
    virtual int slot16();
    virtual int slot17(int);
    virtual void slot18();
    virtual void slot19();
    virtual void slot20(bool, int);
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
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43(float);
};
class Work {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(int); virtual void slot5(int, int);
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual int slot17(int);
 virtual void slot18(); virtual void slot19(); virtual void slot20(bool, int);
};
struct Params { char pad[0x24]; float threshold, scale, vertical; };
struct Owner { char pad[0x4870]; Params* params; };
struct Modules {
    char pad0[0xc]; Object_vptr_0* posture;
    char pad10[0xc]; Object_vptr_0* motion;
    char pad20[0x44]; Work* work;
    char pad68[8]; Object_vptr_0* status;
    char pad74[8]; Object_vptr_0* control;
};
struct Accesser { char pad0[8]; void* owner; char padc[0xcc]; Modules* modules; };
union Pair { unsigned long long bits; struct { float x, y; } v; };
extern "C" {
extern char lbl_27_data_48E80[];
extern char lbl_27_data_248[];
extern float lbl_27_rodata_74F0[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_31C45C(void*, Accesser* a) {
    Params* params = ((Owner*)__dynamic_cast(a->owner, 0x3c, lbl_27_data_48E80, lbl_27_data_248, 1))->params;
    int k;
    int j;
    int index;
    Object_vptr_0* motion = a->modules->motion;
    Work* work = a->modules->work;
    Object_vptr_0* control = a->modules->control;
    short id = -1;
    Pair p;
    Pair raw;
    raw.bits = control->slot13(&id);
    p = raw;
    int status = a->modules->status->slot16();
    if ((status == 0 || status == 1 || (unsigned)(status - 3) <= 3) && !work->slot17(0x22000000)) {
        int i;
        bool any = false;
        int count = 0;
        for (i = 0; i < 4; ++i) {
            if (motion->slot14(i, 0)) {
                motion->slot5(i);
                any = true;
                ++count;
            }
        }
        work->slot20(any, 0x22000000);
        work->slot5(count, 0x20000003);
    }
    if (work->slot17(0x22000000)) {
        int count = work->slot4(0x20000003);
        if (status == 1) {
            float x = nw4r::ut::Abs(p.v.x);
            if (x < params->threshold) {
                if (motion->slot14(0, 0)) motion->slot5(0);
                if (motion->slot14(1, 0)) motion->slot5(1);
            } else {
                motion->slot43(params->scale * x);
                if (p.v.x * a->modules->posture->slot9() > lbl_27_rodata_74F0[0]) {
                    if (!motion->slot14(0, 0)) motion->slot8(0, 0);
                } else {
                    if (!motion->slot14(1, 0)) motion->slot8(1, 0);
                }
            }
            for (index = 2; index < count; ++index) {
                if (!motion->slot14(index, 0)) motion->slot8(index, 0);
            }
        } else if (status == 3 || status == 4 || status == 6) {
            if (p.v.y > -params->vertical) {
                for (j = 0; j < count; ++j) {
                    if (motion->slot14(j, 0)) motion->slot5(j);
                }
            } else {
                for (k = 0; k < count; ++k) {
                    if (!motion->slot14(k, 0)) motion->slot8(k, 0);
                }
            }
        }
    }
}
}