#pragma force_active on
extern "C" void fn_80325334(void*, void*, void*, void*);
extern "C" char lbl_804869E4[];
extern "C" char lbl_804869A8[];

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
 void* vt; unsigned short a4; unsigned short a6; int a8;
 unsigned short aC; unsigned short aE; unsigned short a10;
 unsigned int data[5];
 Class_802A0E20() {}
 ~Class_802A0E20();
};

class Object_802AC3D8 : public Class_802A0DA4, public Class_802A0E20 {
public:
 Object_802AC3D8(void** source, int value) {
  a6 = 1; a8 = value;
  void* input = *source;
  vt = lbl_804869E4;
  aC = 0xFFFF; aE = 0xFFFF; a10 = 0xFFFF;
  fn_80325334((char*)input + 0x10, data, input, lbl_804869E4);
  vt = lbl_804869A8;
 }
};

extern "C" Object_802AC3D8* fn_802AC3D8(void** arg, int, int, int value) {
 Object_802AC3D8* object0 = new Object_802AC3D8(arg, value);
 return object0;
}
