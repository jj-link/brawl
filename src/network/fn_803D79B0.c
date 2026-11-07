#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { u32 a, b; } Pair;
typedef struct { u32 flags; Pair pair; char pad[8]; int value; char pad2[36]; } Entry;
typedef struct { u16 pad, count; Entry entries[26]; } Global;
typedef struct { u32 a, b; void *p; } FnObj;
typedef struct { void (*fn)(Pair *, void *); void *arg; } Input;
extern Global lbl_805639C0;
extern Pair lbl_805643F0[];
extern int fn_803EC2F8(FnObj *);
int fn_803D79B0(Input *input, Entry **out) {
    u16 i;
    int j;
    Pair *pair;
    Entry *entry;
    FnObj obj;
    int result;
    *out = 0;
    if (lbl_805639C0.count >= 26) return 8;
    i = 0;
    for (j = 0; j < 13; j++) {
        if (!(lbl_805639C0.entries[i].flags & 1)) break;
        i++;
        if (!(lbl_805639C0.entries[i].flags & 1)) break;
        i++;
    }
    if (i >= 26) return 8;
    pair = &lbl_805643F0[i];
    input->fn(pair, input->arg);
    entry = &lbl_805639C0.entries[i];
    entry->pair = *pair;
    obj.a = 1;
    obj.b = 1;
    obj.p = (char *)entry + 0x30;
    result = fn_803EC2F8(&obj);
    if (!result) return 19;
    entry->value = result;
    entry->flags |= 1;
    lbl_805639C0.count++;
    *out = entry;
    return 0;
}