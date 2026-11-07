#include <types.h>
#pragma force_active on
typedef struct Entry {
    u16 index;
    u16 pad02;
    u32 flags;
    u32 address;
    u32 title_hi;
    u32 title_lo;
    u16 id;
    unsigned char pad16[0x1e6];
    u8 mode;
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
int fn_803A4FCC(Entry *entry, u8 mode) {
    int result = validate(entry);
    if (result != 0)
        return result;
    if ((mode & 1) && (mode & 2))
        return -3;
    entry->mode = mode;
    return 0;
}