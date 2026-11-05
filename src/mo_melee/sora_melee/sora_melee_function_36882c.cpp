#pragma force_active on
class ClassA { public: virtual int v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
class ClassC { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual float v12(int); };
class ObjB { public: int pad0; int pad1; virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(int, float*); };
struct Pad8 { int a; int b; };
struct Ret { int a; int b; int c; };
class Callback : public Pad8 { public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual Ret v25(int);
};
extern "C" {
void fn_27_36882C(void* a, char* arg) {
 char* p1=*(char**)(arg+0xd8); ClassA* objA=*(ClassA**)(p1+0x70); int r=objA->v16();
 switch(r) {
 case 0: {
  char* p2=*(char**)(arg+0xd8); Callback* ptr1=(Callback*)*(char**)(p2+4);
  const Ret& sp8=ptr1->v25(1);
  char* p3=*(char**)(arg+0xd8); ClassC* objC=*(ClassC**)(p3+0x64);
  *(float*)&sp8=objC->v12(0x21000000);
  char* p4=*(char**)(arg+0xd8); ObjB* ptr2=*(ObjB**)(p4+4); ptr2->v29(1,(float*)&sp8);
  break;
 }
 default: return;
 }
}
}