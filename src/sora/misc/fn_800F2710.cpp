#pragma force_active on
extern "C" int fn_800F227C(void*, void*, int, int);
extern "C" void fn_800B92D8(void*, unsigned long, void*, int);
extern "C" void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);

extern "C" void fn_800F2710(char* self, unsigned long a, unsigned long b, int c, int d) {
    char buf[0x100];
    void* m = *(void**)(self + 0x8c);
    if (c == 1) {
        fn_800B92D8(m, a, buf, fn_800F227C(self, buf, d, 1));
        return;
    }
    switch (c) {
    case 2: b = 0x4e; break;
    case 3: b = 0x51; break;
    case 4: b = 0x53; break;
    case 5: b = 0x30; break;
    }
    printIndex__5MuMsgFUlUlPv(m, a, b, 0);
}
