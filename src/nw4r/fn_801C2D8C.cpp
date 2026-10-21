#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;

extern "C" {
void fn_801C2244(void*);
void fn_801C2474(void*);
void fn_801C2548(void*, void*);
int fn_8020111C(void);
void fn_80201148(int, void*, int);
void fn_8020120C(int);

extern u8 lbl_804C1D00[0x2D8];
extern u8 lbl_805A05A0;

inline u8* getData() {
    if ((s8)lbl_805A05A0 == 0) {
        u8* p;
        u8* base = lbl_804C1D00;
        base[0] = 0;
        p = base + 0x38;
        u8* end = base + 0x2D8;
        do {
            fn_801C2244(p);
            p += 0xA8;
        } while (p < end);
        *(int*)(base + 0x70) = 0;
        *(int*)(base + 0x118) = 1;
        *(int*)(base + 0x1C0) = 2;
        *(int*)(base + 0x268) = 3;
        lbl_805A05A0 = 1;
    }
    return lbl_804C1D00;
}

void fn_801C2D8C(void) {
    u8 buffer[0x50];
    u8* p;
    u8* base = getData();
    if (fn_8020111C() >= 0x28) {
        p = base + 0x38;
        int i = 0;
        do {
            if (*(int*)(base + 0x44) == 4) {
                fn_80201148(i, buffer, 0x28);
                fn_801C2548(p, buffer);
            }
            fn_801C2474(p);
            ++i;
            base += 0xA8;
            p += 0xA8;
        } while (i < 4);
        fn_8020120C(0x28);
    }
}
}
