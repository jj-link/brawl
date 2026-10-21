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

s32 fn_803C7A70(s32 arg0, u32 arg1, s32 *arg2, s32 arg3, s32 *arg4)
{
    u32 index;
    LblEntry *entry;
    u32 limit;
    u32 type;

    *arg4 = 0;
    index = fn_803C43AC(arg3);
    if (index < 26U) {
        entry = &lbl_80563590[index];
    } else {
        entry = 0;
    }
    if (entry != 0) {
        limit = entry->unkC;
    } else {
        limit = 0;
    }
    if (arg1 < limit) {
        if ((s32)arg1 != 0) {
            if (arg1 != 1U) {
                goto failure;
            }
            {
                index = fn_803C43AC(arg3);
                if (index < 26U) {
                    entry = &lbl_80563590[index];
                } else {
                    entry = 0;
                }
                if (entry != 0) {
                    type = entry->unk8;
                } else {
                    type = 1;
                }
                if (type != 2U) {
                    goto failure;
                }
            }
        }
        *arg2 = arg0;
        *arg4 = 0;
        return 0;
failure:
        *arg4 = -22;
        return 0;
    }
    return 1;
}
