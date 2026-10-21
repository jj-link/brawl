#pragma force_active on
extern int fn_80369034(void* a, int b);

int fn_80367C74(int* p) {
    int* q;
    if (p == 0 || (q = (int*)*p) == 0) return 2;
    if (q[0x108 / 4] != 0) return 0;
    return fn_80369034(p, 0);
}
