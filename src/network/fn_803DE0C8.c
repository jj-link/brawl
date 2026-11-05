#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct File {
    u8 pad[0x20];
    u8 shift;
} File;

typedef struct State {
    u32 position;
    File *file;
    u8 pad[0x34];
    File *source;
    s32 field40;
    u32 sector;
    u16 offset;
    u16 mask;
    u8 data[0x20];
    u8 shift;
} State;

typedef struct Entry {
    u16 name;
    u8 pad02[0x208];
    u8 count;
    u8 index;
    u8 checksum;
    u8 pad20d;
    u8 shortname[14];
    u8 flags;
    u8 pad21d[15];
    File *source;
    u8 pad230[4];
    u32 special;
    u32 sector;
    u16 offset;
} Entry;

extern char lbl_8059FEC8;
extern char lbl_8059FECC;
extern char lbl_805644C0[];

extern s32 fn_803D69AC(void *, char *);
extern u8 fn_803DCE4C(Entry *);
extern void fn_803DCEBC(Entry *, void *);
extern void fn_803DCF04(Entry *, void *);
extern s32 fn_803DD04C(Entry *, void *);
extern s32 fn_803DDF18(State *, s32);
extern s32 fn_803DEE48(State *);
extern s32 fn_803DF04C(State *, s32);
extern s32 fn_803E72B4(void *, void *, s32);
extern void fn_803E799C(void *, void *, u8);
extern s32 fn_803E7D7C(Entry *, void *);
extern u32 fn_803E8BD0(void *, s32 *);
extern s32 PFSEC_ReadData(File *, void *, u32, u16, u32, u32 *, s32);

static inline s32 seek(State *p, u32 pos)
{
    u32 count, old;
    s32 result, error, status;
    File *file = p->source;

    old = p->position;
    p->file = file;
    p->shift = file->shift - 5;
    p->field40 = -1;
    p->mask = (1 << p->shift) - 1;
    p->position = pos;
    result = fn_803DDF18(p, 0);
    if (result != 0) {
        p->position = old;
        fn_803DDF18(p, 0);
    } else {
        if (p->sector == 0xffffffffU) {
            error = 16;
        } else {
            status = PFSEC_ReadData(p->file, p->data, p->sector,
                                    p->offset, 32, &count, 0);
            error = 17;
            if (count == 32)
                error = status;
        }
        result = error & ((-error | error) >> 31);
    }
    return result;
}

static inline s32 advance(State *p)
{
    u32 count, old;
    s32 result, error, status;

    old = p->position;
    p->position = old + 1;
    result = fn_803DDF18(p, 0);
    if (result != 0) {
        p->position = old;
        fn_803DDF18(p, 0);
    } else {
        if (p->sector == 0xffffffffU) {
            error = 16;
        } else {
            status = PFSEC_ReadData(p->file, p->data, p->sector,
                                    p->offset, 32, &count, 0);
            error = 17;
            if (count == 32)
                error = status;
        }
        result = error & ((-error | error) >> 31);
    }
    return result & ((-result | result) >> 31);
}

static inline void found(State *p, Entry *e, s32 *out)
{
    fn_803DCF04(e, p->data);
    e->sector = p->sector;
    e->offset = p->offset;
    e->source = p->source;
    if ((e->flags & 0x10) && e->special == 0)
        e->special = 1;
    *out = 1;
}

s32 fn_803DE0C8(State *p, Entry *e, void *name, u8 include, u8 exclude,
                s32 *out)
{
    s32 result = 0;
    u32 special;
    s32 index;
    u32 attr;
    char temp[16];

    *out = 0;
    special = 0;
    if (fn_803D69AC(name, &lbl_8059FEC8) == 0 &&
        (e->flags & 0x10) && e->special == 1)
        return 2;

    if (fn_803D69AC(name, &lbl_8059FECC) == 0) {
        *out = 1;
        return 0;
    }

    e->count = 0;
    e->index = 0;
    e->checksum = 0;
    e->name = 0;
    if ((*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2)
        special = fn_803E8BD0(name, &index);

    if (special == 1) {
        result = seek(p, index - 1);
    again:
        if (result != 0)
            return result;
        if ((p->data[11] & 15) == 15) {
            if (fn_803DD04C(e, p->data) != 0)
                return 3;
            if (!(p->data[0] & 0x40))
                goto next_long;
        } else {
            return 0;
        }

        result = seek(p, index);
        if (result != 0)
            return result;
        attr = p->data[11];
        if (attr == 0)
            attr = 0x40;
        if (include & 0x80) {
            include &= 0x7f;
            exclude &= 0x7f;
            if ((include && include != (s32)(include & attr)) ||
                (exclude && exclude == (s32)(exclude & attr)))
                result = -1;
        } else if (include != 0x7f && attr != include &&
                   (!(attr & include) || (attr & exclude))) {
            result = -1;
        }
        if (result == -1)
            return 0;
        if (attr & 8)
            return 3;
        fn_803DCEBC(e, p->data);
        if (fn_803E72B4(e->shortname, name, 0)) {
            found(p, e, out);
            return 0;
        }
        goto done;

    next_long:
        result = fn_803DF04C(p, 0);
        goto again;
    }

    while (!fn_803DEE48(p)) {
        if (result != 0)
            return result;
        if (p->data[0] == 0)
            goto done;
        if (p->data[0] == 0xe5) {
            e->count = 0;
            e->name = 0;
        } else if ((p->data[11] & 15) == 15) {
            if (fn_803DD04C(e, p->data)) {
                e->count = 0;
                e->name = 0;
            }
        } else {
            attr = p->data[11];
            if (!attr)
                attr = 0x40;
            if (include & 0x80) {
                include &= 0x7f;
                exclude &= 0x7f;
                if ((include && include != (s32)(include & attr)) ||
                    (exclude && exclude == (s32)(exclude & attr)))
                    result = -1;
            } else if (include != 0x7f && attr != include &&
                       (!(attr & include) || (attr & exclude))) {
                result = -1;
            }
            if (result == -1) {
                e->count = 0;
                e->name = 0;
            } else {
                if (attr & 8) {
                    e->count = 0;
                    e->name = 0;
                }
                fn_803DCEBC(e, p->data);
                if (e->count && e->index == 1 &&
                    e->checksum == fn_803DCE4C(e) &&
                    fn_803E72B4(e, name, 1)) {
                    found(p, e, out);
                    return 0;
                }
                if (fn_803E72B4(e->shortname, name, 0)) {
                    if (p->data[12] & 0x18) {
                        s32 len;
                        fn_803E799C(e->shortname, temp, p->data[12]);
                        len = fn_803E7D7C(e, temp);
                        e->count = len / 13 + (len % 13 != 0);
                        e->checksum = fn_803DCE4C(e);
                        e->index = 1;
                    }
                    found(p, e, out);
                    return 0;
                }
                e->count = 0;
                e->name = 0;
            }
        }
        result = advance(p);
    }

done:
    return 0;
}
