#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct THPComponent {
    u8 quantizationTableSelector;
    u8 DCTableSelector;
    u8 ACTableSelector;
    u8 pad;
    s16 predDC;
} THPComponent;

typedef struct Ctx {
    f32 quantTabs[6][64];
    char pad600[0x80];
    THPComponent components[3];
    char pad692[4];
    u16 MCUsPerRow;
    char pad698[0xC];
    u32 cnt;
    u8 b6A8;
    u8 RST;
    u16 RSTinterval;
    u16 nMCU;
    char pad6AE[2];
    u32 dLC[3];
} Ctx;

extern Ctx *lbl_805A0D44;
extern f32 *lbl_805A0D60;
extern u32 lbl_805A0D80;
extern u32 lbl_805A0DA0;
extern void *lbl_80532000[6];
extern u32 lbl_80532018[10];

void fn_801D7AE4(int);
void fn_801D7A38(u32, u32, u32);
void fn_8025D334(void *, u32);
void fn_8025D7C0(void *, u32);
void fn_8025E100(Ctx *, void *);
void fn_8025E75C(Ctx *, void *);
void fn_8025EDE4(Ctx *, void *);

void fn_8025D0E8(void) {
    u8 cl_num;
    u32 x_pos;
    THPComponent *comp;

    fn_801D7AE4(3);
    for (cl_num = 0; cl_num < (*(Ctx **)&lbl_805A0D44)->MCUsPerRow; cl_num++) {
        fn_8025E100(lbl_805A0D44, lbl_80532000[0]);
        fn_8025E100(lbl_805A0D44, lbl_80532000[1]);
        fn_8025E100(lbl_805A0D44, lbl_80532000[2]);
        fn_8025E100(lbl_805A0D44, lbl_80532000[3]);
        fn_8025E75C(lbl_805A0D44, lbl_80532000[4]);
        fn_8025EDE4(lbl_805A0D44, lbl_80532000[5]);

        comp = &lbl_805A0D44->components[0];
        lbl_805A0DA0 = lbl_80532018[0];
        lbl_805A0D80 = 0x200;
        lbl_805A0D60 = lbl_805A0D44->quantTabs[comp->quantizationTableSelector];
        x_pos = (u32)(cl_num * 16);
        fn_8025D334(lbl_80532000[0], x_pos);
        fn_8025D334(lbl_80532000[1], x_pos + 8);
        fn_8025D7C0(lbl_80532000[2], x_pos);
        fn_8025D7C0(lbl_80532000[3], x_pos + 8);

        comp = &lbl_805A0D44->components[1];
        lbl_805A0DA0 = lbl_80532018[1];
        lbl_805A0D80 = 0x100;
        lbl_805A0D60 = lbl_805A0D44->quantTabs[comp->quantizationTableSelector];
        x_pos /= 2;
        fn_8025D334(lbl_80532000[4], x_pos);
        comp = &lbl_805A0D44->components[2];
        lbl_805A0DA0 = lbl_80532018[2];
        lbl_805A0D60 = lbl_805A0D44->quantTabs[comp->quantizationTableSelector];
        fn_8025D334(lbl_80532000[5], x_pos);

        if (lbl_805A0D44->RST != 0) {
            if (--lbl_805A0D44->nMCU == 0) {
                lbl_805A0D44->nMCU = lbl_805A0D44->RSTinterval;
                lbl_805A0D44->cnt = ((lbl_805A0D44->cnt + 6) & ~7) + 1;
                if (lbl_805A0D44->cnt > 0x21) {
                    lbl_805A0D44->cnt = 0x21;
                }
                lbl_805A0D44->components[0].predDC = 0;
                lbl_805A0D44->components[1].predDC = 0;
                lbl_805A0D44->components[2].predDC = 0;
            }
        }
    }
    fn_801D7A38(lbl_805A0D44->dLC[0], lbl_80532018[0], 0x2000);
    fn_801D7A38(lbl_805A0D44->dLC[1], lbl_80532018[1], 0x800);
    fn_801D7A38(lbl_805A0D44->dLC[2], lbl_80532018[2], 0x800);
    lbl_805A0D44->dLC[0] += 0x2000;
    lbl_805A0D44->dLC[1] += 0x800;
    lbl_805A0D44->dLC[2] += 0x800;
}
