#pragma force_active on
extern "C" void fn_40_42F04(void* a, int b, int c);

extern "C" void fn_40_47B98(char* base, int n) {
    *(int*)(base + 0x1bc) = 0;
    int* q = (int*)base;
    for (int i = 0; i < n; i++) {
        int cnt = *(int*)(base + 0x1bc);
        char* t = base;
        t = t + cnt * 0x58;
        char* p = t + 0x1c0;
        fn_40_42F04(p, i, q[0x1348 / 4]);
        if (i == 0 || ((p[0] >> 7) & 1)) {
            *(int*)(base + 0x1bc) = *(int*)(base + 0x1bc) + 1;
        }
        q++;
    }
}
