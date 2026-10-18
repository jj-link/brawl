#pragma force_active on
extern "C" int fn_100_13568(char* self, int unused, int idx) {
    int base = *(int*)(self + 0x18);
    return *(int*)(self + (idx - base) * 4 + 0x24);
}
