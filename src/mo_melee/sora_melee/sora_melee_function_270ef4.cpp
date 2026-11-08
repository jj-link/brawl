#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_27_data_57CB0[];
extern "C" unsigned char lbl_27_data_57D30[];
extern "C" const float lbl_27_rodata_4450;
struct Vec3 {
 float x,y,z;
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3& operator=(const Vec3& o) {
  ((unsigned int*)this)[0]=((const unsigned int*)&o)[0];
  ((unsigned int*)this)[1]=((const unsigned int*)&o)[1];
  ((unsigned int*)this)[2]=((const unsigned int*)&o)[2];
  return *this;
 }
};
struct Input { unsigned int word; unsigned short half; };
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 unsigned int field4;
 float field8;
 unsigned char fieldC, fieldD;
 unsigned short padE;
 int field10;
 Input input;
 Vec3 position;
 unsigned char pad28[0x18];
 float field40;
 unsigned char field44;
};
extern "C" Object_vptr_0* fn_27_270EF4(int arg0, const Input* arg1) {
 Object_vptr_0* obj=(Object_vptr_0*)__nw__FUlQ25Heaps8HeapType(0x48,15);
 if(obj) {
  *(void**)obj=lbl_27_data_57CB0;
  obj->field4=0;
  obj->field8=lbl_27_rodata_4450;
  obj->fieldC=1;
  obj->fieldD=0;
  *(void**)obj=lbl_27_data_57D30;
  obj->field10=arg0;
  obj->input=*arg1;
  obj->position=Vec3(lbl_27_rodata_4450,lbl_27_rodata_4450,lbl_27_rodata_4450);
  obj->field40=lbl_27_rodata_4450;
  obj->field44=0;
  obj->slot2();
 }
 return obj;
}