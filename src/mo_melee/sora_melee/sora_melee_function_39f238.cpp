#pragma force_active on
class State {
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
    virtual int getKind();
};

struct Modules {
    char padding[0x70];
    State* state;
};

struct Access {
    char padding[0xD8];
    Modules* modules;
};

struct Object {
    char padding[0x60];
    Access* access;
};

extern "C" int fn_27_1DAF80(Object*, void*);

extern "C" int fn_27_39F238(Object* self, void* arg) {
    State* state = self->access->modules->state;
    switch (state->getKind()) {
    case 0:
    case 1:
        return 0;
    default:
        return fn_27_1DAF80(self, arg);
    }
}
