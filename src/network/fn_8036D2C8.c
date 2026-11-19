#include <types.h>
#pragma force_active on

extern char jumptable_8048F1C0[];
extern char lbl_8059F7E8[3];
extern char lbl_8059F778[6];
extern char lbl_8059F790[6];
extern char lbl_8059F798[6];
extern char lbl_8059F7A0[6];
extern char lbl_8059F7A8[6];
extern char lbl_8059F7B0[6];
extern char lbl_8059F7B8[6];
extern char lbl_8059F7C0[6];
extern char lbl_8059F7EC[4];
extern char lbl_8059F7F0[4];
extern char lbl_8059F7F4[4];

extern s32 fn_8036A328(void *, void *, const char *);
extern void fn_803732E0(void *, const void *);
extern s32 sprintf(char *, const char *, ...);

static inline s32 append_pair(void **ctx, const char *value, char *state,
                              s32 offset, const char *name)
{
    s32 result = fn_8036A328(ctx, state + offset, name);
    s32 next;
    s32 tmp;

    if (result != 0)
        return result;

    next = fn_8036A328(ctx, state + offset, value);
    tmp = 0;
    if (next != 0)
        tmp = next;
    return tmp;
}

#define APPEND(offset, key, value) do { \
    char *state = (char *)*arg0; \
    ret = append_pair(arg0, (value), state, (offset), (key)); \
    if (ret != 0) return ret; \
} while (0)

s32 fn_8036D2C8(void **arg0, s32 arg1, s32 arg2)
{
    char *genderState;
    char buf[24];
    s32 ret;
    char *table = jumptable_8048F1C0;

    switch (arg1) {
    case 0x708:
        if (arg2 < 0) {
            fn_803732E0(arg0, table + 0x130);
            return 2;
        }
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, table + 0xb0, buf);
        break;

    case 0x70b:
        switch (arg2) {
        case 0x500:
            {
                const char *value = lbl_8059F7EC;
                genderState = (char *)*arg0;
                ret = append_pair(arg0, value, genderState, 0x45c, lbl_8059F778);
                if (ret != 0) return ret;
            }
            break;
        case 0x501:
            {
                const char *value = lbl_8059F7F0;
                genderState = (char *)*arg0;
                ret = append_pair(arg0, value, genderState, 0x45c, lbl_8059F778);
                if (ret != 0) return ret;
            }
            break;
        case 0x502:
            {
                const char *value = lbl_8059F7F4;
                genderState = (char *)*arg0;
                ret = append_pair(arg0, value, genderState, 0x45c, lbl_8059F778);
                if (ret != 0) return ret;
            }
            break;
        default:
            fn_803732E0(arg0, table + 0x144);
            return 2;
        }
        break;

    case 0x706:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, table + 0x98, buf);
        break;

    case 0x70c:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x46c, table + 0x154, buf);
        break;

    case 0x70d:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x46c, table + 0x164, buf);
        break;

    case 0x70e:
        sprintf(buf, lbl_8059F7E8, arg2 / 16);
        APPEND(0x46c, table + 0x170, buf);
        break;

    case 0x710:
        sprintf(buf, lbl_8059F7E8, arg2 / 4);
        APPEND(0x46c, table + 0x180, buf);
        break;

    case 0x712:
        sprintf(buf, lbl_8059F7E8, arg2 / 4);
        APPEND(0x46c, table + 0x190, buf);
        break;

    case 0x713:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x46c, table + 0x1a0, buf);
        break;

    case 0x714:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x46c, table + 0x1b0, buf);
        break;

    case 0x715:
        if (arg2 != 0)
            arg2 = 1;
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x46c, table + 0x1c4, buf);
        break;

    case 0x718:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, lbl_8059F790, buf);
        break;

    case 0x719:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, lbl_8059F798, buf);
        break;

    case 0x71a:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, lbl_8059F7A0, buf);
        break;

    case 0x71b:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, lbl_8059F7A8, buf);
        break;

    case 0x71c:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, lbl_8059F7B0, buf);
        break;

    case 0x71d:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, lbl_8059F7B8, buf);
        break;

    case 0x71e:
        sprintf(buf, lbl_8059F7E8, arg2);
        APPEND(0x45c, lbl_8059F7C0, buf);
        break;

    default:
        fn_803732E0(arg0, table + 0x1d4);
        return 2;
    }

    return 0;
}
