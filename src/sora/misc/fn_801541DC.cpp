#pragma force_active on

typedef unsigned char u8;

extern "C" u8 fn_801541DC(void* arg0) {
    u8 v = *(u8*)((char*)arg0 + 4);
    if (v > 5) {
        v = 0;
    }
    return v;
}
