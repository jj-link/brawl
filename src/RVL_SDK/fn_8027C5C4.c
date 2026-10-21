#pragma force_active on
int fn_8027D1F0(void* self, int a, int b);

unsigned int fn_8027C5C4(char* arg0, int arg1) {
    int r = fn_8027D1F0(arg0 + 8, arg1, 0);
    return (__cntlzw(r) << 19) & 0xFF000000;
}
