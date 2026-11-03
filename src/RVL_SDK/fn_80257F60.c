#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_8052D9C0[];
extern char lbl_80484C24[];
extern void fn_80231A14(u32, const char *, u16, u32);
extern void fn_80257BC8(int, int, int, int, u8 *);

void fn_80257F60(int arg0, int arg1, u32 count, u16 *data)
{
    u8 buffer[0x9C];
    u8 *p = buffer;
    int n = 0;
    u32 i;

    for (i = 0; i < count; i++) {
        *p++ = 0x19;
        *p++ = (u8)(*data >> 8);
        *p++ = (u8)*data;
        if ((int)(p - buffer) > 0x4d) {
            if (lbl_8052D9C0[0x4630] >= 2) {
                fn_80231A14(0xA0001, lbl_80484C24, (u16)n, count);
            }
            break;
        }
        n++;
        data++;
    }

    fn_80257BC8(arg0, arg1, 6, (int)(p - buffer), buffer);
}