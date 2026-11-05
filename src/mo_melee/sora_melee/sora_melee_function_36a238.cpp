#define soEventUnitWrapper HeaderEventUnitWrapper
#define soInstanceUnitFullProperty HeaderInstanceUnitFullProperty
#include <so/event/so_event_system.h>
#undef soEventUnitWrapper
#undef soInstanceUnitFullProperty
#include <so/event/so_event_manage_module_impl.h>
#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_840D8(void*, int);
void* fn_27_84358(void*, int);
void* fn_27_844D8(void*, int);
void* fn_27_84198(void*, int);
void* fn_27_845D8(void*, int);
void* fn_27_84458(void*, int);
void* fn_27_84398(void*, int);
void* fn_27_50588(void*, int);
extern char lbl_27_data_21D78[], lbl_27_data_260C8[], lbl_27_data_25948[], lbl_27_data_25F88[], lbl_27_data_26028[], lbl_27_data_26050[];
}
template <class T> struct soEventUnitWrapper { static char __vt[]; };
template <class T> struct soInstanceUnitFullProperty { char d[0xC]; ~soInstanceUnitFullProperty(); };
class soTurnEventObserver;
class soLinkEventObserver;
struct LinkArray { char pad[12]; soInstanceUnitFullProperty<soLinkEventObserver*> arr[1]; };
#define PART(O,F,N,V) \
 if (p + O) { \
  if (p + O + 12 && p + O + 28) __destroy_arr(p + O + 40,(void (*)(void*,int))F,12,N); \
  if (p + O && p + O) { \
   short id = *(short*)(p + O + 4); \
   *(void**)(p + O) = V; \
   if (id != -1) soEventSystem::getInstance()->getManager(*(short*)(p + O + 4))->eraseUnit(*(short*)(p + O + 6)); \
  } \
 }
#define SPECIAL(O,F,N,T) PART(O,F,N,soEventUnitWrapper<T>::__vt)
extern "C" void* fn_27_36A238(void* obj, int flag) {
 char* p = (char*)obj;
 if (obj) {
  SPECIAL(0x3e8,fn_27_840D8,7,soTurnEventObserver)
  PART(0x3a8,fn_27_84358,1,lbl_27_data_21D78)
  PART(0x36c,fn_27_844D8,1,lbl_27_data_260C8)
  PART(0x310,fn_27_84198,4,lbl_27_data_25948)
  PART(0x2b4,fn_27_845D8,4,lbl_27_data_25F88)
  if (p + 0x278) {
   if (p + 0x284) ((LinkArray*)(p + 0x294))->~LinkArray();
   if (p + 0x278 && p + 0x278) {
    short id = *(short*)(p + 0x27c);
    *(void**)(p + 0x278) = soEventUnitWrapper<soLinkEventObserver>::__vt;
    if (id != -1) soEventSystem::getInstance()->getManager(*(short*)(p + 0x27c))->eraseUnit(*(short*)(p + 0x27e));
   }
  }
  PART(0x17c,fn_27_84458,17,lbl_27_data_26028)
  PART(0xcc,fn_27_84398,11,lbl_27_data_26050)
  ((soEventManageModuleImpl*)(p + 0xb8))->~soEventManageModuleImpl();
  if (p && p + 0x14) __destroy_arr(p + 0x20,(void (*)(void*,int))fn_27_50588,8,19);
  if (flag > 0) __dl__FPv(obj);
 }
 return obj;
}
