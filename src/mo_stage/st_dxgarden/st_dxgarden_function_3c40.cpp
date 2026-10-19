#pragma force_active on
extern "C" char* fn_77_3C40(char* base, int index) {
    int flag = *(int*)(base + 8);
    int adj = (flag >> 30) + index;
    if (adj >= 1) {
        adj -= 1;
    }
    return base + adj * 0x78 + 0xc;
}
