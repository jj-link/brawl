#pragma force_active on
struct Container {
    char pad[0x58];
    int state;
};

extern "C" int fn_27_26854(Container* self);

extern "C" int fn_41_2B84C(Container* self) {
    if (self->state != 0) {
        return 1;
    }
    return fn_27_26854(self);
}