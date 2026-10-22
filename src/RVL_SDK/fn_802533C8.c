#pragma force_active on
typedef unsigned char u8;

extern u8 lbl_8052D5A8[];
extern const char lbl_80484708[];
extern void fn_802319FC(int, const char*, int);
extern void fn_80253458(u8*, int, int);
extern void fn_802535CC(u8*, int, int);
extern void fn_80253924(u8*, int, int);
extern void fn_80253768(u8*, int, int);
extern void fn_80253A74(u8*, int, int);
extern void fn_80253C60(u8*, int, int);

void fn_802533C8(u8* arg1, int arg2, int arg3) {
    if (arg1 == 0) {
        if (lbl_8052D5A8[0x414] >= 2) {
            fn_802319FC(0x90001, lbl_80484708, arg2);
        }
        return;
    }
    switch (arg1[0x68]) {
        case 0:
            fn_80253458(arg1, arg2, arg3);
            return;
        case 1:
            fn_802535CC(arg1, arg2, arg3);
            return;
        case 2:
            fn_80253924(arg1, arg2, arg3);
            return;
        case 3:
            fn_80253768(arg1, arg2, arg3);
            return;
        case 4:
            fn_80253A74(arg1, arg2, arg3);
            return;
        case 5:
            fn_80253C60(arg1, arg2, arg3);
            return;
    }
}
