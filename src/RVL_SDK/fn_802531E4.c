#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x68];
    u16 field68;
    u8 pad6A[2];
    u8 field6C;
    u8 field6D;
    u8 field6E;
    u8 field6F;
} Data;

extern u8 lbl_8052D5A8[];
extern char lbl_804846C8[];

extern void fn_80231A14(u32, const char *, void *, int);
extern void fn_8025047C(Data *, int);
extern void fn_8024AA7C(u16);
extern void fn_802562B8(Data *);
extern void fn_80254A94(Data *, int);

void fn_802531E4(Data *arg0, u16 *arg1)
{
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_80231A14(0x90003, lbl_804846C8, arg1, arg1 ? *arg1 : 0);
    }

    if (*arg1 != 0) {
        if (arg0->field6D != 0) {
            fn_8025047C(arg0, *arg1);
            fn_8024AA7C(arg0->field68);
        }
        fn_802562B8(arg0);
        return;
    }

    arg0->field6E = 1;
    if (arg0->field6C == 2 && arg0->field6F != 0) {
        if (arg0->field6D != 0) {
            arg0->field6C = 3;
            fn_80254A94(arg0, 0);
            return;
        }
        arg0->field6C = 4;
    }
}
