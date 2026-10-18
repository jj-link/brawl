#pragma force_active on
extern "C" {
void fn_113_23FA4(void*);
void fn_113_25530(void*);

void fn_113_C394(void* object) {
    char* base = (char*)object;
    fn_113_23FA4(base + 0x20000 - 0x2F8);
    fn_113_25530(base + 0x20000 - 0x2F8);
}
}
