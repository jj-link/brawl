#pragma force_active on
#include <types.h>

struct Value { int tag; int value; };

struct Ref {
    Value* p;
    u8 null;
    Ref(Value* v) : p(v), null(0) {}
    int valueOrZero() const { return null == 1 ? 0 : p->value; }
};

struct Args {
    virtual void slot0();
    virtual void slot1();
    virtual Value* at(int) const;
    virtual void slot3();
    virtual int isNull() const;
    virtual void slot5();
    virtual void advance();
    int data[3];
    Ref get(int index) const { return Ref(at(index)); }
    void shift() { advance(); }
    int size() const { return isNull(); }
};

struct Input {
    virtual void slot0();
    virtual s8 group();
    virtual s8 mode();
    virtual void slot3();
    virtual void slot4();
    virtual Args args();
    virtual void result(Ref*, int);
};

struct AnimationBase { char pad[8]; };
struct Animation : AnimationBase {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57(); virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61();
    virtual void update(void*, float);
};

struct Modules { char pad[0x9c]; Animation* animation; };
struct ModuleOwner { char pad[0xd8]; Modules* modules; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int, int, int);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int);
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
    virtual int slot18(s8);
    char pad[0x18];
    ModuleOwner* owner;
    void* data20;
    void* data24;
};

struct Object_vptr_88_base { char pad[0x88]; };
class Object_vptr_88 : public Object_vptr_88_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6();
};

extern "C" const float lbl_27_rodata_D78;
extern "C" const float lbl_27_rodata_DA0;

extern "C" int fn_27_ADF30(Object_vptr_0* self, Input* in) {
    if (!self->slot18(in->group())) {
        return 0;
    }
    if (in->mode() <= -1 || in->mode() >= 4) {
        return 0;
    }
    switch (in->mode()) {
    case 0: {
        Ref value(0);
        in->result(&value, 0);
        self->slot2(value.valueOrZero(), 0, 0);
        return 1;
    }
    case 1: {
        int flag;
        Args args = in->args();
        const Ref& first = args.get(0);
        args.shift();
        const Ref& second = args.get(0);
        args.shift();
        flag = 0;
        if (args.size() == 0) {
            flag = 1;
        }
        int firstValue = first.valueOrZero();
        self->slot2(firstValue, second.valueOrZero(), flag);
        return 1;
    }
    case 2: {
        Ref value(0);
        in->result(&value, 0);
        self->slot6(value.null == 1 ? 0 : value.p->value != 0);
        return 1;
    }
    case 3: {
        float value;
        Args args = in->args();
        const Ref& first = args.get(0);
        args.shift();
        const Ref& second = args.get(0);
        int flags = first.valueOrZero();
        value = second.null == 1
            ? lbl_27_rodata_D78
            : (float)second.p->value / lbl_27_rodata_DA0;
        if (flags & 2) {
            self->owner->modules->animation->update(self->data20, value);
        }
        if (flags & 4) {
            self->owner->modules->animation->update(self->data24, value);
        }
        return 1;
    }
    }
    return 0;
}
