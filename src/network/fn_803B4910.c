#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Device {
    u8 pad[0x20];
    u8 shift;
} Device;

typedef struct State {
    u32 position;
    Device *device;
    u32 field08;
    u32 field0c;
    u32 *field10;
    u8 pad14[0x28];
    Device *next_device;
    s32 field40;
    u32 offset;
    u16 length;
    u16 mask;
    u8 data[0x20];
    u8 shift;
} State;

typedef struct Entry {
    u8 pad0[0x20a];
    u8 flag20a;
    u8 pad20b[3];
    char name[0xe];
    u8 flags;
    u8 pad21d[0x13];
    u32 size;
    u32 cluster;
} Entry;

typedef struct Iterator {
    u32 first;
    u32 second;
    u32 third;
    u32 fourth;
} Iterator;

typedef struct SavedEntry {
    Entry entry;
    u32 cluster;
} SavedEntry;

extern char lbl_8059FE38;
extern char lbl_8059FE3C;
extern char lbl_8059FE40;
extern char lbl_8059FE4C;
extern char lbl_8059FE50;
extern char lbl_8059FE54;
extern char lbl_8059FE58;

extern s32 fn_803A98A8(void *, void *);
extern s32 fn_803A9A78(void *);
extern s32 fn_803A9AA8(void *, s32);
extern void fn_803A9AD0(void *, s32);
extern u16 fn_803A9C60(void *);
extern u16 fn_803A9C74(void *, s32);
extern s32 fn_803A9D54(void *, void *);
extern s32 fn_803A9DF8(void *, void *, s32, s32, s32);
extern s32 fn_803B35D0(void *, Entry *);
extern s32 fn_803B3C2C(State *, s32);
extern s32 fn_803B3DD8(State *, Entry *, u32, s32 *);
extern s32 fn_803B40F8(State *, Entry *, Iterator *, s32, s32, s32 *, s32);
extern void fn_803B841C(void *, u32 *);
extern void fn_803B847C(void *, void *, void *, u32 *);
extern void fn_803BE034(Iterator *, s32, s32);
extern s32 fn_803BE044(Iterator *, s32);
extern s32 fn_803BED20(void *);
extern s32 fn_803BED88(void *);
extern s32 fn_803C0080(Device *, void *, u32, u16, u32, u32 *, s32);
extern s32 fn_803C120C(void *, Entry *);

s32 fn_803B4910(State *self, Entry *entry, void *file, void *path,
                 s32 mode, s32 limit)
{
    SavedEntry saved;
    Iterator iter;
    u32 temp[3];
    s32 found;
    u32 count1;
    u32 count2;
    s32 result;
    u32 old_position;
    s32 status;
    s32 old_length;
    u32 saved_cluster;
    s32 context;
    u32 mask;

    if (fn_803A9DF8(path, &lbl_8059FE4C, 1, 1, 1) == 0)
        fn_803A9AD0(path, 2);

    if (fn_803A9DF8(path, &lbl_8059FE50, 1, 0, 1) == 0 ||
        fn_803A9DF8(path, &lbl_8059FE54, 1, 0, 1) == 0) {
        result = fn_803B35D0(file, entry);
        if (result != 0)
            return result;
        if (fn_803A9C74(path, 1) == 1 &&
            fn_803A9DF8(path, &lbl_8059FE58, 2, 0, 1) == 0)
            return 0;
    } else {
        result = fn_803C120C(file, entry);
        if (result != 0)
            return result;
    }

    context = fn_803A9AA8(path, 1);
    fn_803B847C(&self->field08, temp, file, &self->field0c);
    self->field0c = entry->cluster;
    fn_803BE034(&iter, context, fn_803A9A78(path));
    result = fn_803BE044(&iter, mode);

    while (iter.first != 0) {
        if (result != 0)
            return result;
        if (limit != 0 &&
            fn_803A9DF8(&iter, &lbl_8059FE58, 2, 0, 1) == 0)
            break;
        if (!(entry->flags & 0x10))
            return 2;
        if (fn_803A9C60(&iter) == 0)
            return 2;

        self->field0c = entry->cluster;
        fn_803B841C(&self->field08, &self->field0c);
        self->device = self->next_device;
        if (self->device == 0) {
            result = 10;
        } else {
            s32 sh;
            file = (void *)self->position;
            sh = self->device->shift - 5;
            self->shift = sh;
            mask = 1 << (u8)sh;
            self->field40 = 0;
            self->field40 = 1;
            self->field40 = -1;
            self->mask = mask - 1;
            self->position = 0;
            result = fn_803B3C2C(self, 0);
            if (result != 0) {
                self->position = (u32)file;
                fn_803B3C2C(self, 0);
            } else {
                if (self->offset == 0xffffffffU) {
                    status = 16;
                } else {
                    s32 rc = fn_803C0080(self->device, self->data,
                                         self->offset, self->length,
                                         0x20, &count1, 0);
                    status = 17;
                    if (count1 == 0x20)
                        status = rc;
                }
                result = status != 0 ? status : 0;
            }
        }
        if (result != 0)
            return result;

        old_length = 0;
        saved_cluster = *self->field10;
        if ((fn_803A9DF8(&iter, &lbl_8059FE38, 1, 0, 3) == 0 ||
             fn_803A9DF8(&iter, &lbl_8059FE3C, 1, 0, 3) == 0 ||
             fn_803A9D54(&iter, &lbl_8059FE40) == 0) &&
            fn_803A98A8(entry->name, &lbl_8059FE40) != 0) {
            if (entry->flag20a != 0)
                old_length = fn_803BED88(entry) + 1;
            else
                old_length = fn_803BED20(entry->name) + 1;
        }

        result = fn_803B40F8(self, entry, &iter, 0x7f, 0, &found, 1);
        if (result != 0)
            return result;
        if (found == 0) {
            result = fn_803BE044(&iter, mode);
            if (result != 0)
                return result;
            return (iter.first == 0) + 2;
        }

        if (mode == 0) {
            if ((entry->flags & 0x10) && entry->cluster == 1) {
                entry->size = 3;
            } else if ((entry->flags & 0x10) &&
                       fn_803A98A8(entry->name, &lbl_8059FE40) == 0) {
                if (old_length != 0) {
                    entry->size -= old_length;
                } else {
                    saved.entry.cluster = entry->cluster;
                    fn_803B841C(&self->field08, &saved.entry.cluster);
                    self->device = self->next_device;
                    if (self->device == 0) {
                        old_position = 10;
                    } else {
                        s32 sh;
                        result = self->position;
                        sh = self->device->shift - 5;
                        self->shift = sh;
                        mask = 1 << (u8)sh;
                        self->field40 = 0;
                        self->field40 = 1;
                        self->field40 = -1;
                        self->mask = mask - 1;
                        self->position = 0;
                        old_position = fn_803B3C2C(self, 0);
                        if (old_position != 0) {
                            self->position = result;
                            fn_803B3C2C(self, 0);
                        } else {
                            if (self->offset == 0xffffffffU) {
                                status = 16;
                            } else {
                                s32 rc = fn_803C0080(self->device, self->data,
                                                     self->offset, self->length,
                                                     0x20, &count2, 0);
                                status = 17;
                                if (count2 == 0x20)
                                    status = rc;
                            }
                            old_position = status != 0 ? status : 0;
                        }
                    }
                    if (old_position != 0)
                        return old_position;
                    result = fn_803B3DD8(self, &saved.entry, saved_cluster, &found);
                    if (result != 0)
                        return result;
                    if (found == 0)
                        return 2;
                    if (saved.entry.flag20a != 0)
                        entry->size -= fn_803BED88(&saved.entry) + 1;
                    else
                        entry->size -= fn_803BED20(saved.entry.name) + 1;
                }
            } else if (!(entry->flags & 0x10) || entry->name[0] != '.') {
                entry->size += fn_803A9C74(&iter, 1) + 1;
                if (fn_803A9DF8(&iter, &lbl_8059FE58, 2, 0, 1) != 0)
                    entry->size -= fn_803A9C74(&iter, 2);
            }
        }
        result = fn_803BE044(&iter, mode);
    }
    return 0;
}
