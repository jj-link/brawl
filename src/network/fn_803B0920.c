#include <types.h>
#pragma force_active on

typedef struct Context {
    u16 size;
    u8 pad02[4];
    u8 count;
    u8 pad07[9];
    u32 sector;
    u8 pad14[8];
    s32 mode;
} Context;

typedef struct Header {
    u32 words[2];
    u32 *current;
    u32 words2[9];
    u32 *last;
    u32 word34;
} Header;

typedef struct State {
    u32 value;
    void *file;
    Header header;
    u32 field40;
    u32 field44;
    u16 field48;
    u16 mask;
    u8 buffer[0x20];
    u8 shift;
} State;

typedef struct Obj {
    u16 name[0x105];
    u8 count;
    u8 pad20b[3];
    char text[13];
    u8 flags;
    u8 size;
    u8 kind;
    u16 a, b, c, d, e;
    u32 f228;
    Context *owner;
    u32 f230;
    u32 f234;
    u32 f238;
    u16 f23c, f23e;
} Obj;

typedef struct Output {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0c;
    u32 field10;
    u32 flags;
    u8 count;
    u8 has_name;
    u8 kind;
    u8 size;
    u8 data[0x208];
    u16 date;
    u16 time;
    u32 field228;
    u8 field22c;
    char text[13];
    char name[0x20a];
    u8 extra[0x208];
    u16 extra_text[13];
    u16 extra_name[0x105];
} Output;

typedef struct Buffer {
    u8 pad[8];
    u8 *data;
} Buffer;

extern char lbl_8053B248[];

extern int fn_803BE3C8(void *, void *, void *);
extern int fn_803B5638(void *, void *, void *, void *, int);
extern u16 fn_803A9C74(void *, int);
extern u32 fn_803A9A78(void *);
extern void *fn_803A9AA8(void *, u32);
extern void fn_803BEE24(void *, void *);
extern void fn_803A9A80(void *, void *);
extern void fn_803BF90C(void *, void *, void *);
extern void fn_803B847C(void *, void *, void *, void *);
extern void fn_803B841C(void *, void *);
extern int fn_803B4F28(void *, int);
extern void fn_803A9644(void *, void *, int);
extern int fn_803B555C(void *, void *, void *, int, int, int *, int);
extern int fn_803BEFE8(void *, void *);
extern int fn_803B3968(void *, void *);
extern int fn_803BEF50(void *, void *);
extern void fn_803AA01C(void *, void *);
extern u8 fn_803B3BA8(u16 *, u16 *);
extern int fn_803B3290(void *, u8, void *, u32 *, void *, u32 *);
extern void fn_803BFF54(void *, u32);
extern int fn_803B7080(void *, int, int, u32 *);
extern int fn_803AFD48(void *, int, Buffer **);
extern void fn_803A976C(void *, int, u16);
extern void fn_803B2968(void *);
extern void fn_803B2B3C(void *, void *);
extern void fn_803B29A0(void *);
extern int fn_803C0440(void *, void *, u32, u16, u16, u32 *, int);
extern void fn_803AFE4C(void *, void *);
extern u8 fn_803B29D8(void *);
extern void fn_803B2DB0(void *, void *, u8, u8, int);
extern int fn_803B37BC(void *, int);
extern void fn_803A9884(void *, void *);

int fn_803B0920(Context *ctx, void *arg1, void *arg2, Output *out)
{
    u32 *next;
    u8 count;
    int found;
    Buffer *buffer;
    u32 first;
    u32 written;
    u32 value;
    u32 blocks[2];
    u8 init[0x10];
    u8 key[0x10];
    u8 state2[0x10];
    u8 entry[0x20];
    Header header;
    State state;
    u8 initial_name[0x200];
    Obj copy;
    Obj obj;
    u32 i;
    u32 j;
    u32 sector;
    u16 length;
    u16 initial_offset;
    u32 saved;
    u8 kind;
    int result;
    int has_text;

    count = 0;
    first = 0;
    result = fn_803BE3C8(arg1, init, key);
    if (result)
        return result;

    result = fn_803B5638(&state, &copy, ctx, init, 1);
    if (result)
        return result;
    if (!(((u8 *)&copy)[0x21c] & 0x10))
        return 0x14;

    length = fn_803A9C74(key, 1);
    if (length > 0xff)
        return 1;
    if ((u32)length + copy.f230 > 0x103)
        return 2;

    if (fn_803A9A78(key) == 2)
        fn_803BEE24(initial_name, fn_803A9AA8(key, 1));
    fn_803A9A80(key, initial_name);

    if (out) {
        out->field00 = 0;
        out->field04 = 0;
        out->field0c = copy.f234;
        out->field08 = *(u32 *)((u8 *)&copy + 0x22c);
        out->size = 0x10;
        if (fn_803A9A78(key) == 1) {
            fn_803BF90C(out->data, 0, key);
            out->flags |= 1;
        } else {
            fn_803BF90C(out->data, out->extra, key);
            out->flags |= 2;
        }
    }

    fn_803B847C(&header, state2, ctx, &copy.f234);
    state.header = header;
    fn_803B841C(&state.header, &copy.f234);
    result = fn_803B4F28(&state, 0);
    if (result)
        return result;

    fn_803A9644(&obj, &copy, 0x240);
    result = fn_803B555C(&state, &obj, key, 0x10, 0, &found, 1);
    if (result)
        return result;
    if (found)
        return 8;

    has_text = fn_803BEFE8(obj.text, key);
    if (has_text && (s8)obj.text[0] == 0)
        return 1;
    if (has_text) {
        result = fn_803B3968(&copy, obj.text);
        if (result)
            return result;
        if (fn_803A9A78(key) == 1)
            length = fn_803BEF50(&obj, fn_803A9AA8(key, 1));
        else
            fn_803AA01C(&obj, fn_803A9AA8(key, 1));
    } else {
        obj.name[0] = 0;
    }

    obj.f234 = 0;
    obj.f228 = 0;
    obj.owner = ctx;
    obj.flags = 0;
    obj.size = 0x10;
    obj.kind = fn_803B3BA8(&obj.b, &obj.a);
    initial_offset = obj.f23c;
    obj.c = obj.b;
    obj.d = obj.a;
    obj.e = obj.b;

    if (obj.name[0] && !(obj.flags & 0x18)) {
        count = length / 13U + (length % 13U != 0);
        result = fn_803B3290(&obj, count + 1, &header, blocks, key, &value);
        if (result)
            return result;
        if ((*(u32 *)(lbl_8053B248 + 0x3c) & 2) == 2)
            fn_803BFF54(obj.text, value);
    } else {
        result = fn_803B3290(&obj, 1, &header, blocks, key, &value);
        if (result)
            return result;
    }

    fn_803B841C(&header, &obj.f234);
    result = fn_803B7080(&header, 0, 1, &first);
    if (result)
        return result;
    if (first == 0xffffffffU)
        return 6;

    saved = header.last[1];
    if (ctx->mode == 2 && *state.header.current == ctx->sector &&
        initial_offset == 0 && saved == ctx->sector) {
        state.header = header;
        result = fn_803B4F28(&state, count);
        if (result)
            return result;
        if (state.buffer[0] == 0) {
            fn_803B841C(&header, &obj.f234);
            *header.current = 0;
            header.last[1] = 0;
            saved = ctx->sector + 1;
            result = fn_803B7080(&header, 0, 1, &first);
            if (result)
                return result;
        }
    }

    result = fn_803AFD48(ctx, -1, &buffer);
    if (result)
        return result;

    fn_803A976C(buffer->data, 0, ctx->size);
    i = ctx->count;
    while (i != 0) {
        if (i == 1) {
            fn_803B2968(buffer->data);
            fn_803B2B3C(buffer->data, &obj);
            fn_803B29A0(buffer->data + 0x20);
            if (copy.f238 == 0xffffffffU)
                obj.f234 = 0;
            else
                obj.f234 = copy.f234;
            fn_803B2B3C(buffer->data + 0x20, &obj);
        }
        result = fn_803C0440(ctx, buffer->data, i + first - 1,
                             0, ctx->size, &written, 0);
        if (result)
            break;
        if (written != ctx->size) {
            result = 0x11;
            break;
        }
        i--;
    }
    fn_803AFE4C(ctx, buffer);
    if (result)
        return result;

    obj.count = count;
    sector = obj.f238;
    kind = fn_803B29D8(&obj);
    if (!(obj.flags & 0x18)) {
        j = count;
        next = blocks;
        while (j >= 1) {
            fn_803B2DB0(entry, &obj, j, kind, j == count);
            result = fn_803C0440(ctx, entry, sector, obj.f23c,
                                 0x20, &written, 0);
            if (result)
                return result;
            if (written != 0x20)
                return 0x11;
            obj.f23c += 0x20;
            if (obj.f23c >= ctx->size) {
                obj.f23c = 0;
                sector = *next++;
            }
            j--;
        }
        obj.f238 = sector;
    }

    obj.f234 = saved;
    result = fn_803B37BC(&obj, 0);
    if (result)
        return result;

    if (out) {
        out->field10 = value + 1;
        fn_803A9884(out->text, obj.text);
        if ((out->flags & 2) == 2)
            fn_803BEF50(out->extra_text, out->text);

        if (obj.name[0]) {
            if ((*(u32 *)(lbl_8053B248 + 0x3c) & 2) == 2) {
                *(u32 *)(lbl_8053B248 + 0x3c) =
                    (*(u32 *)(lbl_8053B248 + 0x3c) & ~3U) | 1;
                fn_803BEE24(out->name, &obj);
                *(u32 *)(lbl_8053B248 + 0x3c) =
                    (*(u32 *)(lbl_8053B248 + 0x3c) & ~3U) | 2;
            } else {
                fn_803BEE24(out->name, &obj);
            }
            if ((out->flags & 2) == 2)
                fn_803AA01C(out->extra_name, &obj);
            out->kind = kind;
            out->has_name = 1;
        } else {
            out->name[0] = 0;
            if ((out->flags & 2) == 2)
                out->extra_name[0] = 0;
            out->has_name = 0;
            out->kind = 0;
        }
        out->field228 = obj.f228;
        out->date = obj.d;
        out->time = obj.e;
        out->field22c = obj.size;
        out->count = obj.count;
    }
    return 0;
}
