#pragma force_active on
extern "C" {
void* fn_8007EF70(void*, int, int, int, int);
}

struct SoraMenuObj {
    char pad[0x40];
    void* m40;
    void* m44;
};

extern "C" void fn_2_24D20(SoraMenuObj* self) {
    self->m44 = fn_8007EF70(self->m40, 0, 0, -1, -1);
}
