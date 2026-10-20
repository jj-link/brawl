#pragma force_active on
extern "C" void* fn_27_1AFB5C(char* p, int i) {
    int s = *(int*)(p + 8) >> 27;
    int j = s + i;
    if (j >= 8) {
        j -= 8;
    }
    return p + 0xc + j * 4;
}
