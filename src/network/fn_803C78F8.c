#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct LblEntry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} LblEntry;

extern u32 fn_803C43AC(s32);
extern LblEntry lbl_80563590[];

s32 fn_803C78F8(s32 arg0, s32 arg1, u32 arg2, s32 *arg3, s32 arg4, s32 *arg5, s32 (*arg6)(s32, s32, s32 *), s32 (*arg7)(s32))
{
    s32 sp8;
    u32 index;
    LblEntry *entry;
    u32 limit;

    *arg5 = 0;
    index = fn_803C43AC(arg4);
    if (index < 0x1AU) {
        entry = &lbl_80563590[index];
    } else {
        entry = 0;
    }
    if (entry != 0) {
        limit = entry->unkC;
    } else {
        limit = 0;
    }
    if (arg2 < limit) {
        if ((s32)arg2 == 0) {
            s32 result = arg6(arg4, arg1, &sp8);
            *arg5 = result;
            if (result != 0) {
                return 0;
            }
            *arg3 = arg0;
            *arg5 = 0;
            return 0;
        }
        if (arg2 == 1U) {
            u32 idx2;
            LblEntry *entry2;
            u32 type;
            idx2 = fn_803C43AC(arg4);
            if (idx2 < 0x1AU) {
                entry2 = &lbl_80563590[idx2];
            } else {
                entry2 = 0;
            }
            if (entry2 != 0) {
                type = entry2->unk8;
            } else {
                type = 1;
            }
            if (type == 2U) {
                s32 result = arg7(arg1);
                *arg5 = result;
                if (result != 0) {
                    return 0;
                }
                *arg3 = arg0;
                *arg5 = 0;
                return 0;
            }
        }
        *arg5 = -0x16;
        return 0;
    }
    return 1;
}
