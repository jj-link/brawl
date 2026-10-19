#pragma force_active on
extern "C" int fn_99_8EE8();

extern "C" int fn_99_8EF4(int self, int unused, int i, int j) {
    int* table = *(int**)((self - 0x10000) + fn_99_8EE8() * 12 + i * 4 - 0x75b0);
    return table[j];
}
