#pragma force_active on
typedef unsigned int u32;
struct Flags { u32 pad; u32 flags; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(int,int); virtual void slot5();
 Flags* data; u32 state;
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
 virtual void processDefault(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void processPreMapCorrection(); virtual void slot5(); virtual void processFixPosition(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
 virtual void slot12(); virtual void processEffect(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
 virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(); virtual void slot42(int); virtual void slot43();
 virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
 virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
 virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
 virtual void slot56(); virtual void slot57(); virtual void slot58(); virtual void slot59();
 virtual void slot60(); virtual void slot61(); virtual void slot62(); virtual void slot63();
 virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67();
 virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71();
 virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
 virtual void slot76(); virtual void slot77(); virtual void slot78(const char*);
};
struct Obj {
 Obj(const char*);
 char pad0[0x3c]; void* vtable; char pad40[0x90]; char part[0xc];
 char paddc[0xd0]; unsigned char flag; char pad1ad[3]; int value;
};
namespace Heaps { enum HeapType { StageInstance = 15 }; }
extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" Obj* fn_63_10C5C(Obj*, const char*);
extern char lbl_63_data_5080[];
inline Obj::Obj(const char* name) {
 fn_63_10C5C(this, name);
 flag = 0;
 value = -1;
 vtable = lbl_63_data_5080;
 Object_vptr_0* p = (Object_vptr_0*)part;
 if (!p) return;
 p->slot5();
 p->state = 1;
 p->slot4(0, 15);
 p->data->flags |= 1;
 p->data->flags |= 4;
}
extern "C" Obj* fn_63_1244C(int a, const char* b, const char* c) {
 Obj* obj = new (Heaps::StageInstance) Obj(c);
 if (obj) {
  ((Object_vptr_3c*)obj)->slot42(a);
  ((Object_vptr_3c*)obj)->slot78(b);
 }
 return obj;
}