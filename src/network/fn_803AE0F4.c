#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern s32 fn_803AB808(void);
extern s32 fn_803AB1B4(u8 *, s32 *);
extern s32 fn_803ADD50(u8 *, s32, s32 *);

typedef struct Node {
    u8 pad[0x18];
    u32 size;
    u8 rest[0x18];
} Node;

typedef struct State {
    u8 pad[0x1A4];
    Node nodes[26];
} State;

extern State lbl_8053A6E0;

typedef struct Part {
    s32 pad[3];
    s32 off;
    s32 sz;
} Part;

static inline void validate(s32 idx, s32 *tbl, s32 *out) {
    Node *ent = &lbl_8053A6E0.nodes[(u8)idx];
    Part *p = (Part *)(tbl + 2);
    s32 i;

    for (i = 0; i < 4; i++) {
        s32 off = p[i].off;
        s32 sz = p[i].sz;

        if ((u32)sz > (u32)(-1 - off) ||
            (u32)(off + sz) > ent->size) {
            *out = 0;
            return;
        }
        if (off != 0) {
            *out = 1;
        }
    }
}

s32 fn_803AE0F4(s32 idx, u8 *buf, s32 *out) {
    struct {
        s32 a;
        s32 b;
        s32 tbl[22];
    } s;
    s32 temp;

    if (idx == 0 || buf == 0 || out == 0) {
        return 1;
    }
    temp = fn_803AB808();
    if (temp != 0) {
        return temp;
    }
    *out = 0;
    if (buf[0x1FE] != 0x55 || buf[0x1FF] != 0xAA) {
        return 0;
    }
    fn_803ADD50(buf, 0, s.tbl);
    validate(idx, s.tbl, out);
    if (*out == 0 && s.tbl[5] == 0 && s.tbl[10] == 0 &&
        s.tbl[15] == 0 && s.tbl[20] == 0) {
        fn_803AB1B4(buf, &s.a);
        if (s.a == 0) {
            *out = 1;
        } else {
            *out = 0;
        }
    }
    return 0;
}
