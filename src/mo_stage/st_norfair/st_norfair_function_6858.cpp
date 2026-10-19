#pragma force_active on
extern "C" void* fn_54_6858(char* self, int index) {
    int n = (*(int*)(self + 8) >> 30) + index;
    n = (n >= 1) ? n - 1 : n;
    return self + n * 0x90 + 0xc;
}
