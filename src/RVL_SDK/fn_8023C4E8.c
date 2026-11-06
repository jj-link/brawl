#pragma force_active on
typedef unsigned char u8;

typedef struct Inquiry {
    u8 mode;
    u8 duration;
    u8 responses;
    u8 filter;
    u8 address[6];
} Inquiry;

extern unsigned char lbl_80529CF8[];
extern char lbl_80481044[];
extern void fn_80231A44(unsigned int, const char *, u8, u8, u8, u8);
extern u8 fn_8023A5A4(void);
extern u8 fn_8023CEFC(u8, void *);

u8 fn_8023C4E8(Inquiry *arg0, int arg1, int arg2) {
    u8 result;
    u8 *p = lbl_80529CF8;
    if (p[0x27C0] >= 3U) {
        fn_80231A44(0xD0002, lbl_80481044,
            arg0->mode, arg0->duration, arg0->responses, arg0->filter);
    }
    if (p[0x1848] != 0 || p[0x1844] != 0) {
        return 2;
    }
    if (arg0->mode != 0 && arg0->mode != 1) {
        return 5;
    }
    if (fn_8023A5A4() == 0) {
        return 6;
    }
    *(Inquiry *)(p + 0x1834) = *arg0;
    p[0x1847] = 3;
    *(int *)(p + 0x16B0) = arg2;
    *(int *)(p + 0x16B4) = arg1;
    p[0x183F] = 0;
    p[0x1848] = arg0->mode == 1 ? 1 : 2;
    switch (arg0->filter) {
    case 0:
        p[0x1847] = 2;
        break;
    case 1:
    case 2:
        p[0x1847] = 1;
        arg0->filter = 0;
        break;
    default:
        return 5;
    }
    result = fn_8023CEFC(arg0->filter, arg0->address);
    if (result != 1) {
        p[0x1847] = 0;
    }
    return result;
}
