#pragma force_active on
extern "C" void fn_803127A8(void* a, void* p);

struct Obj {
    unsigned char pad[0x70];
    char* base;
};

extern "C" void fn_8030D758(Obj* self, unsigned int* idx)
{
    fn_803127A8(self, self->base + (*idx << 4));
}
