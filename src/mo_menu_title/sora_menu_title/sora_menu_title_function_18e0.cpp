#pragma force_active on
extern "C" void fn_8007F148(void*);
extern "C" void fn_8007EF70(void*, int, int, int, int);

struct SoraMenuTitleObj {
    char pad[0x54];
    void* manager;
};

extern "C" void fn_24_18E0(SoraMenuTitleObj* self) {
    fn_8007F148(self->manager);
    fn_8007EF70(self->manager, 0, 0, -1, -1);
}
