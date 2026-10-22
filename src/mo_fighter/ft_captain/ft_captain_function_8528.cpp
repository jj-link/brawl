#pragma force_active on
extern "C" {
void* fn_27_197E94(void* self, unsigned a2, unsigned a3);
void* fn_27_14DFE4(void* p, unsigned a2, unsigned a3, void* a4, void* a5, void* a6, void* a7, unsigned a8, unsigned a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, unsigned a2);
void* fn_27_CAF4C(char* self, unsigned a2);
}

extern "C" void* fn_100_8528(void* self, unsigned arg2, unsigned arg3, unsigned arg4) {
    fn_27_197E94(self, 1, 0);
    char* p = (char*)self;
    fn_27_14DFE4(p + 0x10, arg2, (unsigned char)arg3, p + 0x220, p + 0x94, p + 0x78, self, arg4, 8);
    fn_27_A78C0(p + 0x78);
    fn_27_1991F0(p + 0x94, 0);
    fn_27_CAF4C(p + 0x220, 0);
    return self;
}
