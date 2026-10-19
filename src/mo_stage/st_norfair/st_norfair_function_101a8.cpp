#pragma force_active on
extern "C" {
void* fn_54_101A8(char* self, int index);
}

void* fn_54_101A8(char* self, int index) {
    int n = (*(int*)(self + 8) >> 26) + index;
    if (n >= 0x12) {
        n -= 0x12;
    }
    return self + 0xc + n * 0x90;
}
