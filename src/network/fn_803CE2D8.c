#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

typedef struct Entry {
    u16 count;
    u16 pad2;
    s32 offset;
} Entry;

typedef struct Struct_803CE468 {
    char pad[0x94];
    s32 field_94;
    s32 field_98;
} Struct_803CE468;

extern s32 lbl_8041ACF4[];
extern s32 fn_803CD270(void);
extern Struct_803CE468 *fn_803CD2E0(void);
extern s32 fn_803CDAC8(s32 dst, Struct_803CE468 *p, s32 idx, u32 arg);
extern void *memcpy(void *dst, const void *src, u32 n);

s32 fn_803CE2D8(s32 arg0, u32 arg1, s32 arg2) {
    s32 idx;
    Struct_803CE468 *p;
    Struct_803CE468 *q;
    Entry *e;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r9;
    s32 temp_r5;
    s32 temp_r0;
    s32 var;

    idx = lbl_8041ACF4[arg0];
    if (fn_803CD270() == 0) {
        arg2 = 0;
    } else {
        p = fn_803CD2E0();
        if (p == 0) {
            arg2 = 0;
        } else {
            e = (Entry *)((char *)p + idx * 8);
            if (arg1 >= e->count) {
                arg2 = 0;
            } else {
                if (fn_803CD270() == 0) {
                    var = 0;
                } else {
                    q = fn_803CD2E0();
                    if (q == 0) {
                        var = 0;
                    } else {
                        var = q->field_98;
                    }
                }
                if (var != 0) {
                    temp_r6 = p->field_94;
                    temp_r9 = e->offset;
                    temp_r7 = temp_r6 + temp_r9;
                    temp_r8 = ((s32 *)temp_r7)[(u16)arg1];
                    temp_r5 = e->count * 4;
                    temp_r0 = ((s32 *)temp_r7)[arg1 + 1];
                    memcpy((void *)arg2, (char *)temp_r6 + (temp_r9 + temp_r8 + temp_r5 + 4),
                           temp_r0 - temp_r8);
                } else {
                    arg2 = fn_803CDAC8(arg2, p, idx, arg1);
                }
            }
        }
    }
    return arg2;
}
