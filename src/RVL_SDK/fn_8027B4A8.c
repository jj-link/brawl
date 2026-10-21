#pragma force_active on
int fn_8027B4A8(char* base, int idx) {
    return *(int*)(base + idx * 0x68 + 0x50) != 0;
}
