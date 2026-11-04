#pragma force_active on

extern void *fn_80251AD0(void);
extern void fn_80254F00(void *, int, int, int, int, unsigned char);
extern void fn_8025640C(void *, int);

void fn_8025466C(unsigned char *arg0, int arg1, int arg2)
{
    unsigned char *temp;
    unsigned char mode;
    unsigned short count;
    unsigned short limit;
    unsigned char value;
    int flags;

    temp = (unsigned char *)fn_80251AD0();
    if (arg0[0x6C] != 5) {
        temp[0xE] = 0xD;
        return;
    }
    mode = arg0[0x72] ? arg0[0x72] : 2;
    if (mode == 2) {
        count = *(unsigned short *)(temp + 0x9C);
        flags = 0xF0;
        limit = count < 7U ? count : 7;
        value = (unsigned char)limit;
        *(unsigned short *)(temp + 0x9A) = value;
    } else {
        flags = 0;
        value = 0;
    }
    temp[0x69] |= 1;
    fn_80254F00(arg0, arg1, 1, arg2, flags, value);
    fn_8025640C(temp, 0x3C);
}
