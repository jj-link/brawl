#include <ut/ut_list.h>
#include <snd/snd_system.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_2BAC0[];
extern int lbl_27_bss_31F8;
void fn_27_145944();
void fn_27_6FDE0(unsigned int);
void fn_27_141588(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}
struct Class_C560_base { char pad[0x18]; };
class Class_C560 : public Class_C560_base {
public:
 virtual void fn_27_7F31C();
 virtual void fn_27_7F33C(int);
};
struct CallBase { char pad[0x14]; };
class CallClass : public CallBase {
public:
 virtual void fn_27_7F31C();
 virtual void fn_27_7F33C(int);
};
struct Class_741A8_base { char pad[0x18]; };
class Class_741A8 : public Class_741A8_base {
public:
 virtual void fn_27_296880();
 virtual void fn_27_296224();
};
extern "C" void* fn_27_141648(void* obj, int flag) {
 char* p = (char*)obj;
 if (p) {
  *(char**)p = lbl_27_data_2BAC0;
  unsigned char count = *(unsigned char*)(p+0xc);
  int a;
  if (count != 0 && (--*(unsigned char*)(p+0xc)) == 0) a = 1;
  else a = 0;
  unsigned int b;
  if (a) {
   ((CallClass*)(p+4))->fn_27_7F33C(1);
   b = 1;
  } else b = 0;
  unsigned int c;
  if (b == 1) {
   ((utList*)(p+0x1088))->removeExist((utListNode*)(p+4));
   ((utList*)(p+0x1094))->removeExist((utListNode*)(p+4));
   ((utList*)(p+0x107c))->addTail((utListNode*)(p+4));
   c = 1;
  } else c = 0;
  if (c == 1) {
   int group = *(int*)(p+0x1078);
   if (group >= 0) {
    g_sndSystem->freeGroup(group, 0);
    *(int*)(p+0x1078) = -1;
   }
  }
  fn_27_145944();
  fn_27_6FDE0(0);
  lbl_27_bss_31F8 = 0;
  __destroy_arr(p+0x38, fn_27_141588, 0x34, 0x50);
  if (flag > 0) __dl__FPv(p);
 }
 return obj;
}