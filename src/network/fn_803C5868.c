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

typedef struct Inner {
    u8 pad[0x38];
    Target *target;
} Inner;

typedef struct Object {
    u8 pad[8];
    Inner *inner;
} Object;

extern u32 lbl_805A1210;
extern Record *lbl_805A1220;
extern void fn_803C7D64(void *, int);
extern int fn_803C2C08(Object *, int, int);
extern int fn_803C2AB0(void);

static inline Record *first_record(void)
{
    if (lbl_805A1210 != 0 && lbl_805A1220 != 0) {
        return lbl_805A1220;
    }
    return 0;
}

static inline Record *find_record(Object *obj)
{
    Record *entry = 0;
    if (obj != 0) {
        Inner *inner = obj->inner;
        if (inner != 0) {
            Record *end;
            Target *target = inner->target;
            if (target != 0) {
                entry = first_record();
                end = entry + lbl_805A1210;
                for (; entry != end; ++entry) {
                    if (entry->active != 0 && entry->id == target->id) {
                        return entry;
                    }
                }
            }
            entry = 0;
        }
    }
    return entry;
}

int fn_803C5868(Object *arg0, int arg1, int arg2)
{
    Record *entry = find_record(arg0);
    if (entry != 0 && entry->handle != 0) {
        fn_803C7D64(entry->handle, 0);
    }
    if (fn_803C2C08(arg0, arg1, arg2) == 0) {
        return 0;
    }
    return fn_803C2AB0();
}
