#pragma force_active on
extern "C" {
void* fn_27_1C8F18(char* p, unsigned int i) {
    int n = *(int*)(p + 0x18) >> 30;
    int j = n + (int)i;
    if (j >= 1) {
        j--;
    }
    return p + j * 12 + 0x1c;
}
}
