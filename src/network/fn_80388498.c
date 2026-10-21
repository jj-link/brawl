#pragma force_active on
typedef unsigned char u8;

void fn_80388498(u8* p, u8 c) {
    int n = *(int*)(p + 0x40);
    u8* q;
    if (n >= 0x14) {
        return;
    }
    q = p + n;
    q[0x2c] = c;
    *(int*)(p + 0x40) = n + 1;
}
