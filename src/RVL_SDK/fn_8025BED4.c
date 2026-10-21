#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;

void fn_8025BED4(unsigned long arg0, u8* arg1) {
    int lim;
    u16 a;
    u16 b;
    u8* p;
    u16 i;

    if (arg0 > 1) {
        lim = arg0 - 1;
        i = 0;
        while ((int)i < lim) {
            p = arg1 + (i * 2);
            b = *(u16*)(p + 0x50);
            a = *(u16*)(p + 0x4E);
            if (a > b) {
                *(u16*)(p + 0x4E) = b;
                i = 0xFFFF;
                *(u16*)(p + 0x50) = a;
            }
            i++;
        }
    }
}
