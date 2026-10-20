#pragma force_active on
extern "C" void fn_1_8E0C(char* self, int a, int b) {
    char* p = *(char**)(*(char**)(self + 0x35c) + 0x8);
    *(int*)(p + 0x40) = a;
    *(int*)(p + 0x44) = b;
}
