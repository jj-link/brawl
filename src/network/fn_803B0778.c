#include <types.h>
#pragma force_active on
typedef struct Disk { u16 size; u8 pad[0x1f]; u8 shift; } Disk;
typedef struct Inner { u32 flags; u8 pad04[0x10]; u32 count; u8 pad18[0x24c]; u32 pos; Disk *disk; u32 pad26c; u32 start; } Inner;
typedef struct Outer { u32 flags; u32 pad; Inner *inner; } Outer;
extern char lbl_8053B248[];
extern s32 fn_803B8160(u8 *, u32, u32, u32 *, u32 *);
extern s32 fn_803B83A0(Disk *, u32, u32 *);
extern u32 fn_803B8508(Disk *);
s32 fn_803B0778(Outer *obj, u32 *out) {
 u32 temp, current, next;
 Inner *inner;
 Disk *disk;
 u32 size, pos, rem, end, count, limit;
 s32 result;
 *out = 0;
 if (lbl_8053B248 > (char *)obj || lbl_8053B248 + 0x27fb8 < (char *)obj) return 10;
 if (!obj || !(inner = obj->inner) || !(obj->flags & 1) || !(inner->flags & 1) || !(inner->flags & 2)) return 0x26;
 if (!(inner->flags & 1) || !(inner->flags & 2)) return 0x26;
 disk = obj == 0 ? 0 : inner->disk;
 if (!disk) return 0x26;
 size = disk->size << disk->shift;
 if (inner->start) {
  pos = inner->pos;
  end = pos + (pos % size ? size - pos % size : 0);
  if (inner->count) {
   limit = (inner->count + 1) * size;
  } else {
   if (pos) {
    result = fn_803B8160((u8 *)inner + 4, inner->start, pos, &temp, &current);
    if (result) return result;
   } else { current = inner->start; }
   limit = fn_803B8508(disk);
   count = 0;
   while (current != limit) {
    count++;
    result = fn_803B83A0(disk, current, &next);
    if (result) return result;
    current = next;
   }
   limit = end + count * size;
  }
  *out = limit - end;
 }
 return 0;
}