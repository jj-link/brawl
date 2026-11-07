#include <ut/ut_list.h>
#pragma force_active on
class soNullable {
public:
 virtual void isNull();
 virtual void fn_27_6A3D8();
 virtual void fn_27_6A4BC();
 virtual void fn_27_6A51C();
 virtual void fn_27_6A5E0();
 virtual void fn_27_6A640();
 virtual void fn_27_6A660();
 virtual void fn_27_6A650();
 virtual void fn_27_6A6DC();
 virtual int fn_27_6A71C(int);
};
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual int slot8(int);
 virtual void slot9();
};
extern "C" void* fn_27_6F30C(void*);
extern "C" int fn_27_6BFDC(soNullable* self, int arg) {
 if (self->fn_27_6A71C(-1)) {
  unsigned char* node = (unsigned char*)((utList*)((unsigned char*)self + 0x20))->getNode(0);
  while (node != 0) {
   unsigned char* item = *(unsigned char**)(node + 0xc);
   if ((*(unsigned long*)(item + 0x30) >> 8) & 2) {
    unsigned char* p = *(unsigned char**)((unsigned char*)fn_27_6F30C(node) + 0x44);
    p = *(unsigned char**)(p + 0xd8);
    p = *(unsigned char**)(p + 0x4c);
    return ((Object_vptr_0*)p)->slot8(arg);
   }
   node = *(unsigned char**)node;
  }
 }
 return 0;
}