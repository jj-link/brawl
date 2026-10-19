#pragma force_active on
struct Fn27Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
};

struct Fn27Holder {
    unsigned char pad[8];
    Fn27Object* object;
};

extern "C" void fn_27_10FC1C(Fn27Holder* self) {
    self->object->unused2();
    self->object = reinterpret_cast<Fn27Object*>(
        reinterpret_cast<char*>(self) + 4);
}
