#pragma force_active on
extern "C" int fn_40_24918(char* p) {
    int v = *(int*)(p + 8);
    return ((v << 2) & (int)0xE0000000) >> 30;
}
