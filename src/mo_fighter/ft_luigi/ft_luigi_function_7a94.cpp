#pragma force_active on
extern "C" {
void* fn_27_197E94(void* self, unsigned int a, unsigned int b);
void* fn_27_14DFE4(void* p, unsigned int a2, unsigned int a3, void* a4, void* a5, void* a6, void* a7, void* a8, unsigned int a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, int v);
void fn_27_CAF4C(void* p, int v);
}

extern "C" void* fn_99_7A94(void* self, unsigned int a2, unsigned char a3, unsigned int a4) {
    char* s = static_cast<char*>(self);
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(s + 0x10, a2, a3, s + 0x220, s + 0x94, s + 0x78, self, reinterpret_cast<void*>(a4), 8);
    fn_27_A78C0(s + 0x78);
    fn_27_1991F0(s + 0x94, 0);
    fn_27_CAF4C(s + 0x220, 0);
    return self;
}
