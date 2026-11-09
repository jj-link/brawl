#include <types.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on
extern "C" char* fn_801CC2E4();
extern "C" void fn_801CC818(void*, void*);
extern "C" void* fn_801BE7BC();
extern "C" void fn_801BE8D0(void*, void*);
extern "C" void fn_801C4DEC(void*);
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2(void*);
};
inline void* get(char* p, s32 i) {
 if (i > 15) return 0;
 return *(void**)(p + 0xb8);
}
struct O { char pad[0x74]; char m74[12]; char m80[12]; u8 f8c; u8 f8d; char rest[0x26]; Object_vptr_0* b4; void* b8[16]; };
extern "C" void fn_801C38E8(char* self, u32 low, u32 high) {
 OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
 if (*(u8*)(self + 0x8c)) {
  char* p = self;
  for (s32 i = 0; i < 16; i++) {
   void* v = get(p, i);
   if (v && low <= *(u32*)((char*)v + 0x50) && *(u32*)((char*)v + 0x50) <= high) {
    {
 O* obj=(O*)self;
s32 i;
 OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
 if (obj->f8d) {
  i = (s32)obj;
  if (obj) i = (s32)obj + 0x80;
  fn_801CC818(fn_801CC2E4(), (void*)i);
  obj->f8d = 0;
 }
 if (obj->f8c) {
  i = (s32)obj;
  if (obj) i = (s32)obj + 0x74;
  fn_801BE8D0(fn_801BE7BC(), (void*)i);
  obj->f8c = 0;
 }
 char* p = (char*)obj;
 i = 0;
 do {
  OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
  void* v = get(p, i);
  if (v == 0) {
   OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
  } else {
   fn_801C4DEC(v);
   obj->b4->slot2(*(void**)(p + 0xb8));
   *(void**)(p + 0xb8) = 0;
   OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
  }
  i++;
  p += 4;
 } while (i < 16);
 OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));

    }
    break;
   }
   p += 4;
  }
 }
 OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
}
