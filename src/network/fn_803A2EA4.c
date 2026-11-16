#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct Entry {
    u16 index;
    u16 pad02;
    u32 flags;
    u32 address;
    u32 title_hi;
    u32 title_lo;
    u16 id;
} Entry;

typedef struct Context {
    unsigned char pad00[0x14];
    u16 count;
} Context;

extern unsigned char *lbl_805A1170;
extern int lbl_805A11C8;
extern char lbl_8059FDF0[8];
extern char lbl_80492410[];
extern int fn_8039A274(void);
extern u32 fn_80399AC8(void);
extern u16 fn_80399B14(void);
extern int fn_80399EE0(const char *, int, int);
extern int fn_80399F5C(void *, const char *, int);

static int same_address(u32 address) {
    return (fn_80399AC8() & 0xFFFFFF00) == (address & 0xFFFFFF00);
}

static int same_id(u32 flags, u16 id) {
    int result = 0;
    if ((flags & 0x40) && id == fn_80399B14())
        result = 1;
    return result;
}

static Context *get_context(void) {
    if (lbl_805A1170 != 0)
        return (Context *)(lbl_805A1170 + 0x3600);
    return 0;
}

static inline int validate(Entry *entry) {
    Context *context = get_context();
    int result;
    if (entry == 0)
        result = -3;
    else if (context == 0)
        result = -9;
    else if (fn_8039A274() == 0 && (same_address(entry->address) & 1) == 0 && !same_id(entry->flags, entry->id))
        result = -7;
    else if (entry->index != 0xFFFF && entry->index >= context->count)
        result = -3;
    else
        result = 0;
    return result;
}

static inline int check_name(const char *name) {
    int result = fn_80399EE0(name, 7, 0x100);
    if (result < 0)
        return result;
    if (strncmp(name, lbl_8059FDF0, 7) != 0 && strncmp(name, lbl_80492410, 8) != 0)
        return -0x18;
    return 0;
}

int fn_803A2EA4(Entry *entry, const char *name) {
    int result = validate(entry);
    if (result != 0)
        return result;
    result = check_name(name);
    if (result < 0)
        return result;
    if (lbl_805A11C8 == 0 && (entry->flags & 4) && strncmp(name, lbl_8059FDF0, 7) == 0)
        return -3;
    fn_80399F5C((unsigned char *)entry + 0xB4, name, 0xEC);
    return 0;
}
