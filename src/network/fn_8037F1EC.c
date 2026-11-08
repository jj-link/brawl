#include <string.h>
#include <types.h>
#pragma force_active on

extern char *fn_8035D654(const char *);
extern void fn_8035E00C(void *);
extern void fn_8035A5C8(void *, void *);

struct Buf {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

s32 fn_8037F1EC(struct Obj *arg0, char *arg1, s32 arg2, s32 arg3, char *arg4, char *arg5) {
    struct Buf buf;

    arg1 = fn_8035D654(arg1);
    arg4 = fn_8035D654(arg4);
    arg5 = fn_8035D654(arg5);
    if (arg1 == 0 || arg4 == 0 || arg5 == 0) {
        fn_8035E00C(arg1);
        fn_8035E00C(arg4);
        fn_8035E00C(arg5);
        return 0;
    }
    memset(&buf, 0, 0x18);
    buf.unk0 = 2;
    buf.unk4 = (s32)arg1;
    buf.unk8 = arg2;
    buf.unkC = arg3;
    buf.unk10 = (s32)arg4;
    buf.unk14 = (s32)arg5;
    fn_8035A5C8((void *)arg0->unk0, &buf);
    arg0->unkC = 1;
    if (arg0->unk10 == 1) {
        arg0->unk14 = 1;
    }
    return 1;
}
