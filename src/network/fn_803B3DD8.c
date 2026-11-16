#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 position;
    s32 handle;
    u8 pad08[0x34];
    u32 field3c;
    u32 field40;
    u32 offset;
    u16 length;
    u16 pad4a;
    u8 data[0x20];
} State;

typedef struct {
    u16 name[0x105];
    u8 active;
    u8 sequence;
    u8 checksum;
    u8 pad20d;
    u8 text[0xe];
    u8 flags;
    u8 pad21d[0xf];
    u32 field22c;
    u32 field230;
    u32 field234;
    u32 field238;
    u16 field23c;
} Entry;

extern u8 fn_803B29D8(Entry *);
extern void fn_803B2A48(Entry *, void *);
extern void fn_803B2A90(Entry *, void *);
extern s32 fn_803B2BD8(Entry *, void *);
extern s32 fn_803B3C2C(State *, s32);
extern s32 fn_803B502C(State *);
extern void fn_803BEB70(void *, void *, u8);
extern s32 fn_803BEF50(Entry *, void *);
extern s32 fn_803C0080(s32, void *, u32, u16, u32, u32 *, s32);

s32 fn_803B3DD8(State *a, Entry *b, u32 c, s32 *d)
{
    u32 count;
    char temp[5];
    s32 result, old, status, readResult;
    u32 error = 0;
    u32 hi, lo;
    s32 n;

    if (a == 0 || b == 0)
        return 10;

    *d = 0;
    b->active = 0;
    b->sequence = 0;
    b->checksum = 0;

    while (fn_803B502C(a) == 0) {
        if (error != 0)
            return error;

        if (a->data[0] == 0xe5) {
            b->active = 0;
            b->name[0] = 0;
            goto advance;
        }

        if ((a->data[11] & 15) == 15) {
            if (fn_803B2BD8(b, a->data) != 0) {
                b->active = 0;
                b->name[0] = 0;
            }
            goto advance;
        }

        if (a->data[11] & 8) {
            b->active = 0;
            b->name[0] = 0;
            goto advance;
        }

        if (!(a->data[11] & 16)) {
            b->active = 0;
            b->name[0] = 0;
            goto advance;
        }

        hi = *(u16 *)(a->data + 0x1a);
        lo = *(u16 *)(a->data + 0x14);
        if (c != ((((lo >> 8) | ((lo & 0xff) << 8)) << 16) |
                  (((hi & 0xff) << 8) | (hi >> 8)))) {
            b->active = 0;
            b->name[0] = 0;
            goto advance;
        }

        *d = 1;
        fn_803B2A48(b, a->data);
        if (b->active != 0 && b->sequence == 1 &&
            b->checksum == fn_803B29D8(b)) {
            s32 flags;
            fn_803B2A90(b, a->data);
            b->field238 = a->offset;
            flags = b->flags & 16;
            b->field23c = a->length;
            b->field22c = a->field3c;
            if (flags && b->field234 != c) {
                b->active = 0;
                b->name[0] = 0;
                goto advance;
            }
            if (flags && b->field234 == 0)
                b->field234 = 1;
        }

        if (a->data[12] & 0x18) {
            fn_803BEB70(b->text, temp, a->data[12]);
            n = fn_803BEF50(b, temp);
            b->active = n / 13 + (n % 13 != 0);
            b->checksum = fn_803B29D8(b);
            b->sequence = 1;
        }

        fn_803B2A90(b, a->data);
        b->field238 = a->offset;
        b->field23c = a->length;
        b->field22c = a->field3c;
        return 0;

    advance:
        old = a->position;
        a->position = old + 1;
        result = fn_803B3C2C(a, 0);
        if (result != 0) {
            a->position = old;
            fn_803B3C2C(a, 0);
        } else {
            if (a->offset == 0xffffffffU) {
                status = 16;
            } else {
                readResult = fn_803C0080(a->handle, a->data, a->offset,
                                         a->length, 32, &count, 0);
                status = 17;
                if (count == 32)
                    status = readResult;
            }
            result = status & ((-status | status) >> 31);
        }
        error = result != 0 ? result : 0;
    }

    return 0;
}
