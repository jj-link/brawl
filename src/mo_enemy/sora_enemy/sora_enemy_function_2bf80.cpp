#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" char lbl_41_data_3DD8[];

struct Object {
    char pad[0x24];
    virtual void unused();
    virtual void callback();
};

extern "C" Object* fn_41_2BF80(Object* self, int flag) {
    if (self) {
        *(void**)((char*)self + 0x24) = lbl_41_data_3DD8;
        self->callback();
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
