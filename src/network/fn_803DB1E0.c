#include <types.h>
#pragma force_active on

typedef struct {
    u16 sector_size;
    u8 pad02[4];
    u8 sectors_per_cluster;
    u8 pad07[9];
    u32 root_cluster;
    u8 pad14[8];
    s32 type;
} PFDIRVolume;

typedef struct {
    u32 a, b, c, d, e, f, g, h, i, j, k, l;
    void *context;
    u32 m;
} PFDIRState;

typedef struct {
    u32 value;
    void *file;
    PFDIRState state;
    u8 pad40[0xC];
    u8 flag;
    u8 pad4d[0x23];
} PFDIRIterator;

typedef struct {
    u16 name[0x105];
    u8 count;
    u8 pad20b[3];
    char short_name[13];
    u8 flags;
    u8 attribute;
    u8 tenths;
    u16 date;
    u16 time;
    u16 create_time;
    u16 create_date;
    u16 access_date;
    u32 size;
    PFDIRVolume *volume;
    u32 pad230;
    u32 cluster;
    u32 sector;
    u16 offset;
    u16 pad23e;
} PFDIREntry;

typedef struct {
    u8 pad000[0x21B];
    u8 flags;
    u8 attribute;
    u8 pad21d[0xF];
    u32 parent;
    u32 length;
    u32 cluster;
    u32 previous;
    u8 rest[4];
} PFDIRPathEntry;

typedef struct {
    u32 a;
    u32 b;
    u32 parent;
    u32 cluster;
    u32 index;
    u32 flags;
    u8 count;
    u8 has_long_name;
    u8 checksum;
    u8 attribute;
    u8 data[0x208];
    u16 date;
    u16 time;
    u32 size;
    u8 entry_attribute;
    char short_name[13];
    char long_name[0x20A];
    u8 extra[0x208];
    u16 wide_short_name[13];
    u16 wide_long_name[0x105];
} PFDIRResult;

typedef struct {
    u32 pad[2];
    u8 *data;
} PFDIRBuffer;

extern char lbl_805644C0[];
extern int fn_803E7224(int, void *, void *);
extern int PFENT_ITER_GetEntryOfPath(void *, void *, void *, void *, int);
extern u16 fn_803D68CC(void *, int);
extern u32 fn_803D66F4(void *);
extern void *fn_803D6724(void *, u32);
extern int fn_803E7C50(void *, void *);
extern void fn_803D66FC(void *, void *);
extern void fn_803E8738(void *, void *, void *);
extern void fn_803E2414(void *, void *, void *, void *);
extern void fn_803E23D4(void *, void *);
extern int fn_803DED54(void *, u8);
extern int fn_803DF5E4(void *, void *, void *, int, int, int *);
extern int fn_803E7E14(void *, void *);
extern int fn_803DDC84(void *, void *);
extern u32 fn_803E7D7C(void *, void *);
extern void fn_803D6528(void *, void *);
extern u8 PFENT_getcurrentDateTimeForEnt(u16 *, u16 *);
extern int fn_803DD674(void *, u8, void *, void *, void *, void *);
extern void fn_803E8D5C(void *, int);
extern int fn_803E1414(void *, int, int, void *);
extern int fn_803DA454(void *, int, void *, void *);
extern void fn_803D634C(void *, int, u16);
extern void fn_803DCFB0(void *, void *);
extern int PFSEC_WriteData(void *, void *, u32, u16, u16, u32 *, int);
extern void fn_803DA55C(void *, void *);
extern u8 fn_803DCE4C(void *);
extern void fn_803DD224(void *, void *, u8, u8, int);
extern int fn_803DDB2C(void *, int);
extern void fn_803D645C(void *, void *);

int PFDIR_p_mkdir(PFDIRVolume *volume, int path, void *unused,
                  PFDIRResult *result)
{
    PFDIRPathEntry path_entry;
    PFDIREntry entry;
    u8 name_buffer[0x200];
    PFDIRIterator iter;
    PFDIRState state;
    u8 raw_entry[0x20];
    u8 path_info[0x10];
    u8 path_part[0x10];
    u8 state_info[0x10];
    u32 blocks[2];
    int found;
    u32 buffer_info;
    PFDIRBuffer *buffer;
    u32 old_offset;
    u32 i;
    u8 count = 0;
    u32 sector_start = count;
    u16 length;
    u32 written;
    u32 index;
    u32 *next;
    u32 sector;
    u32 cluster;
    u8 checksum;
    int j;
    u8 *p;
    int status;

    status = fn_803E7224(path, path_info, path_part);
    if (status != 0)
        return status;
    status = PFENT_ITER_GetEntryOfPath(&iter, &path_entry, volume, path_info, 1);
    if (status != 0)
        return status;
    if (!(path_entry.attribute & 0x10))
        return 0x14;

    length = fn_803D68CC(path_part, 1);
    if ((u32)length + path_entry.length > 0x103)
        return 2;
    if (length > 0xFF)
        return 1;

    if (fn_803D66F4(path_part) == 2)
        fn_803E7C50(name_buffer, fn_803D6724(path_part, 1));
    fn_803D66FC(path_part, name_buffer);

    if (result != 0) {
        result->a = 0;
        result->b = 0;
        result->cluster = path_entry.cluster;
        result->parent = path_entry.parent;
        result->attribute = 0x10;
        if (fn_803D66F4(path_part) == 1) {
            fn_803E8738(result->data, 0, path_part);
            result->flags |= 1;
        } else {
            fn_803E8738(result->data, result->extra, path_part);
            result->flags |= 2;
        }
    }

    fn_803E2414(&state, state_info, volume, &path_entry.cluster);
    iter.state = state;
    fn_803E23D4(&iter.state, &path_entry.cluster);
    status = fn_803DED54(&iter, 0);
    if (status != 0)
        return status;
    status = fn_803DF5E4(&iter, &entry, path_part, 0x10, 0, &found);
    if (status != 0)
        return status;
    if (found != 0)
        return 8;

    status = fn_803E7E14(entry.short_name, path_part);
    if (status != 0 && (s8)entry.short_name[0] == 0)
        return 1;
    if (status != 0) {
        status = fn_803DDC84(&path_entry, entry.short_name);
        if (status != 0)
            return status;
        if (fn_803D66F4(path_part) == 1)
            length = fn_803E7D7C(entry.name, fn_803D6724(path_part, 1));
        else
            fn_803D6528(entry.name, fn_803D6724(path_part, 1));
    } else {
        entry.name[0] = 0;
    }

    entry.cluster = 0;
    entry.size = 0;
    entry.volume = volume;
    entry.flags = 0;
    entry.attribute = 0x10;
    entry.tenths = PFENT_getcurrentDateTimeForEnt(&entry.time, &entry.date);
    old_offset = entry.offset;
    entry.create_time = entry.time;
    entry.create_date = entry.date;
    entry.access_date = entry.time;

    if (entry.name[0] && !(entry.flags & 0x18)) {
        count = length / 13U + (length % 13U != 0);
        status = fn_803DD674(&entry, count + 1, &state, blocks, path_part, &index);
        if (status != 0)
            return status;
        if ((*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2)
            fn_803E8D5C(entry.short_name, index);
    } else {
        status = fn_803DD674(&entry, 1, &state, blocks, path_part, &index);
        if (status != 0)
            return status;
    }

    fn_803E23D4(&state, &entry.cluster);
    status = fn_803E1414(&state, 0, 1, &sector_start);
    if (status != 0)
        return status;
    if (sector_start == 0xFFFFFFFF)
        return 6;

    cluster = ((u32 *)state.context)[1];
    if (volume->type == 2 &&
        *(u32 *)iter.state.c == volume->root_cluster &&
        old_offset == 0 && cluster == volume->root_cluster) {
        iter.state = state;
        status = fn_803DED54(&iter, count);
        if (status != 0)
            return status;
        if (iter.flag == 0) {
            fn_803E23D4(&state, &entry.cluster);
            *(u32 *)state.c = 0;
            ((u32 *)state.context)[1] = 0;
            cluster = volume->root_cluster + 1;
            status = fn_803E1414(&state, 0, 1, &sector_start);
            if (status != 0)
                return status;
        }
    }

    status = fn_803DA454(volume, -1, &buffer, &buffer_info);
    if (status != 0)
        return status;
    fn_803D634C(buffer->data, 0, volume->sector_size);
    i = volume->sectors_per_cluster;
    while (i != 0) {
        if (i == 1) {
            p = buffer->data;
            p[0] = '.';
            for (j = 1; j < 11; j++)
                p[j] = ' ';
            fn_803DCFB0(buffer->data, &entry);
            p = buffer->data;
            p[0x20] = '.';
            p[0x21] = '.';
            for (j = 2; j < 11; j++)
                p[0x20 + j] = ' ';
            if (path_entry.previous == 0xFFFFFFFF)
                entry.cluster = 0;
            else
                entry.cluster = path_entry.cluster;
            fn_803DCFB0(buffer->data + 0x20, &entry);
        }
        status = PFSEC_WriteData(volume, buffer->data, i + sector_start - 1,
                                 0, volume->sector_size, &written, 0);
        if (status != 0)
            break;
        if (written != volume->sector_size) {
            status = 0x11;
            break;
        }
        i--;
    }
    fn_803DA55C(volume, buffer);
    if (status != 0)
        return status;

    entry.count = count;
    sector = entry.sector;
    checksum = fn_803DCE4C(&entry);
    if (!(path_entry.flags & 0x18)) {
        i = count;
        next = blocks;
        while (i >= 1) {
            fn_803DD224(raw_entry, &entry, i, checksum, i == count);
            status = PFSEC_WriteData(volume, raw_entry, sector, entry.offset,
                                     0x20, &written, 0);
            if (status != 0)
                return status;
            if (written != 0x20)
                return 0x11;
            entry.offset += 0x20;
            if (entry.offset >= volume->sector_size) {
                entry.offset = 0;
                sector = *next++;
            }
            i--;
        }
        entry.sector = sector;
    }

    entry.cluster = cluster;
    status = fn_803DDB2C(&entry, 0);
    if (status != 0)
        return status;

    if (result != 0) {
        result->index = index + 1;
        fn_803D645C(result->short_name, entry.short_name);
        if ((result->flags & 2) == 2)
            fn_803E7D7C(result->wide_short_name, result->short_name);
        if (entry.name[0] != 0) {
            if ((*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2) {
                *(u32 *)(lbl_805644C0 + 0x60) =
                    (*(u32 *)(lbl_805644C0 + 0x60) & ~3) | 1;
                fn_803E7C50(result->long_name, entry.name);
                *(u32 *)(lbl_805644C0 + 0x60) =
                    (*(u32 *)(lbl_805644C0 + 0x60) & ~3) | 2;
            } else {
                fn_803E7C50(result->long_name, entry.name);
            }
            if ((result->flags & 2) == 2)
                fn_803D6528(result->wide_long_name, entry.name);
            result->checksum = checksum;
            result->has_long_name = 1;
        } else {
            result->long_name[0] = 0;
            if ((result->flags & 2) == 2)
                result->wide_long_name[0] = 0;
            result->has_long_name = 0;
            result->checksum = 0;
        }
        result->size = entry.size;
        result->date = entry.create_date;
        result->time = entry.access_date;
        result->entry_attribute = entry.attribute;
        result->count = entry.count;
    }
    return 0;
}
