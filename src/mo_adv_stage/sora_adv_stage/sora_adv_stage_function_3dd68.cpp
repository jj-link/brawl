#pragma force_active on
extern "C" void fn_8007F148(void*);

struct Obj {
    int pad0[16];
    int state;
    int pad1;
    void* manager;
};

extern "C" int fn_40_3DD68(Obj* self) {
    if (self->manager != 0 && self->state == 6) {
        fn_8007F148(self->manager);
        self->state = 7;
        return 1;
    }
    return 0;
}
