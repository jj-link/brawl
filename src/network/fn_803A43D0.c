#include <stdio.h>
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
extern char lbl_8049241C[];
extern char lbl_80492434[];
extern char lbl_8059FE00[4];
extern int fn_8039A274(void);
extern u32 fn_80399AC8(void);
extern u16 fn_80399B14(void);
extern int fn_8020A710(void *, int, int);
extern int fn_803A5A8C(void *, int, void *, int, int);

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
static int check_entry(Entry *entry) {
    Context *context = get_context();
    if (entry == 0)
        return -3;
    if (context == 0)
        return -9;
    if (entry->index != 0xFFFF && entry->index >= context->count)
        return -3;
    return 0;
}
static int get_path(Entry *entry, char *buf) {
    int result = check_entry(entry);
    if (result != 0)
        return result;
    if (*(int *)((char *)entry + 8) == 0)
        return -3;
    snprintf(buf, 0x40, lbl_8049241C, entry->title_hi, entry->title_lo);
    return 0;
}
static int get_file_path(Entry *entry, char *buf, const char *name) {
    const char *filename = name;
    int result = check_entry(entry);
    int len;
    if (result != 0)
        return result;
    if (entry->address == 0)
        return -3;
    result = get_path(entry, buf);
    if (result < 0)
        return result;
    len = strlen(buf);
    snprintf(buf + len, 0x40 - len, lbl_8059FE00, filename);
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
int fn_803A43D0(Entry *entry, void *output) {
    char buf[0x40];
    int result = validate(entry);
    if (result != 0)
        return result;
    if (output == 0)
        return -3;
    result = get_file_path(entry, buf, lbl_80492434);
    if (result < 0)
        return result;
    result = fn_8020A710(buf, 0x3d, 0);
    if (result != 0 && result != -6)
        return -0x15;
    return fn_803A5A8C(buf, 0, output, 0x100, 0);
}