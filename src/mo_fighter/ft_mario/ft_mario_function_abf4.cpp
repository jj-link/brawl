#pragma force_active on
extern "C" int fn_91_ABE8();

extern "C" int fn_91_ABF4(int self, int a, int b, int c) {
    int* table = *reinterpret_cast<int**>(self - 0x10000 + (fn_91_ABE8() << 4) + (b << 2) - 0x7670);
    return table[c];
}
