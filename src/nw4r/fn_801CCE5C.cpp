#include <types.h>
#pragma force_active on
class V {
public:
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual int read(void*, u32);
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14();
 virtual void reset(int, int);
};
struct Container { V* obj; void* data; void* data2; };
extern "C" int fn_801D3698(u8, u32, void*);
inline bool valid(void* p) {
 if (*(u32*)p != 0x5253544D) return false;
 u16 f = *(u16*)((char*)p + 6);
 if (f < 0x100) return false;
 return f <= 0x100;
}
extern "C" s32 fn_801CCE5C(Container* self, void* arg1, u32 arg2) {
 self->obj->reset(0, 0);
 char buf[0x60];
 char* p = (char*)(((u32)&buf[0x1f]) & 0xFFFFFFE0);
 if ((u32)self->obj->read(p, 0x40) != 0x40U) return 0;
 if (!valid(p)) return 0;
 if (*(u32*)(p + 0x18) > arg2) return 0;
 u32 off = *(u32*)(p + 0x10) + *(u32*)(p + 0x14);
 self->obj->reset(0, 0);
 u32 result = self->obj->read(arg1, off);
 if (result != off) return 0;
 if (valid(arg1)) {
  self->data = arg1;
  u32 a = *(u32*)((char*)arg1 + 0x10);
  char* B = (char*)(a + (u32)arg1);
  self->data2 = B;
  char* ref = B + 8;
  u32 value = *(u32*)(ref + 4);
  fn_801D3698(*(u8*)ref, value, ref);
 }
 return 1;
}