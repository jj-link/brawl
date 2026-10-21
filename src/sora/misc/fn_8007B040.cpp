#pragma force_active on
extern "C" void fn_803EF188(void*);

struct Obj {
    char pad0[0x54];
    void* m54;
    unsigned char m58;
};

extern "C" void fn_8007B040(Obj* self) {
    if (self->m58 == 0) {
        return;
    }
    fn_803EF188(self->m54);
}
