#pragma force_active on
extern "C" {
int fn_801C6C34(void*, int, int, int*);
int fn_801C6C1C(void*, int, int*);
int fn_801C6C24(void*, int, int, int*);
}

extern "C" int fn_801C0DC8(int* self, int x) {
    int c[6];
    int b[6];
    int a[2];
    if (!fn_801C6C34(self, x, 0, a)) return 0;
    if (!fn_801C6C1C(self, a[0], c)) return 0;
    if (!fn_801C6C24(self, a[0], a[1], b)) return 0;
    if (c[1] != 0) return 0;
    int s = c[2] + b[1];
    return s + self[0x42];
}
