#include <revolution/OS/OS.h>
#pragma force_active on

#pragma use_lmw_stmw on

typedef unsigned long u32;
typedef signed long s32;
typedef unsigned char u8;

extern s32 fn_80264074(s32 *, u32 *, s32, void *);
extern s32 fn_802642F0(void *, s32, void *);
extern s32 fn_80262218(void *, s32, void *);
extern s32 fn_80262444(void *, s32, void *);
extern void fn_80267874(void *);
extern void fn_802691A8(void *);
extern const char *lbl_8059EE50;

s32 fn_802608BC(void *arg0, s32 arg1, u32 arg2, void *arg3,
                u32 arg4, u8 arg5, u8 arg6, u32 arg7)
{
    struct {
        unsigned char input[0x20];
        unsigned char parsed[0x700];
    } workspace;
    s32 spC;
    u32 sp8;
    s32 count;
    u32 val;
    s32 ret;

    OSRegisterVersion(lbl_8059EE50);
    workspace.input[0x1D] = arg6;
    workspace.input[4] = arg5;
    *(void **)(workspace.input + 0) = arg0;
    *(u32 *)(workspace.input + 8) = arg2;

    if (arg7 == 1) {
        workspace.input[0x1C] = 1;
        count = fn_80264074(&spC, &sp8, arg1, workspace.input);
        if (count < 0) {
            if (count == -0x45 || count == -2) {
                return -0xA0;
            }
            return count;
        }
        if (sp8 > arg2) {
            return -0xA0;
        }
        count = fn_802642F0(workspace.parsed, arg1 + spC, workspace.input);
        if (count < 0) {
            if (count == -0x45) {
                return -0xA0;
            }
            return count;
        }
    } else if (arg7 == 0) {
        workspace.input[0x1C] = 0;
        count = fn_80262218(workspace.parsed, arg1, workspace.input);
        if (count < 0) {
            return count;
        }
    } else {
        return -1;
    }

    switch (*(s32 *)(workspace.parsed + 8)) {
    case 4:
        val = *(u32 *)(workspace.parsed + 0x4C) *
              (*(u32 *)(workspace.parsed + 0x48) * 2);
        break;
    case 6:
        val = *(u32 *)(workspace.parsed + 0x4C) *
              (*(u32 *)(workspace.parsed + 0x48) * 4);
        break;
    default:
        val = 0;
        break;
    }

    if (val > arg4) {
        return -0x90;
    }

    for (;;) {
        ret = fn_80262444(workspace.parsed, count, arg3);
        if (ret < 0) {
            return ret;
        }
        if (ret > 0) {
            continue;
        }
        switch (*(s32 *)(workspace.parsed + 8)) {
        case 4:
            fn_802691A8(workspace.parsed);
            break;
        case 6:
            fn_80267874(workspace.parsed);
            break;
        default:
            break;
        }
        return 0;
    }
}
