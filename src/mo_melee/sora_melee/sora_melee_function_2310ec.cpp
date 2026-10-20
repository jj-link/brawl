#pragma force_active on
extern "C" void fn_27_2310EC(char* self, float x, float y) {
    char* p = *(char**)(self + 0x78);
    if (p == 0) {
        return;
    }
    *(float*)(p + 0x10) = x;
    *(float*)(p + 0x14) = y;
}
