#pragma force_active on

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Record {
    int active;
    u8 pad04[4];
    void *handle;
    u8 pad0C[8];
    s8 id;
    u8 pad15[0x140 - 0x15];
} Record;

typedef struct Target {
    u8 pad[0x187A];
    s8 id;
} Target;

extern u32 lbl_805A1210;
extern Record *lbl_805A1220;
extern Target *fn_803C1514(void);
extern int fn_803C7D10(void *);

static inline Record *first_record(void)
{
    if (lbl_805A1210 != 0 && lbl_805A1220 != 0) {
        return lbl_805A1220;
    }
    return 0;
}

static inline Record *find_record(Target *target)
{
    Record *entry;

    if (target != 0) {
        Record *end;

        entry = first_record();
        end = entry + lbl_805A1210;
        for (; entry != end; ++entry) {
            if (entry->active != 0 && entry->id == target->id) {
                return entry;
            }
        }
    }
    return 0;
}

int fn_803C67E4(void)
{
    Record *entry = find_record(fn_803C1514());

    if (entry != 0 && entry->handle != 0) {
        return fn_803C7D10(entry->handle);
    }
    return -1;
}
