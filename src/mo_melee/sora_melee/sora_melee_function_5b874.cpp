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
};

struct Input {
    virtual void slot0();
    virtual s8 group();
    virtual s8 mode();
    virtual void slot3();
    virtual void slot4();
    virtual Args args();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int, int);
    virtual void slot3(int, int, int);
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
    virtual int slot16(s8);
    char pad[0x20];
    s8* data24;
};

extern "C" int fn_27_5B050(Object_vptr_0*, Input*, int, int);

extern "C" int fn_27_5B874(Object_vptr_0* self, Input* in, int arg2, int arg3) {
    if (!self->slot16(in->group())) {
        return 0;
    }
    if (in->mode() <= -1 || in->mode() >= 4) {
        return 0;
    }
    switch (in->mode()) {
    case 0: {
        Args args = in->args();
        const Ref& first = args.get(0);
        args.shift();
        const Ref& second = args.get(0);
        int firstValue = first.valueOrZero();
        self->slot2(firstValue, second.valueOrZero());
        return 1;
    }
    case 1: {
        Args args = in->args();
        const Ref& first = args.get(0);
        args.shift();
        const Ref& second = args.get(0);
        int firstValue = first.valueOrZero();
        self->slot3(firstValue, second.valueOrZero(), 1);
        return 1;
    }
    case 3: {
        Args args = in->args();
        const Ref& first = args.get(0);
        int v = first.valueOrZero();
        self->slot2(v, self->data24[v * 3]);
        return 1;
    }
    default:
        return fn_27_5B050(self, in, arg2, arg3);
    }
}
