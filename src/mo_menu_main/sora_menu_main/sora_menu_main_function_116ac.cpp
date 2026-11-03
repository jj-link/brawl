#include <gf/gf_file_io_handle.h>
#include <revolution/OS/OSError.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on
extern "C" u32 fn_800AE528(s32*, u32, u32, s32*);
extern "C" char lbl_2_data_17BC[];
extern "C" char lbl_2_data_17C8[];
struct Entry { char pad[8]; const char* name; };
struct Object {
 char pad0[0x4c]; s32* source; char pad50[0xb8]; u32 index;
 Entry* entries[0xc3a]; u32 ids[0x3e8]; u32 counts[0x478];
 u8 flags[0x20]; gfFileIOHandle handles[0x20]; u8 loaded;
};
extern "C" void fn_2_116AC(Object* obj) {
 char path[64];
 if (obj->loaded) { OSReport(lbl_2_data_17BC); return; }
 fn_800AE528(obj->source, 0x20, obj->ids[obj->index], (s32*)obj->entries);
 unsigned n = 0;
 unsigned j;
 unsigned k = 0;
 for (; n < 2; n++) {
  for (j = 0; j < obj->counts[obj->index + n]; j++) {
   sprintf(path, lbl_2_data_17C8, obj->entries[k]->name);
   obj->handles[k].readRequest(path, (HeapType)0x2b, 0, 0);
   obj->flags[k] = 0;
   k++;
  }
 }
 obj->loaded = 1;
}