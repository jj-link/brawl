#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef unsigned char u8;
typedef signed short s16;

typedef struct { u8* first; u8* second; u8* third; u32 mode; } Arg;

typedef struct { double lo; double hi; } Copy;

typedef union {
    struct { u32 first; u32 second; u32 third; u32 d; } f;
    Copy dd;
} Buf;

typedef union {
    double d[2];
    Copy c;
    u32 w[4];
} Tmp;

extern s32 fn_803D66F4(void*);
extern void fn_803D66EC(void*, s32);
extern void fn_803D674C(void*, s16);
extern int fn_803D68B8(int*);
extern s32 fn_803D6A50(Arg*, s32, u32, s32, u16);
extern s32 fn_803E6EA0(Buf*, s32);
extern char lbl_8059FEE0;
extern char lbl_8059FEE4;

s32 fn_803E5F58(Arg* arg0, u32* arg1, u32* arg2, s32 arg3) {
    Buf buf;
    Tmp tmp;
    u32 var_r30;
    s32 ctx;
    s32 ret;

    ctx = fn_803D66F4(arg0);
    fn_803D66EC(arg1, ctx);
    fn_803D66EC(arg2, ctx);
    arg1[0] = 0;
    if (arg2 != 0) {
        arg2[0] = 0;
    }
    if (fn_803D6A50(arg0, (s32)&lbl_8059FEE0, 1, 1, 1) == 0) {
        fn_803D674C(arg0, 2);
    }
    var_r30 = (u32)arg0->first;
    buf.f.first = var_r30;
    buf.f.second = var_r30;
    buf.f.d = ctx;
    ret = fn_803E6EA0(&buf, arg3);
    if (ret != 0) {
        return ret;
    }
    if (buf.f.first == 0 || (u16)fn_803D68B8((int*)&buf) == 0) {
        return 2;
    }
    if ((u32)arg0->second < buf.f.second) {
        return 2;
    }
    tmp.c = buf.dd;
    for (;;) {
        if (fn_803D6A50((Arg*)&buf, (s32)&lbl_8059FEE4, 2, 0, 1) == 0) {
            var_r30 = tmp.w[1];
            break;
        }
        ret = fn_803E6EA0(&buf, arg3);
        if (ret != 0) {
            return ret;
        }
        if ((u16)fn_803D68B8((int*)&buf) == 0) {
            return 2;
        }
        if ((u32)arg0->second < buf.f.second) {
            break;
        }
        if (buf.f.first == 0) {
            break;
        }
        var_r30 = tmp.w[1];
        tmp.c = buf.dd;
    }
    arg1[0] = (u32)arg0->first;
    arg1[1] = var_r30;
    if (arg2 != 0) {
        arg2[0] = tmp.w[0];
        arg2[1] = tmp.w[1];
        arg2[2] = tmp.w[2];
        arg2[3] = tmp.w[3];
    }
    return 0;
}
