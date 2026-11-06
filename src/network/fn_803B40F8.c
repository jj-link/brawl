#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct File {
    u8 pad00[0x10];
    u32 id;
    u8 pad14[8];
    s32 kind;
    u8 shift;
} File;

typedef struct State {
    u32 position;
    File *file;
    u8 pad08[8];
    u32 *type;
    u8 pad14[0x28];
    File *source;
    s32 field40;
    u32 offset;
    u16 length;
    u16 mask;
    u8 data[0x20];
    u8 shift;
} State;

typedef struct Entry {
    u16 name[0x105];
    u8 count;
    u8 valid;
    u8 checksum;
    u8 pad20D;
    u8 shortname[0xE];
    u8 flags;
    u8 pad21D[0xF];
    File *source;
    u8 pad230[4];
    s32 field234;
    u32 offset;
    u16 length;
} Entry;

extern s32 fn_803A9D54(s32, void *);
extern s32 fn_803A9DF8(s32, void *, s32, s32, s32);
extern u8 fn_803B29D8(Entry *);
extern void fn_803B2A48(Entry *, void *);
extern void fn_803B2A90(Entry *, void *);
extern s32 fn_803B2BD8(Entry *, void *);
extern s32 fn_803B35D0(File *, Entry *);
extern s32 fn_803B3C2C(State *, s32);
extern s32 fn_803B502C(State *);
extern s32 fn_803B5230(State *, s32);
extern s32 fn_803BE470(void *, s32, s32);
extern void fn_803BEB70(void *, void *, u8);
extern s32 fn_803BEF50(Entry *, void *);
extern u32 fn_803BFDB0(s32, s32 *);
extern s32 fn_803C0080(File *, void *, u32, u16, u32, u32 *, s32);
extern char lbl_8053B248[];
extern char lbl_8059FE38[4];
extern char lbl_8059FE3C[4];
extern char lbl_8059FE40[3];
extern char lbl_8059FE44[3];
extern char lbl_8059FE48[2];

static inline s32 seek_entry(State *self, u32 value)
{
    u32 count;
    s32 result;
    u32 old;
    s32 error;
    s32 readResult;
    u8 shift;

    self->file = self->source;
    if (self->file == 0)
        return 10;
    old = self->position;
    shift = self->file->shift - 5;
    self->field40 = -1;
    self->shift = shift;
    self->mask = (1 << self->shift) - 1;
    self->position = value;
    result = fn_803B3C2C(self, 0);
    if (result != 0) {
        self->position = old;
        fn_803B3C2C(self, 0);
    } else {
        if (self->offset == 0xFFFFFFFFU) {
            error = 16;
        } else {
            readResult = fn_803C0080(self->file, self->data, self->offset,
                                    self->length, 32, &count, 0);
            error = 17;
            if (count == 32)
                error = readResult;
        }
        result = error != 0 ? error : 0;
    }
    return result;
}

static inline s32 next_entry(State *self)
{
    u32 count;
    u32 old;
    s32 result;
    s32 error;
    s32 readResult;
    old = self->position;
    self->position = old + 1;
    result = fn_803B3C2C(self, 0);
    if (result != 0) {
        self->position = old;
        fn_803B3C2C(self, 0);
    } else {
        if (self->offset == 0xFFFFFFFFU) {
            error = 16;
        } else {
            readResult = fn_803C0080(self->file, self->data, self->offset,
                                    self->length, 32, &count, 0);
            error = 17;
            if (count == 32)
                error = readResult;
        }
        result = error != 0 ? error : 0;
    }
    return result != 0 ? result : 0;
}

static inline void set_entry(State *self, Entry *entry)
{
    fn_803B2A90(entry, self->data);
    entry->offset = self->offset;
    entry->length = self->length;
    entry->source = self->source;
    if ((entry->flags & 0x10) && entry->field234 == 0)
        entry->field234 = 1;
}

s32 fn_803B40F8(State *self, Entry *entry, s32 path, u8 include,
                 u8 exclude, s32 *found, u32 mode)
{
    void *name;
    s32 index;
    s32 status;
    s32 result = 0;
    u32 special = 0;
    *found = 0;
    if (*self->type == 1 &&
        (!fn_803A9DF8(path, lbl_8059FE38, 1, 0, 3) ||
         !fn_803A9DF8(path, lbl_8059FE3C, 1, 0, 3) ||
         !fn_803A9D54(path, lbl_8059FE40)))
        return 2;

    if (!fn_803A9DF8(path, lbl_8059FE44, 1, 0, 2) ||
        !fn_803A9D54(path, lbl_8059FE48)) {
        if (mode == 0 &&
            (*self->type == 1 ||
             (self->source->kind == 2 && *self->type == self->source->id))) {
            result = fn_803B35D0(self->file, entry);
            if (result != 0)
                return result;
            mode = 1;
        }
        if (mode == 1) {
            *found = 1;
            return 0;
        }
    }

    entry->count = 0;
    entry->valid = 0;
    entry->checksum = 0;
    entry->name[0] = 0;

    if ((*(u32 *)(lbl_8053B248 + 0x3C) & 2) == 2)
        special = fn_803BFDB0(path, &index);

    if (special == 1) {
        status = seek_entry(self, index - 1);
        for (;;) {
            u8 attr;
            if (status != 0)
                return status;
            if ((self->data[11] & 0xF) == 0xF) {
            if (fn_803B2BD8(entry, self->data) != 0) {
                entry->count = 0;
                entry->name[0] = 0;
                goto special_next;
            }
            if (!(self->data[0] & 0x40))
                goto special_next;
            } else {
                return 0;
            }
            {
                status = seek_entry(self, index);
                if (status != 0)
                    return status;
                attr = self->data[11];
                if (attr == 0)
                    attr = 0x40;
                if (include & 0x80) {
                    include &= 0x7F;
                    exclude &= 0x7F;
                    if ((include != 0 && include != (include & attr)) ||
                        (exclude != 0 && exclude == (exclude & attr)))
                        status = -1;
                } else if (include != 0x7F && attr != include &&
                           (!(attr & include) || (attr & exclude)))
                    status = -1;
                if (status == -1)
                    return 0;
                if (attr & 8)
                    return 3;
                fn_803B2A48(entry, self->data);
                if (fn_803BE470(entry->shortname, path, 0)) {
                    set_entry(self, entry);
                    *found = 1;
                    return 0;
                }
                goto done;
            }
special_next:
            status = fn_803B5230(self, 0);
        }
    }

    while (fn_803B502C(self) == 0) {
        u8 attr;
        if (result != 0)
            return result;
        if (self->data[0] == 0)
            goto done;
        if (self->data[0] == 0xE5) {
            entry->count = 0;
            entry->name[0] = 0;
            goto advance;
        }
        attr = self->data[11];
        if ((attr & 0xF) == 0xF) {
            if (fn_803B2BD8(entry, self->data)) {
                entry->count = 0;
                entry->name[0] = 0;
            }
            goto advance;
        }
        if (attr == 0)
            attr = 0x40;
        if (include & 0x80) {
            include &= 0x7F;
            exclude &= 0x7F;
            if ((include != 0 && include != (include & attr)) ||
                (exclude != 0 && exclude == (exclude & attr)))
                result = -1;
        } else if (include != 0x7F && attr != include &&
                   (!(attr & include) || (attr & exclude)))
            result = -1;
        if (result == -1) {
            entry->count = 0;
            entry->name[0] = 0;
            goto advance;
        }
        if (attr & 8) {
            entry->count = 0;
            entry->name[0] = 0;
        }
        fn_803B2A48(entry, self->data);
        if (entry->count != 0 && entry->valid == 1 &&
            entry->checksum == fn_803B29D8(entry) &&
            fn_803BE470(entry, path, 1)) {
            set_entry(self, entry);
            *found = 1;
            return 0;
        }
        if (fn_803BE470(entry->shortname, path, 0)) {
            if (self->data[12] & 0x18) {
                s32 length;
                fn_803BEB70(entry->shortname, &name, self->data[12]);
                length = fn_803BEF50(entry, &name);
                entry->count = length / 13 + (length % 13 != 0);
                entry->checksum = fn_803B29D8(entry);
                entry->valid = 1;
            }
            set_entry(self, entry);
            *found = 1;
            return 0;
        }
        entry->count = 0;
        entry->name[0] = 0;
advance:
        result = next_entry(self);
    }
done:
    return 0;
}
