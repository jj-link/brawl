#pragma force_active on
extern "C" void fn_40_4127C(char* base, int idx, int val) {
    *(int*)(base + idx * 0x150 + 0xabc) = val;
}
