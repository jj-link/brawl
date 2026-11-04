#pragma force_active on
typedef unsigned int u32;
struct Base1 { virtual void dummy1(); }; struct Base2 { virtual void dummy2(); };
struct Pair { u32 a,b; Pair& operator=(const Pair& p) { a=p.a; b=p.b; return *this; } };
struct Inner { u32 b0; };
struct Nested : Base1, Base2 { Inner inner; Pair pairs[7]; };
struct Element { u32 a0,a1,a2,a3,a4; float f14; u32 a6,a7,a8,a9; float f28,f2c,f30; u32 a13,a14,a15,a16; Nested nested; u32 l0,l1; };
class soNullable { public:
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual int slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual int slot13(); virtual bool slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual Element* slot26(int); virtual int slot27(); virtual int slot28(); virtual void slot29(int);
};
extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(void*, int, bool, int, int, int, int);
extern "C" void fn_27_E4A5C(soNullable* self,int iface,const Element* value) {
 int pos=insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll((char*)self+4,iface,self->slot14(),self->slot3(),self->slot13(),self->slot27(),self->slot28());
 *self->slot26(pos)=*value; self->slot29(self->slot3()+1);
}