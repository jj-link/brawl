#pragma force_active on
extern unsigned char lbl_8052CDC0[];
extern char lbl_80482878[];
extern void fn_80231A2C(int, const char *);
extern void fn_80231A74(int, const char *, int, int, int, int, int, int);
extern void fn_802319E4(int, const char *);
extern void fn_80231A14(int, const char *, unsigned int, unsigned int);
extern void *fn_8024E73C(void *);
extern unsigned char *fn_8024FC18(void *, unsigned int);
extern void fn_8024AED0(void *, int, void *);

struct Params {
    char pad[10];
    unsigned short a;
    unsigned short b;
};

int fn_8024A764(unsigned char *addr, unsigned int id, unsigned int psm, unsigned int mode, unsigned int value)
{
    char *base = lbl_80482878;
    struct Params params;
    void *entry;
    unsigned char *channel;
    if (lbl_8052CDC0[0] >= 3)
        fn_80231A2C(0x80002, base + 0x26c);
    if (lbl_8052CDC0[0] >= 3)
        fn_80231A74(0x80002, base + 0x2a4, addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
    entry = fn_8024E73C(addr);
    if (entry == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319E4(0x80001, base + 0x2dc);
        return 0;
    }
    channel = fn_8024FC18(entry, psm);
    if (channel == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319E4(0x80001, base + 0x300);
        return 0;
    }
    if (channel[0x36] != id) {
        if (lbl_8052CDC0[0] >= 2)
            fn_80231A14(0x80001, base + 0x324, channel[0x36], id);
        return 0;
    }
    if (mode == 0) {
        fn_8024AED0(channel, 0x15, 0);
    } else {
        params.a = mode;
        params.b = value;
        if (mode == 1)
            fn_8024AED0(channel, 0x15, &params);
        else
            fn_8024AED0(channel, 0x16, &params);
    }
    return 1;
}