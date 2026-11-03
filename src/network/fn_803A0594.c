#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef struct {
    char pad[0x10];
    u32 flags;
    u32 unused;
    u64 value;
    u32 id;
    u32 condition;
} A;
typedef struct {
    u32 unused;
    u32 flags;
    u32 unused2;
    u32 id;
    u32 unused3;
    u32 condition;
    char pad[8];
    u64 value;
} B;
extern int fn_8039B4C8(B *);
int fn_803A0594(A *a, B *b) {
    u32 flags;
    u32 x, y;
    int result;
    if (!fn_8039B4C8(b)) return 0;
    flags = a->flags;
    if ((flags & 1) && !(b->flags & 8)) return 0;
    if ((flags & 0x20) && a->id != b->id) return 0;
    if (flags & 0x10) {
        if (!(b->flags & 1)) return 0;
        if (a->value != b->value) return 0;
    }
    if (flags & 0x100) {
        x = (u16)a->condition;
        y = (u16)b->condition;
        switch (a->condition >> 16) {
        case 0: result = y != x; break;
        case 1: result = y == x; break;
        case 2: result = y <= x; break;
        case 3: result = x <= y; break;
        case 4: result = (y & x) != 0; break;
        default: result = 0; break;
        }
        if (!result) return 0;
    }
    return 1;
}