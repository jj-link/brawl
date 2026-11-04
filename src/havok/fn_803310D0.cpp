#pragma force_active on
#pragma use_lmw_stmw on
struct Header { char pad[0x14]; int count; };
struct Entry { char pad[0x1c]; int start; int end; char rest[0xc]; };
class Class_80488EE0 {
public:
 virtual void fn_8032FA40(); virtual void fn_80080A64(); virtual void fn_8032FCB4(); virtual void fn_80330928(); virtual void fn_8033259C(); virtual void fn_803315A4(); virtual void fn_80330698(); virtual void fn_8032FF60(); virtual void fn_803309D0(); virtual void fn_8032FCAC(); virtual void fn_8032FD74(); virtual void fn_80331408(); virtual int fn_80331494(int, int);
 char pad[8]; Header* header; Entry* entries; char** blocks;
};
extern "C" int fn_803310D0(Class_80488EE0* self) {
 int* p;
 char* block;
 for (int i = 0; i < self->header->count; i++) {
  block = self->blocks[i];
  if (block) {
   Entry* entry;
   int j = 0;
   entry = &self->entries[i];
   p = (int*)(block + entry->start);
   for (; j < (entry->end - entry->start) / 4; p += 3, j += 3) {
    int offset = p[0];
    if (offset != -1) {
     *(int*)(block + offset) = self->fn_80331494(p[1], p[2]);
    }
   }
  }
 }
 return 0;
}