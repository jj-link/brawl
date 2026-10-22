#pragma force_active on
struct S { char d[0x3c]; };
extern "C" {
void exit__6gfTaskFv(void*);
void fn_8007C9DC();
void fn_8007C168();
void FreeTHPReadWork__Fv();
void fn_8007E3C8();
void FreeTHPAudioDecWork__Fv();
void fn_8007BCE4();
void free__13gfHeapManagerFPv(void*);
void fn_8007BD5C();
void fn_801F6524(void*);
void fn_8015D72C();
void fn_802010D8(int);
void __dl__FPv(void*);
extern S lbl_8049DDF0[2];
extern int lbl_805A0210;
extern int lbl_805A0214;
extern void* lbl_805A0218;
extern void* lbl_805A021C;
extern void* lbl_805A0220;
extern void* lbl_805A0224;
extern void* lbl_805A0228;
extern void* lbl_805A022C;
extern int lbl_805A0230;
extern unsigned char lbl_805A024C[2];
extern int lbl_805A0250;
extern int lbl_805A025C;
extern void* lbl_805A0260;

void* fn_8007EA78(void* p, int n) {
    if (p != 0) {
        if (lbl_805A0260 != 0) {
            exit__6gfTaskFv(lbl_805A0260);
            lbl_805A0260 = 0;
        }
        if (lbl_805A0214 != 0) {
            fn_8007C9DC();
            fn_8007C168();
            lbl_805A0214 = 0;
        }
        FreeTHPReadWork__Fv();
        fn_8007E3C8();
        FreeTHPAudioDecWork__Fv();
        fn_8007BCE4();
        if (lbl_805A0218 != 0) { free__13gfHeapManagerFPv(lbl_805A0218); lbl_805A0218 = 0; }
        if (lbl_805A021C != 0) { free__13gfHeapManagerFPv(lbl_805A021C); lbl_805A021C = 0; }
        if (lbl_805A0220 != 0) { free__13gfHeapManagerFPv(lbl_805A0220); lbl_805A0220 = 0; }
        if (lbl_805A0224 != 0) { free__13gfHeapManagerFPv(lbl_805A0224); lbl_805A0224 = 0; }
        if (lbl_805A0228 != 0) { free__13gfHeapManagerFPv(lbl_805A0228); lbl_805A0228 = 0; }
        if (lbl_805A022C != 0) { free__13gfHeapManagerFPv(lbl_805A022C); lbl_805A022C = 0; }
        fn_8007BD5C();
        for (int i = 0; i < 2; i++) {
            if (lbl_805A024C[i] != 0) {
                fn_801F6524(&lbl_8049DDF0[i]);
                lbl_805A024C[i] = 0;
            }
        }
        fn_8015D72C();
        lbl_805A0210--;
        fn_802010D8(lbl_805A0230);
        lbl_805A0230 = 0;
        lbl_805A0250 = 0;
        lbl_805A025C = 0;
        if (n > 0) __dl__FPv(p);
    }
    return p;
}
}
