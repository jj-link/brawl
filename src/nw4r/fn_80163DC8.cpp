#pragma force_active on

struct Obj {
    unsigned char pad0[0xC];
    int state;
    int field10;
    unsigned char pad1[0x8];
    virtual void f8();
    virtual void fC(unsigned int);
};

struct Actor {
    unsigned char pad[0x3C];
    unsigned short counter;
};

extern "C" int fn_80163DC8(Actor* self, Obj* obj) {
    if (obj->state != 1) {
        return 0;
    }
    unsigned short temp = self->counter;
    self->counter = temp - 1;
    obj->fC(temp);
    obj->state = 2;
    if (obj->field10 == 0) {
        obj->f8();
    }
    return 1;
}
