#pragma force_active on
extern "C" char* fn_51_D84C(char* self, int index) {
    int i = (*(int*)(self + 8) >> 29) + index;
    if (i >= 2) {
        i -= 2;
    }
    return self + i * 0xA0 + 0xC;
}
