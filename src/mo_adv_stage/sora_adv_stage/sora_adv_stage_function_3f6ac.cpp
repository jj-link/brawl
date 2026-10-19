#pragma force_active on
extern "C" int fn_40_3F6AC(int* base, int index) {
    int value = *(int*)((char*)base + index * 0xac + 0xe4);
    return (value + 6) / 7;
}
