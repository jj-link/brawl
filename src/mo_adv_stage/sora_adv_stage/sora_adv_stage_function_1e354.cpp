#pragma force_active on
extern "C" int fn_40_1E354(void* self) {
    unsigned int v = *(unsigned int*)((char*)self + 8);
    return (int)((v << 6) & 0xFE000000) >> 26;
}
