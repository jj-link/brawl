#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
extern char lbl_80414180[];
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2(const char*, s32, void*, s32, s32, void*);
 virtual void slot3(const char*, s32, void*);
};
extern "C" void fn_802FEA60(void* arg0, Object_vptr_0* arg1) {
 u8* entry;
 u8* end;
 s32 offset = 0;
 u8* cursor;
 s32 size;
 goto setup;
scan:
 switch (*cursor) {
 case 1: goto finish;
 case 6:
  arg1->slot3(lbl_80414180, 8, *(void**)(cursor + 4));
  cursor += cursor[3];
  break;
 case 0: case 2: case 3: case 4: case 5:
  cursor += cursor[3];
  break;
 }
 if (cursor < end) goto scan;
setup:
 entry = *(u8**)(*(u8**)arg0 + offset);
 size = *(s32*)entry;
 cursor = entry + 0x10;
 end = entry + size + 0x10;
 arg1->slot2(lbl_80414180 + 6, 8, entry, size + 0x10, 0x200, entry + size);
 offset += 4;
 goto scan;
finish:;
}