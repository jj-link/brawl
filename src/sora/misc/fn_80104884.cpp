#pragma force_active on

struct Inner {
    char pad[0x10];
    void* field_10;
};

struct Outer {
    char pad[0x18];
    Inner* field_18;
};

extern "C" void fn_8019D950(void*);

extern "C" void fn_80104884(Outer* self) {
    fn_8019D950(self->field_18->field_10);
}
