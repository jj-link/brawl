#pragma force_active on
struct Query {
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
    virtual int get();
};

struct Modules {
    char pad[0x70];
    Query* query;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Owner* owner;
};

extern "C" int fn_27_1DAF80(void*, void*);

extern "C" int fn_27_2F2224(Object* self, void* arg) {
    switch (self->owner->modules->query->get()) {
    case 0:
    case 1:
        return 0;
    default:
        return fn_27_1DAF80(self, arg);
    }
}
