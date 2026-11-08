#pragma force_active on
extern "C" void fn_80325184(void*, void*, void*, void*);
extern "C" char lbl_80486E28[];
extern "C" char lbl_80486E64[];

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
 char data[16];
 unsigned short aC; unsigned short aE; unsigned short a10; unsigned short a12;
 unsigned short a14; unsigned short a16; unsigned short a18; unsigned short a1A;
 Class_802A0E20() {}
 ~Class_802A0E20();
};

class Object_802BD804 : public Class_802A0DA4, public Class_802A0E20 {
public:
 Object_802BD804(void** source, int value) {
  a6 = 1; a8 = value;
  void* input = *source;
  vt = lbl_80486E64;
  aC = 0xFFFF; aE = 0xFFFF; a10 = 0xFFFF; a12 = 0xFFFF;
  a14 = 0xFFFF; a16 = 0xFFFF; a18 = 0xFFFF; a1A = 0xFFFF;
  fn_80325184((char*)input + 0x10, data, input, lbl_80486E64);
  vt = lbl_80486E28;
 }
};

extern "C" Object_802BD804* fn_802BD804(void** arg, int, int, int value) {
 Object_802BD804* object0 = new Object_802BD804(arg, value);
 return object0;
}
