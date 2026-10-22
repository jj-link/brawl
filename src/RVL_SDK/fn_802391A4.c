#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

extern char lbl_80529CF8[];

struct Local {
    u8 a;
    u8 pad[7];
    s16 b;
    u32 c;
};

void fn_802391A4(void *arg0) {
    struct Local loc;
    void (*fn)(void *);

    if (*(u32 *)((char *)arg0 + 0x10) == 4) {
        fn = *(void (**)(void *))(lbl_80529CF8 + 0x5C4);
        loc.a = 10;
        loc.b = 0;
        *(void **)(lbl_80529CF8 + 0x5C4) = 0;
        if (fn != 0) {
            fn(&loc.a);
        }
    }
}
