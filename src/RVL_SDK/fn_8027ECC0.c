#pragma force_active on
extern int fn_8027E2F0(void* unused, int size);

int fn_8027ECC0(char* self, int idx) {
    int v;
    if (idx <= 0x2000) {
        if (idx <= 0x200) {
            v = *(signed char*)(self + idx + 0xacc);
        } else {
            v = *(int*)(self + ((idx - 1) >> 10) * 4 + 0xcd0);
        }
        return *(int*)(self + v * 4 + 0xa88);
    }
    return fn_8027E2F0(self, idx);
}
