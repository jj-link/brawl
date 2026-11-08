#pragma force_active on
#include <types.h>
class VObj {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual s32 f12(s32, s32);
};
struct Data { u8 pad[0x20]; s32 x; s32 y; };
struct SelfStruct : VObj { u8 pad[8]; Data* data; };
extern "C" s32 fn_80331560(SelfStruct* self) {
 Data* d = self->data;
 s32 x = d->x;
 s32 y = d->y;
 s32 result = 0;
 if (x >= 0) { if (y >= 0) { result = 1; } }
 if (result != 0) { return self->f12(x, y); }
 return 0;
}