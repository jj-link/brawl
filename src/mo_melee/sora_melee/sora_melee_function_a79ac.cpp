#include <sr/sr_common.h>
#pragma force_active on

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Entry { int a, b; char pad[5]; unsigned char kind; };
struct Info { unsigned short kind; float value, angle; char rest[0x14]; };

class Class_1250 {
public:
 virtual void fn_27_13C90(); virtual void fn_27_14068(); virtual void fn_27_140C0(); virtual void fn_27_1412C();
 virtual void fn_27_14134(); virtual void fn_27_14370(); virtual void fn_27_14A28(); virtual void fn_27_14A30();
 virtual void fn_27_14A38(); virtual void fn_27_14A48(); virtual void fn_27_14A68(); virtual void fn_27_14AD8();
 virtual void fn_27_14A60(); virtual void fn_27_14D08(); virtual void fn_27_14EDC(); virtual void fn_27_14D00();
 virtual void fn_27_14B80(); virtual void fn_27_14B88(); virtual void fn_27_16A70(); virtual void fn_27_16AB8();
 virtual void fn_27_1CBB4(); virtual void fn_27_14A20(); virtual void fn_27_1CBAC(); virtual void fn_27_1CBA4();
 virtual void fn_27_14B98(); virtual void fn_27_14B90();
 virtual int fn_27_1CB88(int);
 virtual Entry* fn_27_14CF8(int, int);
};
class soPostureModuleImpl {
public:
 virtual void isNull(); virtual ~soPostureModuleImpl(); virtual void fn_27_2362C(); virtual void fn_27_236B0();
 virtual void fn_27_25088(); virtual void fn_27_23E84(); virtual void fn_27_25184(); virtual void fn_27_2370C();
 virtual void fn_27_23728(); virtual void fn_27_23E28(); virtual void fn_27_23CC0(); virtual void fn_27_25068();
 virtual void fn_27_23A9C(); virtual void fn_27_23B18(); virtual void fn_27_250FC(); virtual void fn_27_250A4();
 virtual void fn_27_23BF8(); virtual void fn_27_251B8(); virtual void fn_27_251B0(); virtual void fn_27_23C14();
 virtual void fn_27_25154(); virtual void fn_27_2517C(); virtual void fn_27_23744(); virtual void fn_27_25080();
 virtual void fn_27_2516C(int, Vec3*);
 virtual void fn_27_251A8(); virtual void fn_27_251A0(); virtual void fn_27_237B0();
};
struct Modules { char pad[0x7c]; soPostureModuleImpl* posture; char pad2[0x10]; Class_1250* events; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x10]; int a, b; unsigned char flag; };

extern "C" {
extern void* lbl_27_bss_5780;
extern const float lbl_27_rodata_D28, lbl_27_rodata_D2C;
void* fn_27_22A914(void*);
unsigned int fn_27_22B290(void*, int, Info*);
void fn_8003DC64(Vec2*, float, Vec2*);
}
extern "C" void fn_27_A79AC(Self* self, Access* access) {
 int count = access->modules->events->fn_27_1CB88(-1);
 for (int i = 0; i < count; ++i) {
  Entry* entry = access->modules->events->fn_27_14CF8(-1, i);
  switch (entry->kind) {
  case 0x1a:
  case 0x1b: {
   if (lbl_27_bss_5780 == 0) {
    void* p = operator new(0x54, Heaps::System);
    if (p != 0) p = fn_27_22A914(p);
    lbl_27_bss_5780 = p;
   }
   Info info;
   if (fn_27_22B290(lbl_27_bss_5780, entry->b, &info) == 1 && info.value > lbl_27_rodata_D28 && info.kind != 0xd) {
    Vec2 dst, src;
    src.x = info.value;
    src.y = lbl_27_rodata_D28;
    fn_8003DC64(&src, lbl_27_rodata_D2C * info.angle, &dst);
    int mode;
    if (entry->kind == 0x1a) mode = 1;
    else { mode = 0; self->flag = 1; }
    Vec3 out;
    out.x = dst.x; out.y = dst.y; out.z = lbl_27_rodata_D28;
    access->modules->posture->fn_27_2516C(mode, &out);
   }
   break;
  }
  case 0x1c:
   self->a = entry->b;
   self->b = entry->a;
   break;
  }
 }
}