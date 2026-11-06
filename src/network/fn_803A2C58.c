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
    u8 pad16[6];
    u16 value;
} Entry;
typedef struct Context {
    u8 pad00[0x12];
    u16 limit;
    u16 count;
} Context;
extern unsigned char *lbl_805A1170;
extern int lbl_805A11C8;
extern int fn_8039A274(void);
extern u32 fn_80399AC8(void);
extern u16 fn_80399B14(void);
extern int fn_803A230C(s64 *);
extern s64 fn_803F1470(s64, s64);
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
static int check_entry(Entry *entry, Context *context) {
    if (entry == 0)
        return -3;
    if (context == 0)
        return -9;
    if (entry->index != 0xFFFF && entry->index >= context->count)
        return -3;
    return 0;
}
int fn_803A2C58(Entry *entry, u16 value) {
    s64 time;
    int result = validate(entry);
    if (result != 0)
        return result;
    if (lbl_805A11C8 == 0 && entry->index >= get_context()->limit &&
        !(entry->flags & 0x40000000) && (value < 180 || value > 10080))
        return -3;
    if (entry->value != value) {
        entry->value = value;
        if (entry->index != 0xFFFF) {
            time = 0;
            if (fn_803A230C(&time) >= 0) {
            unsigned char *base = lbl_805A1170;
            s64 end = time + entry->value * 60;
            Context *context = base ? (Context *)(base + 0x3600) : 0;
            if (check_entry(entry, context) == 0) {
                entry = (Entry *)(u32)entry->index;
                if ((u32)entry != 0xFFFF) {
                u32 v = (u32)fn_803F1470(end, 60);
                context = base ? (Context *)(base + 0x3600) : 0;
                *(u32 *)((u8 *)context + (u16)(u32)entry * 16 + 0x84) = v;
                }
            }
            }
        }
    }
    return 0;
}
