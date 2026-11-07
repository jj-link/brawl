#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    u16 field0;
    u8 field2;
    u8 pad3;
    u16 field4;
    u8 field6;
    u8 pad7[0x19];
    u8 field20;
} Arg1;

typedef struct {
    u8 pad[0x68];
    u16 field68;
    s16 field6A;
    u8 field6C;
    u8 field6D;
    u8 field6E;
    u8 field6F;
} Data;

extern u8 lbl_8052D5A8[];
extern char lbl_804846EC[];

extern void fn_802319FC(int, const char *, void *);
extern void fn_8024A9AC(u16, void *);
extern void fn_80254A94(Data *, int);

void fn_802532D8(Data *arg0, Arg1 *arg1)
{
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, lbl_804846EC, arg1);
    }
    if (arg1->field2 != 0) {
        arg0->field6A = (s16)(arg1->field4 - 6);
    } else {
        arg0->field6A = 0x29A;
    }
    arg1->field2 = 0;
    arg1->field20 = 0;
    arg1->field6 = 0;
    arg1->field0 = 0;
    fn_8024A9AC(arg0->field68, arg1);
    arg0->field6F = 1;
    if (arg0->field6C == 2 && arg0->field6E != 0) {
        if (arg0->field6D != 0) {
            arg0->field6C = 3;
            fn_80254A94(arg0, 0);
            return;
        }
        arg0->field6C = 4;
    }
}
