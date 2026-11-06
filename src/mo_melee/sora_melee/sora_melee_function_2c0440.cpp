#pragma force_active on

extern "C" {
int fn_27_8C064(unsigned int, unsigned int, unsigned int);
int fn_27_28CCF0(void*, int);
int fn_27_28C800(void*);
int fn_27_28FC14(void*);
}
extern unsigned int lbl_27_bss_71DC[];

struct Base8 { int a; int b; };
class Vtbl8_Class : public Base8 {
public:
 virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(void*, int);
};
class Vtbl0_Class {
public:
 virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(int);
};
struct Obj_Q { unsigned char pad[0x30]; void* field_30; void* field_34; void* field_38; };
struct Obj_P { Obj_Q* field_0; unsigned char pad[0x60]; Vtbl0_Class* field_64; };
struct Obj_X { unsigned char pad[0x8c0]; int field_8c0; };
struct Self { unsigned char pad[8]; Obj_X* field_8; unsigned char pad2[0xcc]; Obj_P* field_d8; };

extern "C" int fn_27_2C0440(int a, Self* self, int id) {
 if (id > 0x5dbf) { Vtbl8_Class* obj=(Vtbl8_Class*)lbl_27_bss_71DC; return obj->v5(self,id); }
 if (id <= 0x59d7) return fn_27_8C064((unsigned int)a,(unsigned int)self,(unsigned int)id);
 if (id > 0x59d8 && id < 0x59e1) { Obj_P* P=self->field_d8; Obj_Q* Q=P->field_0; unsigned char* arr=(unsigned char*)Q->field_30; return *(int*)(arr+(id-0x59d9)*4+0x40); }
 if (id > 0x5b67 && id < 0x5b76) { Obj_P* P=self->field_d8; Obj_Q* Q=P->field_0; unsigned char* arr=(unsigned char*)Q->field_34; return *(int*)(arr+(id-0x5b68)*4+0xa8); }
 if (id > 0x5bcb && id < 0x5bd3) {
  unsigned int idx=(unsigned int)(id-0x5bcc); Obj_X* X=self->field_8;
  switch(idx) {
  case 2: return fn_27_28C800(X);
  case 0: { int state=X->field_8c0; switch(state) { case 4:return fn_27_28CCF0(X,0x5e88); case 0x2f:return fn_27_28CCF0(X,0x66ee); default:return self->field_d8->field_64->v4(0x10000007); } }
  case 1: return self->field_d8->field_64->v4(0x10000007);
  case 3: { int state=X->field_8c0; Vtbl0_Class* v=self->field_d8->field_64; if(state==0x1d||state==0x1b)return v->v4(0x10000000); return 0; }
  case 4: return fn_27_28FC14(X);
  case 5: { int state=X->field_8c0; Vtbl0_Class* v=self->field_d8->field_64; if(state==0xf)return v->v4(0x10000000); if(state==5)return v->v4(0x10000000); return 0; }
  case 6: { int state=X->field_8c0; switch(state) { case 0x40:return self->field_d8->field_64->v4(0x10000000); case 0x58:return 0x67; case 0x4e:return 0x1c8e; default:return 0x65; } }
 }
 }
 Obj_Q* q=self->field_d8->field_0; void* A=q->field_34; void* B=q->field_38;
 switch(id) {
 case 0x5b77: return *(int*)((char*)B+4);
 case 0x5b78: return *(int*)((char*)B+0xc);
 case 0x5b7b: return *(int*)((char*)B+0x3c);
 case 0x5b79: return 0;
 case 0x5b7a: { void* p=*(void**)((char*)A+0xec); if(!p)return 0; return *(int*)((char*)p+4); }
 default: return 0;
 }
}