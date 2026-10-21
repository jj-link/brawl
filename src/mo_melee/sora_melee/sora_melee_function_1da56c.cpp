#pragma force_active on
struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void invoke();
};

struct Level2 {
    unsigned char pad[0x58];
    Target* target;
};

struct Level1 {
    unsigned char pad[0xD8];
    Level2* next;
};

struct Object {
    unsigned char pad[0x60];
    Level1* next;
};

extern "C" void fn_27_1DA56C(Object* self) {
    self->next->next->target->invoke();
}
