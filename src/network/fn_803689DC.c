#pragma force_active on
typedef int s32;
typedef unsigned char u8;

typedef struct Obj {
    u8 unk00;
    u8 pad01[0xFF];
    s32 unk100;
    s32 unk104;
    s32 unk108;
    s32 unk10C;
    u8 pad110[0x1A4 - 0x110];
    s32 unk1A4;
    s32 unk1A8[18];
    u8 pad1F0[0x434 - 0x1F0];
    s32 unk434;
    u8 pad438[0x43C - 0x438];
    s32 unk43C;
    u8 pad440[0x444 - 0x440];
    s32 unk444;
    u8 pad448[0x484 - 0x448];
    s32 unk484;
    s32 unk488;
} Obj;

extern Obj *fn_8035DFE8(int size);
extern void fn_8035E00C(Obj *p);
extern s32 fn_80370494(Obj **pp);
extern s32 fn_80368C10(Obj **pp);
extern void fn_8036C3A8(Obj **pp, int b);
extern void fn_8035AF74(s32 a);
extern void fn_8035D720(void);
extern unsigned int fn_8035D728(void);
extern void fn_803F8C5C(void);
extern void *memset(void *dst, int c, unsigned long n);

s32 fn_803689DC(Obj **arg0, s32 arg1, s32 arg2, s32 arg3)
{
    Obj *sp8;
    s32 temp = 0;

    *arg0 = 0;
    sp8 = fn_8035DFE8(0x4A8);
    if (sp8 == 0) {
        return 1;
    }
    memset(sp8, 0, 0x4A8);
    sp8->unk00 = 0;
    sp8->unk434 = 0;
    sp8->unk100 = 1;
    sp8->unk104 = 0;
    sp8->unk108 = 0;
    sp8->unk10C = 0;
    sp8->unk484 = arg1;
    sp8->unk488 = arg2;
    sp8->unk1A4 = arg3;
    if (fn_80370494(&sp8) == 0) {
        fn_8035E00C(sp8);
        return 1;
    }
    sp8->unk43C = 0;
    sp8->unk1A8[0] = 0;
    sp8->unk1A8[1] = 0;
    sp8->unk1A8[2] = 0;
    sp8->unk1A8[3] = 0;
    sp8->unk1A8[4] = 0;
    sp8->unk1A8[5] = 0;
    sp8->unk1A8[6] = 0;
    sp8->unk1A8[7] = 0;
    sp8->unk1A8[8] = 0;
    sp8->unk1A8[9] = 0;
    sp8->unk1A8[10] = 0;
    sp8->unk1A8[11] = 0;
    sp8->unk1A8[12] = 0;
    sp8->unk1A8[13] = 0;
    sp8->unk1A8[14] = 0;
    sp8->unk1A8[15] = 0;
    sp8->unk1A8[16] = 0;
    sp8->unk1A8[17] = 0;
    temp = fn_80368C10(&sp8);
    if (temp != 0) {
        Obj *p = sp8;
        fn_8036C3A8(&sp8, 1);
        fn_8035AF74(p->unk444);
        fn_8035E00C(p);
        return temp;
    }
    fn_8035D720();
    fn_8035D728();
    fn_803F8C5C();
    *arg0 = sp8;
    return 0;
}