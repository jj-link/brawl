#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off

struct MotionArgs {
    int kind;
    float frame;
    float rate;
    bool a, b, c, d;
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
    virtual float slot12(int);
    virtual void slot13();
    virtual void slot14(int);
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
    virtual void slot35(float);
    virtual void slot36();
    virtual int slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
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
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106(MotionArgs*);
};

struct Modules {
    char pad[8];
    Object_vptr_0* motion;
    char pad2[0x58];
    Object_vptr_0* work;
};
struct Owner {
    char pad[0xd8];
    Modules* modules;
};
extern "C" {
extern const float lbl_27_rodata_1FF0[];
void fn_27_164BF0(Owner* self, int* kinds, int value, int multiplier, float scale) {
    const float* k = lbl_27_rodata_1FF0;
    float rate;
    float speed = (float)(double)nw4r::math::FAbs(self->modules->work->slot12(value));
    Object_vptr_0* motion = self->modules->motion;
    int kind;
    if (speed >= k[2] * scale)
        kind = kinds[0];
    else if (speed >= k[3] * scale)
        kind = kinds[1];
    else
        kind = kinds[2];
    if (kind == kinds[2])
        rate = speed / (k[4] * scale);
    else if (kind == kinds[1])
        rate = speed / (k[3] * (k[3] * scale + k[2] * scale));
    else
        rate = speed / scale;
    rate *= self->modules->work->slot12(multiplier);
    float max = soValueAccesser::getConstantFloat((soModuleAccesser*)self, 0xc30, 0);
    if (rate > max)
        rate = max;
    float frame = k[7];
    motion->slot14(kind);
    MotionArgs args;
    args.kind = kind;
    args.frame = frame;
    args.rate = rate;
    args.a = false;
    args.b = false;
    args.c = false;
    args.d = false;
    motion->slot106(&args);
    int current = motion->slot37();
    if (current == kinds[2])
        rate = speed / k[4];
    else if (current == kinds[1])
        rate = speed / k[5];
    else
        rate = speed / k[6];
    rate *= self->modules->work->slot12(0x21000005);
    max = soValueAccesser::getConstantFloat((soModuleAccesser*)self, 0xc30, 0);
    if (rate > max)
        rate = max;
    motion->slot35(rate);
}
}