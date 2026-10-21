#pragma force_active on
struct Target {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
};

struct Object {
    unsigned char padding[0x14];
    Target* target;
};

extern "C" void fn_27_871D4(Object* self) {
    self->target->slot28();
}
