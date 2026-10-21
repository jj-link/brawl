#pragma force_active on
extern "C" {
void fn_801B6AE8(int* a, int b, int c, int d, int e);

void fn_801B21A0(unsigned char* arg0) {
    int sp8;
    int v = *(int*)(arg0 + 0x138);

    if (v != 0) {
        sp8 = *(int*)(arg0 + 0xe8);
        fn_801B6AE8(&sp8, v, *(int*)(arg0 + 0x178), *(int*)(arg0 + 0x17c), *(int*)(arg0 + 0x180));
    }
}
}
