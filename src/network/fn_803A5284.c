#include <string.h>
#include <types.h>
#pragma force_active on

typedef struct Entry {
    u16 index, pad02;
    u32 flags, address;
    u8 pad0c[8];
    u16 id;
    u8 pad16[4];
    u16 value;
    u8 pad1c[4];
    u32 state;
    u8 slot, active, pad26[2];
    u32 mask;
    u8 pad2c[0x88];
    char url[0x100];
} Entry;

typedef struct Context {
    u8 pad[0x14];
    u16 count;
} Context;

extern unsigned char *lbl_805A1170;
extern char lbl_8059FDF0[8], lbl_80492410[9];
extern u32 fn_80399AC8(void);
extern u16 fn_80399B14(void);
extern int fn_8039A274(void);
extern int fn_80399EE0(void *, u32, u32);
extern int fn_803A230C(s64 *);
extern int fn_803A4110(void);
extern int fn_803A50EC(Entry *);
extern s64 fn_803F1470(s64, s64);

static int same_address(u32 address)
{
    return (fn_80399AC8() & 0xFFFFFF00) == (address & 0xFFFFFF00);
}

static int same_id(u32 flags, u16 id)
{
    int result = 0;
    if ((flags & 0x40) && id == fn_80399B14())
        result = 1;
    return result;
}

static Context *get_context(void)
{
    if (lbl_805A1170 != 0)
        return (Context *)(lbl_805A1170 + 0x3600);
    return 0;
}

static inline int validate(Entry *entry)
{
    Context *context = get_context();
    int result;

    if (entry == 0)
        result = -3;
    else if (context == 0)
        result = -9;
    else if (fn_8039A274() == 0 &&
             (same_address(entry->address) & 1) == 0 &&
             !same_id(entry->flags, entry->id))
        result = -7;
    else if (entry->index != 0xFFFF && entry->index >= context->count)
        result = -3;
    else
        result = 0;
    return result;
}

static int check_entry(Entry *entry, Context *context)
{
    if (entry == 0)
        return -3;
    if (context == 0)
        return -9;
    if (entry->index != 0xFFFF && entry->index >= context->count)
        return -3;
    return 0;
}

static int check_url(Entry *entry)
{
    char *url = entry->url;
    int result = fn_80399EE0(url, 7, 0x100);

    if (result < 0)
        return result;
    if (strncmp(url, lbl_8059FDF0, 7) != 0 &&
        strncmp(url, lbl_80492410, 8) != 0)
        return -0x18;
    return 0;
}

static void store_time(unsigned char *base, u16 index, s64 time)
{
    u32 value = (u32)fn_803F1470(time, 60);
    Context *context = base ? (Context *)(base + 0x3600) : 0;
    *(u32 *)((u8 *)context + (u32)index * 16 + 0x88) = value;
}

static int set_time(Entry *entry, s64 time, u32 *index)
{
    unsigned char *base = lbl_805A1170;
    Context *context = base ? (Context *)(base + 0x3600) : 0;
    int result = check_entry(entry, context);

    if (result != 0)
        return result;
    *index = entry->index;
    if (*index == 0xFFFF)
        return -2;
    store_time(base, *index, time);
    return 0;
}

static inline int set_slot(Entry *entry, u8 slot)
{
    unsigned char *base = lbl_805A1170;
    Context *context;
    int result;

    if (base == 0)
        context = 0;
    else
        context = (Context *)(base + 0x3600);
    result = check_entry(entry, context);

    if (result != 0)
        return result;
    if (entry->active == 0)
        return -0x28;
    if (entry->mask == 0)
        return -1;
    if (slot > 31)
        return -3;
    result = 0;
    if (!((1U << slot) & entry->mask))
        result = -0x27;
    return result;
}

static inline int set_current_time(Entry *entry, u32 *index)
{
    s64 time;
    int result = fn_803A230C(&time);

    if (result >= 0) {
        result = set_time(entry, time, index);
        if (result < 0)
            return result;
    }
    return result;
}

static int finish_update(Entry *entry)
{
    int result;

    if (entry->active == 1) {
        while ((result = set_slot(entry, entry->slot)) == -0x27)
            entry->slot = (entry->slot + 1) & 31;
        if (result < 0)
            return result;
    }
    return fn_803A50EC(entry);
}

static void reset_error(Entry *entry)
{
    if (validate(entry) == 0) {
        entry->state = 0;
        entry->value = 0;
    }
}

static inline int update(Entry *entry, u32 *index)
{
    int result = validate(entry);

    if (result != 0)
        return result;
    if (entry->index == 0xFFFF || entry->index >= get_context()->count)
        return -3;
    result = set_current_time(entry, index);
    if (result < 0)
        return result;
    reset_error(entry);
    return finish_update(entry);
}

static inline int find_free(Entry *entry, u32 start, u16 end)
{
    u32 i;
    Context *context = get_context();

    if (entry == 0 || start > end || start >= context->count ||
        end > context->count)
        return -3;
    for (i = start; (u16)i < end; ++i) {
        if (*(u32 *)((u8 *)get_context() + ((u32)(u16)i << 4) + 0x80) == 0) {
            entry->index = (u16)i;
            return 0;
        }
    }
    return -6;
}

int fn_803A5284(Entry *entry, u32 start, u16 end)
{
    int result, error;
    Context *context;

    result = validate(entry);
    if (result != 0)
        return result;
    context = get_context();
    if (entry->index >= context->count && entry->index != 0xFFFF)
        error = -3;
    else {
        result = check_url(entry);
        error = 0;
        if (result < 0)
            error = result;
    }
    if (error < 0)
        return error;

    for (;;) {
        if (entry->index != 0xFFFF)
            return update(entry, &start);
        result = find_free(entry, start, end);
        if (result == -6) {
            result = fn_803A4110();
            if (result < 0)
                return result;
        } else if (result < 0) {
            return result;
        }
    }
}
