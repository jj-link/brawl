#pragma force_active on
extern "C" int fn_10_39C8(char* p, int i) {
    return *(int*)(*(char**)(p + 0x44 + i * 4) + 0x1ac);
}
