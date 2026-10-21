#pragma force_active on
extern "C" {
void* fn_27_197E94(void* self, unsigned int mode, unsigned int sub);
void* fn_27_14DFE4(void* p, unsigned int a2, unsigned int a3, void* a4, void* a5, void* a6, void* a7, unsigned int a8, unsigned int a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, unsigned int v);
void* fn_27_CA34C(void* self, unsigned int v);
}

extern "C" void* fn_117_861C(void* self, unsigned int a2, unsigned int a3, void* a4) {
    fn_27_197E94(self, 1, 0);
    unsigned char* base = static_cast<unsigned char*>(self);
    fn_27_14DFE4(base + 0x10, a2, (unsigned char)a3, base + 0x220, base + 0x94, base + 0x78, self, (unsigned int)a4, 8);
    fn_27_A78C0(base + 0x78);
    fn_27_1991F0(base + 0x94, 0);
    fn_27_CA34C(base + 0x220, 0);
    return self;
}
