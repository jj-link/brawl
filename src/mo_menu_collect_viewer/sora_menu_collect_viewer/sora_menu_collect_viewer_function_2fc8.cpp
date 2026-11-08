#include <types.h>
#pragma force_active on
struct Copy { unsigned char data[0x41]; };
class Obj {
public:
 unsigned char pad[0x3C];
 virtual void vf0() = 0;
 virtual void vf1() = 0;
 virtual void vf2() = 0;
 virtual void vf3() = 0;
 virtual void vf4() = 0;
 virtual void vf5() = 0;
 virtual void vf6() = 0;
 virtual void vf7() = 0;
 virtual void vf8() = 0;
 virtual void vf9() = 0;
 virtual void vf10() = 0;
 virtual void vf11() = 0;
 virtual void vf12() = 0;
 virtual void vf13() = 0;
 virtual void vf14() = 0;
 virtual void vf15() = 0;
 virtual void vf16() = 0;
 virtual void vf17() = 0;
 virtual void vf18() = 0;
 virtual void vf19() = 0;
 virtual void vf20() = 0;
 virtual void vf21() = 0;
 virtual void vf22() = 0;
 virtual void vf23() = 0;
 virtual void vf24() = 0;
 virtual void vf25() = 0;
 virtual void vf26() = 0;
 virtual void vf27() = 0;
 virtual void vf28() = 0;
 virtual void vf29() = 0;
 virtual void vf30() = 0;
 virtual void vf31() = 0;
 virtual void vf32() = 0;
 virtual void vf33() = 0;
 virtual void vf34() = 0;
 virtual void vf35() = 0;
 virtual void vf36() = 0;
 virtual void vf37() = 0;
 virtual void vf38() = 0;
 virtual s32 getIdx() = 0;
 virtual Copy copyTo(s32 idx) = 0;
};
extern "C" {
extern unsigned char lbl_6_data_178[0x40];
void* fn_800C34D8(void*, void*);
}
extern "C" void fn_6_2FC8(void* dst, Obj* obj) {
 unsigned char buf4C[0x44];
 *(Copy*)dst = obj->getIdx() < 0 ? *(Copy*)fn_800C34D8(buf4C, lbl_6_data_178) : obj->copyTo(obj->getIdx());
}
