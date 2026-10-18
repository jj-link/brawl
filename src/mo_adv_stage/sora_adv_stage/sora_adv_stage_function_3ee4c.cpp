#pragma force_active on
extern "C" int fn_40_3EE4C(char* self, int i, int j) {
    self += i * 0xac;
    self += j << 2;
    return *(int*)(self + 0x44);
}
