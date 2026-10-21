#pragma force_active on
extern "C" void fn_801C4DD0(char* self, int a, int b) {
    *(int*)(self + 0x50) = a;
    *(int*)(self + 0x54) = a + b;
}
