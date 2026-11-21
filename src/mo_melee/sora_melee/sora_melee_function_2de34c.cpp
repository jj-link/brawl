#pragma force_active on
#include <types.h>

struct Vec3f {
    float x, y, z;
};

class soModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(u32);
    virtual void slot5(int, u32);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int slot11(u32, u32, Vec3f*, Vec3f*, s32, s32, s32, float, s32);
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(u32);
    virtual void slot18(u32);
    virtual void slot19(u32);
    virtual void slot20(int);
    virtual void slot21(int);
    virtual void slot22(s32);
    virtual void slot23(s32);
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
    virtual void slot38(s32, float);
    virtual void slot39(s32);
};

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
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
    virtual void slot38();
    virtual void slot39();
    virtual int slot40();
};

struct Mid {
    char pad[0x64];
    soModule* work;     // 0x64
    char pad2[0x20];
    soModule* stop;     // 0x88
};

struct Accesser {
    char pad_0[0x08];
    gfTask* owner;      // 0x08
    char pad_0c[0xcc];
    Mid* mid;           // 0xd8
};

extern "C" int fn_27_1922CC(void*, u32);
extern "C" const float lbl_27_rodata_6390[];

extern "C" void fn_27_2DE34C(void*, Accesser* accesser) {
    const float* k = lbl_27_rodata_6390;
    soModule* work = accesser->mid->work;
    int limit = fn_27_1922CC(accesser, 0x5dc0);
    int timer = work->slot4(0x10000040);
    int state = work->slot17(0x1200003d);

    if (timer >= limit && state == 0) {
        int r;
        if (accesser->owner->slot40() == 5) {
            Vec3f a, b;
            b.x = k[0]; b.y = k[0]; b.z = k[0];
            a.x = k[0]; a.y = k[1]; a.z = k[0];
            r = accesser->mid->stop->slot11(0x1060003, 0x190, &a, &b, 0, 0, 0, k[2], -1);
        } else {
            Vec3f a, b;
            b.x = k[0]; b.y = k[0]; b.z = k[0];
            a.x = k[0]; a.y = k[0]; a.z = k[0];
            r = accesser->mid->stop->slot11(0x20004, 0x22, &a, &b, 0, 0, 0, k[2], -1);
        }
        work->slot5(r, 0x10000041);
        work->slot18(0x1200003d);
        accesser->mid->stop->slot38(0x1a, k[0]);
    }
    if (timer < limit && state != 0) {
        int t = work->slot4(0x10000041);
        accesser->mid->stop->slot20(t);
        work->slot5(0, 0x10000041);
        work->slot19(0x1200003d);
        accesser->mid->stop->slot39(0x1a);
    }
}
