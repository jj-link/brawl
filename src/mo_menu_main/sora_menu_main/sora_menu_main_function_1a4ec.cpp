#pragma force_active on
struct Class_728_base { char pad[0x3c]; };
class Class_728 : public Class_728_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void fn_2_36914(); virtual void fn_2_36908(); virtual void fn_2_361C4(int,int);
};
struct Params {
 int a,b,c,d,e,f,g,h,i,j,k; char l; int m,n,o,p,q,r,s; char t;
 Params() { l=1; b=0;c=0;d=0;e=0;h=0;i=-1;j=0xf0;k=0;l=1;m=0;n=0;o=0;p=0;q=0;r=0;s=0;t=0; }
};
struct Owner { char pad[0x180]; void* object; };
struct Self { char pad0[0x42]; short field42; char pad44[0x608]; Owner* owner; char pad650[4]; int field654; Class_728* object; char pad65c[8]; int field664; char pad668[0x28]; int field690; int field694; };
extern "C" int fn_11_0(Params*); extern "C" void fn_800B5854(void*,int,int,int,int); extern "C" void fn_800B330C(void*,void*,int); extern "C" void fn_80078990(void*);
extern int lbl_2_data_2514; extern void* lbl_805A01D8;
extern "C" void fn_2_1A4EC(Self* self,int arg) { self->field654=arg; self->field664=0; self->field42=0; self->field694=0; Params p; p.a=2;p.f=arg;p.g=0x20;p.h=self->field690;p.m=0;p.n=0;p.b=0;self->field694=fn_11_0(&p);self->object->fn_2_361C4(0x19,0x46);fn_800B5854(self->owner->object,0,0x17,0,0);fn_800B330C(self->owner->object,&lbl_2_data_2514,0);fn_80078990(lbl_805A01D8);}