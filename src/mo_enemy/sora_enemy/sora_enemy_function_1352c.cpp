#pragma force_active on
struct Fn41Object {
    virtual void fn0();
    virtual void* fn1();
};

struct Fn41Self {
    char padding[0x40];
    Fn41Object* object;
};

extern "C" float fn_41_1352C(Fn41Self* self) {
    return *reinterpret_cast<float*>(
        static_cast<char*>(self->object->fn1()) + 8
    );
}
