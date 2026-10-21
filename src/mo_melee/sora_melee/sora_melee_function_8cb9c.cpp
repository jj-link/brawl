#pragma force_active on
typedef unsigned int u32;

struct Modules;

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual u32 get(Modules*);
};
struct Holder {
    char pad[0x18];
    Object* object;
};
struct Modules {
    char pad[0xD8];
    Holder* holder;
};
struct State {
    char pad0[0x28];
    u32 fallback;
    char pad1[0x34];
    Modules* modules;
};

extern "C" u32 fn_27_8CB9C(const State* self) {
    u32 result = self->modules->holder->object->get(self->modules);
    if ((u32)(result + 0x10000) != 0xFFFF) {
        return result;
    }
    return self->fallback;
}
