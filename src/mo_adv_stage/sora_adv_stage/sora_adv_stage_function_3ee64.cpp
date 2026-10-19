#pragma force_active on
extern "C" {
int fn_40_3EE64(char* self, int a, int b)
{
    int (*arr)[43] = (int (*)[43])(self + 0x44);
    int v = arr[a][b];
    if (v == 0x1b) {
        return *(int*)(self + 0xc30);
    }
    if (v == 0x1b) {
        return *(int*)(self + 0xc30);
    }
    if (v == 0xe) {
        return *(int*)(self + 0xc34);
    }
    if (v == 3) {
        return *(int*)(self + 0xc38);
    }
    return v;
}
}
