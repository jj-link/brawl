#pragma force_active on
extern "C" void fn_27_57FC8(void*);
extern "C" void fn_27_561E0(void*, void*, void*, unsigned int, int, int, void*);

extern "C" {
void* fn_27_2DB024(void* a, void* b, unsigned int c, void* d) {
    fn_27_57FC8(a);
    fn_27_561E0((char*)a + 0xc, b, a, c, 1, 0, d);
    return a;
}
}
