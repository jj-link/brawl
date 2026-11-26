#include <types.h>
#include <new>
#include <so/event/so_event_manage_module_impl.h>
#pragma force_active on

class soLinkEventObserver;
class soTurnEventObserver;
template<> class soEventUnitWrapper<soLinkEventObserver> { public: static char __vt[]; };
template<> class soEventUnitWrapper<soTurnEventObserver> { public: static char __vt[]; };
template<> class soInstanceUnitFullProperty<soLinkEventObserver*> {
public:
 char data[12];
 soInstanceUnitFullProperty();
 ~soInstanceUnitFullProperty();
};

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*,int), unsigned long, unsigned long);
void __ct__23soEventManageModuleImplFPv(soEventManageModuleImpl*, void*);
extern char lbl_27_data_210B0[];
extern char lbl_27_data_5460[];
extern char lbl_27_data_18830[];
extern char lbl_27_data_26050[];
extern char lbl_27_data_26028[];
extern char lbl_27_data_19B18[];
extern char lbl_27_data_25B70[];
extern char lbl_27_data_25C60[];
extern char lbl_27_data_25F88[];
extern char lbl_27_data_25948[];
extern char lbl_27_data_21D78[];
extern char lbl_27_data_21998[];
extern char lbl_27_data_21A90[];
extern char lbl_27_data_18AD0[];
extern char lbl_27_data_41600[];
extern char lbl_27_data_416F0[];
extern char lbl_27_data_334A0[];
extern char lbl_27_data_40DE0[];
extern char lbl_27_data_40ED0[];
extern char lbl_27_data_33260[];
extern char lbl_27_data_44238[];
extern char lbl_27_data_44330[];
extern char lbl_27_data_3F7B0[];
extern char lbl_27_data_25398[];
extern char lbl_27_data_25488[];
extern char lbl_27_data_19918[];
extern char lbl_27_data_41C08[];
extern char lbl_27_data_41CF8[];
extern char lbl_27_data_33650[];
void fn_27_5057C(void*);
void fn_27_50588(void*,int);
void fn_27_EF114(void*);
void fn_27_84398(void*,int);
void fn_27_EF12C(void*);
void fn_27_84458(void*,int);
void fn_27_EF1BC(void*);
void fn_27_845D8(void*,int);
void fn_27_EF0CC(void*);
void fn_27_84198(void*,int);
void fn_27_EF1EC(void*);
void fn_27_84358(void*,int);
void fn_27_1BA420(void*);
void fn_27_840D8(void*,int);
}
struct Array { void* vt; void* vt2; u32 bits; char elements[152]; };
struct Manager {
 void* vt; unsigned char flag; void* secondary; unsigned char flag2;
 Array* array; Array storage;
};
inline void initializeManager(Manager* p) {
 p->flag=0; p->flag2=0; p->secondary=lbl_27_data_5460;
 p->array=&p->storage; p->vt=lbl_27_data_18830;
 Array* a=&p->storage;
 a->vt=lbl_27_data_210B0; a->vt2=lbl_27_data_210B0+0x48;
 a->bits &= 0x1fff;
 __construct_array(a->elements,fn_27_5057C,fn_27_50588,8,19);
}
struct LinkArray { soInstanceUnitFullProperty<soLinkEventObserver*> elements[1]; };

template<int N, u32 MASK, char* V1, char* V2, void (*CT)(void*), void (*DT)(void*,int)>
struct Work {
 void* vtable; unsigned char flag; unsigned char pad[3];
 void* table14; void* table18; void* table1c; void* table20;
 u32 flags; unsigned char array[N*12]; unsigned char end;
 void initialize() {
  flag = 0;
  vtable = V1;
  table14 = V1 + 0x34;
  table18 = V1 + 0x40;
  table1c = V2;
  table20 = V2 + 0x48;
  flags &= MASK;
  initializeElements(array);
  end = 0;
 }
 static void initializeElements(unsigned char* elements) {
  __construct_array(elements, CT, DT, 0xC, N);
 }
};
template<char* V1, char* V2>
struct LinkWork {
 void* vtable; unsigned char flag; unsigned char pad[3];
 void* table14; void* table18; void* table1c; void* table20;
 u32 flags; unsigned char array[12]; unsigned char end;
 void initialize() {
  flag = 0;
  vtable = V1;
  table14 = V1 + 0x34;
  table18 = V1 + 0x40;
  table1c = V2;
  table20 = V2 + 0x48;
  flags &= 0x1ffffff;
  initializeElements(array);
  end = 0;
 }
 static void initializeElements(unsigned char* elements) {
  reinterpret_cast<LinkArray*>(elements)->__ct();
 }
};

template<char* WRAP>
struct Base {
 void* vtable; s16 manager; s16 event;
 void init(s16 m, s16 e) {
  manager = m;
  vtable = WRAP;
  event = e;
  if (m == -1) return;
  s16 id = soEventSystem::getInstance()->getManager(manager)->addUnit((soEventUnit*)this);
  if (id <= -1) return;
  event = id;
 }
};

template<char* WRAP, char* BASE, class W>
struct Unit : Base<WRAP> {
 W* workPtr; W work;
 void init(s16 m, s16 e) {
  Base<WRAP>::init(m, e);
  W* storage = (workPtr = &work);
  this->vtable = BASE;
  storage->initialize();
 }
};

typedef Unit<lbl_27_data_26050, lbl_27_data_334A0, Work<10, 0xffff, lbl_27_data_41600, lbl_27_data_416F0, fn_27_EF114, fn_27_84398> > Unit1;
typedef Unit<lbl_27_data_26028, lbl_27_data_33260, Work<18, 0x1fff, lbl_27_data_40DE0, lbl_27_data_40ED0, fn_27_EF12C, fn_27_84458> > Unit2;
typedef Unit<soEventUnitWrapper<soLinkEventObserver>::__vt, lbl_27_data_19B18, LinkWork<lbl_27_data_25B70, lbl_27_data_25C60> > Unit3;
typedef Unit<lbl_27_data_25F88, lbl_27_data_3F7B0, Work<4, 0x7ffff, lbl_27_data_44238, lbl_27_data_44330, fn_27_EF1BC, fn_27_845D8> > Unit4;
typedef Unit<lbl_27_data_25948, lbl_27_data_19918, Work<4, 0x7ffff, lbl_27_data_25398, lbl_27_data_25488, fn_27_EF0CC, fn_27_84198> > Unit5;
typedef Unit<lbl_27_data_21D78, lbl_27_data_18AD0, Work<1, 0x1ffffff, lbl_27_data_21998, lbl_27_data_21A90, fn_27_EF1EC, fn_27_84358> > Unit6;
typedef Unit<soEventUnitWrapper<soTurnEventObserver>::__vt, lbl_27_data_33650, Work<6, 0x7ffff, lbl_27_data_41C08, lbl_27_data_41CF8, fn_27_1BA420, fn_27_840D8> > Unit7;

struct Root {
 Manager manager;
 soEventManageModuleImpl event;
};

#define UNIT(T, OFF) ((T*)((char*)p + (OFF)))

extern "C" void* fn_27_36F9DC(void* arg0) {
 Root* p=(Root*)arg0;
 initializeManager(&p->manager);
 __ct__23soEventManageModuleImplFPv(&p->event,p);
 UNIT(Unit1,0xcc)->init(p->event.getManageId(), 4);
 UNIT(Unit2,0x170)->init(p->event.getManageId(), 5);
 UNIT(Unit3,0x278)->init(p->event.getManageId(), 7);
 UNIT(Unit4,0x2b4)->init(p->event.getManageId(), 1);
 UNIT(Unit5,0x310)->init(p->event.getManageId(), 9);
 UNIT(Unit6,0x370)->init(p->event.getManageId(), 14);
 UNIT(Unit7,0x3b0)->init(p->event.getManageId(), 18);
 return p;
}
