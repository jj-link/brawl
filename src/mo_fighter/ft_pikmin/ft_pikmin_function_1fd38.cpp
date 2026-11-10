#pragma force_active on
#pragma opt_propagation off
struct V2 { float x,y; };
struct W { unsigned int a,b; };
struct Attr { short v; };
struct Flag { unsigned char value; };
struct Kinetic {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void unableAll(); virtual W getSum(Attr*);
};
struct Access;
struct ParamBase { char pad[8]; };
struct Param : ParamBase {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual float get(Access*, int, int);
};
struct WorkMgr {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual Param* getParam();
};
struct Modules { char p0[0x64]; WorkMgr* work; char p1[0x7c-0x68]; Kinetic* kinetic; };
struct Access { char pad[0xd8]; Modules* mods; };
struct Temp { char data[0x34]; };
extern "C" {
extern const float lbl_113_rodata_90, lbl_113_rodata_94;
Temp* fn_113_1E0A0(Temp*,const V2*,const V2*,const V2*,const V2*,const V2*,unsigned char,unsigned char);
void* fn_113_1E164(void*,Temp*);
void fn_113_4730(Temp*,short);
void fn_113_BC00(void*,const void*);
V2* fn_113_C30C(V2*,float,float);
}
extern "C" void fn_113_1FD38(void*, unsigned char* owner, Access* accesser) {
 unsigned char* obj;
 Attr attr; attr.v=1;
 W s;
 W r=accesser->mods->kinetic->getSum(&attr);
 s.a=r.a; s.b=r.b;
 accesser->mods->kinetic->unableAll();
 Param* params=accesser->mods->work->getParam();
 Flag flag={0};
 obj=owner+0x10;
 V2 e,d,c,b,a;
 a.x=lbl_113_rodata_94; a.y=lbl_113_rodata_94;
 b.x=lbl_113_rodata_90; b.y=lbl_113_rodata_90;
 c.x=lbl_113_rodata_94; c.y=lbl_113_rodata_94;
 d.x=lbl_113_rodata_90; d.y=lbl_113_rodata_90;
 e.x=lbl_113_rodata_90; e.y=lbl_113_rodata_90;
 Temp temp;
 fn_113_1E0A0(&temp,&e,&d,&c,&b,&a,0,0);
 fn_113_1E164(obj,&temp);
 fn_113_4730(&temp,0);
 fn_113_BC00(obj+8,&s);
 V2 z;
 z.x=lbl_113_rodata_90; z.y=lbl_113_rodata_90;
 fn_113_BC00(obj+0x18,&z);
 V2 p1;
 fn_113_C30C(&p1,params->get(accesser,0xfc8,0),params->get(accesser,0xfc8,0));
 fn_113_BC00(obj+0x20,&p1);
 V2 p2;
 fn_113_C30C(&p2,params->get(accesser,0xfc9,0),params->get(accesser,0xfc9,0));
 fn_113_BC00(obj+0x28,&p2);
 obj[5]|=0x80;
}