#pragma force_active on
extern "C" void fn_80325184(void*, void*, void*, void*);
extern "C" char lbl_804870F0[];
extern "C" char lbl_8048712C[];
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void* slot4(int, int);
};
extern Object_vptr_0* lbl_805A0EB8;
class Class_802A0DA4 {
public:
 struct Allocation { void* vt; unsigned short size; };
 static void operator delete(void*);
 static void* operator new(unsigned long size) {
  Allocation* p = (Allocation*)lbl_805A0EB8->slot4(size, 0x1D);
  p->size = size;
  return p;
 }
};
class Class_802A0E20 {
public:
 void* vt; unsigned short a4; unsigned short a6; int a8; unsigned short aC; unsigned short aE;
 Class_802A0E20() {}
 ~Class_802A0E20();
};
class Object_802C7064 : public Class_802A0DA4, public Class_802A0E20 {
public:
 char data[16];
 Object_802C7064(void** source, int value) {
  a6 = 1; a8 = value;
  void* input = *source;
  vt = lbl_8048712C; aC = 0xFFFF;
  fn_80325184((char*)input + 0x10, data, input, lbl_8048712C);
  vt = lbl_804870F0;
 }
};
extern "C" Object_802C7064* fn_802C7064(void** arg, int, int, int value) {
 Object_802C7064* object0 = new Object_802C7064(arg, value);
 return object0;
}
