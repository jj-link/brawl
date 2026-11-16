#include <types.h>
#pragma force_active on

struct Value {
    int tag;
    int value;
};

struct Ref {
    Value* p;
    bool flag;

    Ref(Value* q) : p(q), flag(false) {}

    int get() const {
        return flag == 1 ? 0 : p->value;
    }
};

inline int getValue(Ref ref) {
    return ref.get();
}

struct Holder {
    virtual void v0();
    virtual void v1();
    virtual Value* get(u32);
    int data[3];
};

inline Ref getRef(Holder& h) {
    return Ref(h.get(0));
}

class Obj {
public:
    virtual void v0();
    virtual signed char kind();
    virtual signed char mode();
    virtual void v3();
    virtual void v4();
    virtual Holder fetch();
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(u8);
    virtual void v8(bool);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual int valid(signed char);
    unsigned char pad[0x34];
    unsigned char m38;
};

extern "C" int fn_27_A8E94(Self* self, Obj* arg) {
    if (self->valid(arg->kind()) == 0) {
        return 0;
    }
    signed char mode = arg->mode();
    arg->v3();
    if (mode <= -1 || mode >= 2) {
        return 0;
    }
    switch (mode) {
    case 0:
        self->v7(self->m38);
        return 1;
    case 1: {
        Holder h = arg->fetch();
        self->v8(getValue(getRef(h)) != 0);
        return 1;
    }
    }
    return 0;
}
