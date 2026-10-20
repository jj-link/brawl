#pragma force_active on
extern "C" char* fn_27_D9200(char* p, int idx) {
    int v = *(int*)(p + 8) >> 24;
    int i = v + idx;
    if (i < 0x40) {
        i = i;
    } else {
        i -= 0x40;
    }
    return p + i * 0x30 + 0xc;
}
