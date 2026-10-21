#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Entry {
    u16 index;
    u16 pad02;
    u32 flags;
    u32 address;
    unsigned char pad0C[8];
    u16 id;
} Entry;

typedef struct Context {
    unsigned char pad00[0x14];
    u16 count;
} Context;

extern unsigned char *lbl_805A1170;
extern int fn_8039A274(void);
extern u32 fn_80399AC8(void);
extern u16 fn_80399B14(void);

static int same_address(u32 address) {
    return (fn_80399AC8() & 0xFFFFFF00) == (address & 0xFFFFFF00);
}

static int same_id(u32 flags, u16 id) {
    int result = 0;

    if ((flags & 0x40) && id == fn_80399B14()) {
        result = 1;
    }
    return result;
}

static Context *get_context(void) {
    if (lbl_805A1170 != 0) {
        return (Context *)(lbl_805A1170 + 0x3600);
    }
    return 0;
}

int fn_803A2910(Entry *entry, int check) {
    Context *context = get_context();

    if (entry == 0) {
        return -3;
    }
    if (context == 0) {
        return -9;
    }
    if (check != 0 && fn_8039A274() == 0) {
        if ((same_address(entry->address) & 1) == 0) {
            if (!same_id(entry->flags, entry->id)) {
                return -7;
            }
        }
    }
    if (entry->index != 0xFFFF && entry->index >= context->count) {
        return -3;
    }
    return 0;
}
