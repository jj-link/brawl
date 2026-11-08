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
extern int lbl_805A1214;
extern Target *fn_803C1514(void);
extern void fn_803C7D64(void *, int);
extern int fn_803C2A2C(int, int);
extern int fn_803C2AB0(void);

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

int fn_803C5348(int arg0)
{
    int result;
    Record *entry = find_record(fn_803C1514());

    if (entry != 0 && entry->handle != 0) {
        fn_803C7D64(entry->handle, 0);
    }
    result = fn_803C2A2C(arg0, 0);
    if (result == 0) {
        int tmp = fn_803C2AB0();
        if (tmp != 0) {
            lbl_805A1214 = tmp;
        }
    }
    return result;
}
