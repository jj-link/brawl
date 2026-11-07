#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on
class soAnimCmdEventObserver;
template<class T> class soEventObserver { public: static void __vt(int,int); };
extern "C" {
extern char lbl_27_data_146C8[], lbl_27_data_14FE8[], lbl_27_data_731C[], lbl_27_data_1F78[], lbl_27_data_1180[];
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_9FC94(void*, int);
void* fn_27_9F548(void*, int);
}
class MainVirtual { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6();
};
#define RELEASE(off, table) if (p+off) { if (p+off) { \
 short id=*(short*)(p+off+4); *(void**)(p+off)=table; \
 if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1U) \
 soEventSystem::getInstance()->getManager(*(short*)(p+off+4))->eraseObserver(*(short*)(p+off+6),*(short*)(p+off+8)); \
 *(short*)(p+off+8)=-1; *(short*)(p+off+4)=-1; } }
extern "C" void* fn_27_97968(char* p, int flag) {
 if (p) {
  *(void**)p=lbl_27_data_146C8;
  *(void**)(p+8)=lbl_27_data_146C8+0xd4;
  *(void**)(p+0x14)=lbl_27_data_146C8+0xe8;
  *(void**)(p+0x20)=lbl_27_data_146C8+0xf8;
  *(void**)(p+0x2c)=lbl_27_data_146C8+0x10c;
  *(void**)(p+0x38)=lbl_27_data_146C8+0x120;
  ((MainVirtual*)p)->d();
  fn_27_9FC94(p+0x124,-1);
  if (p+0x78) __destroy_arr(p+0x80,(void (*)(void*,int))fn_27_9F548,0x10,10);
  RELEASE(0x38,lbl_27_data_14FE8);
  RELEASE(0x2c,lbl_27_data_731C);
  RELEASE(0x20,lbl_27_data_1F78);
  RELEASE(0x14,lbl_27_data_1180);
  RELEASE(8,(void*)soEventObserver<soAnimCmdEventObserver>::__vt);
  if (flag>0) __dl__FPv(p);
 }
 return p;
}