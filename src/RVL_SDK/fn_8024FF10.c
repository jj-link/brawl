#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b, c, d, e, f; } Block;
typedef struct {
    char pad[0x28];
    u16 field28;
    char pad2[8];
    u16 field32;
} Inner;
typedef struct {
    char pad[0x10];
    Inner *inner;
    char pad2[0x24];
    u16 field38;
    char pad3[2];
    u16 field3c;
    char pad4[0x1a];
    Block block;
} Target;
typedef struct {
    char pad[2];
    u8 flag2;
    char pad2;
    u16 value4;
    u8 flag6;
    char pad3;
    Block block;
    u8 flag20;
    char pad4;
    u16 value22;
} Input;
extern void *fn_8022EFF8(int);
extern void fn_802465F8(void *, u32, u32);
void fn_8024FF10(Target *a, Input *b)
{
    Inner *p;
    u16 v;
    if (b->flag2) {
        u16 value = b->value4;
        a->field38 = value;
        if (value > 0x69b) {
            b->value4 = 0x69b;
            a->field38 = 0x69b;
        }
    }
    if (b->flag6) {
        a->block = b->block;
    }
    if (b->flag20 && b->value22) {
        a->field3c = b->value22;
        p = a->inner;
        if (b->value22 < p->field32) {
            p->field32 = b->value22;
            if (b->value22 <= 0x4ff) {
                v = (b->value22 * 8 + 3) / 5;
                {
                    void *q = fn_8022EFF8(2);
                    if (q)
                        fn_802465F8(q, p->field28, v);
                }
            }
        }
    }
}