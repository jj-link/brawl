#pragma force_active on
extern void fn_80281D64(int a, int b, int c);

void fn_8027D438(void* a) {
    int* p = (int*)a;
    fn_80281D64(p[0], 0, (p[2] + 1) * 8);
    p[1] &= 0x80000000;
}
