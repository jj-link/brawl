#pragma force_active on

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Record {
    int active;
    u8 pad04[0x10];
    s8 id;
    u8 pad15[0x140 - 0x15];
} Record;

typedef struct Target {
    u8 pad[0x187A];
    s8 id;
} Target;

extern u32 lbl_805A1210;
extern Record *lbl_805A1220;

Record *fn_803C4338(Target *target)
{
    Record *entry;
    Record *end;
    u32 count;

    if (target != 0) {
        count = lbl_805A1210;
        if (count != 0 && lbl_805A1220 != 0) {
            entry = lbl_805A1220;
        } else {
            entry = 0;
        }
        end = entry + count;
        for (; entry != end; ++entry) {
            if (entry->active != 0 && entry->id == target->id) {
                return entry;
            }
        }
    }
    return 0;
}
