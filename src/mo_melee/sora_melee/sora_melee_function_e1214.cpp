#pragma force_active on
struct Pair { int a, b; };
struct Data {
 int a; short b,c; float d,e;
 Pair f; int g,h; Pair i; int j;
 unsigned short k,l;
 unsigned char m0,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10;
 int n; Pair o; int p; float q;
 int r,s,t,u; float v,w,x; int y,z,aa,ab;
 float ac,ad; Pair ae; int af;
 float ag,ah,ai,aj,ak,al,am,an;
 unsigned char ao,ap,aq,ar,as;
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual Data* slot26(int);
};
extern "C" void fn_27_E1214(Object_vptr_0* obj, int from, int to) {
 Data* src = obj->slot26(from);
 Data* dst = obj->slot26(to);
 *dst = *src;
}