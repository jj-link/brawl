#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Callback)(void *);

extern char lbl_80529CF8[];
extern char lbl_8048114C[];
extern void fn_8022F0E0(void *);
extern void fn_80231A14(u32, const char *, u32, u32);

static void reset(char *st)
{
    int zero;
    void *val;
    u16 *words;

    zero = 0;
    *(int *)(st + 0x16B4) = zero;
    *(u8 *)(st + 0x1848) = zero;
    *(u8 *)(st + 0x1847) = zero;
    *(int *)(st + 0x16B0) = zero;
    words = (u16 *)(lbl_80529CF8 + 0x16DC);
    val = *(void **)words;
    if (val != 0) {
        fn_8022F0E0(val);
        *(int *)words = zero;
    }
    words[2] = zero;
    words[3] = zero;
}

void fn_8023D478(int arg0)
{
    char *base;
    int callback;
    int counter;
    u8 status;

    base = lbl_80529CF8;
    callback = *(int *)(base + 0x16B0);
    if (*(u8 *)(base + 0x1848) != 0) {
        counter = *(int *)(base + 0x16C0) + 1;
        *(int *)(base + 0x16C0) = counter;
        status = 10;
        if (arg0 == 0) {
            status = 0;
        }
        *(u8 *)(base + 0x183E) = status;
        if (!(*(u8 *)(base + 0x1848) & 4)) {
            reset(base);
            if (*(u8 *)(lbl_80529CF8 + 0x27C0) >= 5) {
                fn_80231A14(0xD0004, lbl_8048114C,
                            *(u8 *)(base + 0x183E), *(u8 *)(base + 0x183F));
            }
            if (callback != 0) {
                ((Callback)callback)(base + 0x183E);
            }
        }
    }
}