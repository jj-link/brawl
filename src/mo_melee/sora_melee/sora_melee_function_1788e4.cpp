#pragma force_active on
extern "C" void fn_27_1744D4(void* a, void* b);
extern "C" void fn_27_174C08(void* a, void* b, void* c);

extern "C" void fn_27_1788E4(void* a, void* b) {
    fn_27_1744D4(a, b);
    unsigned int local[8];
    local[0] = 0x27;
    local[1] = 0;
    fn_27_174C08(a, local, b);
}
