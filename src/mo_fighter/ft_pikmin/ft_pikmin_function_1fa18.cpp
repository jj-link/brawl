#pragma force_active on
#pragma opt_propagation off
struct Vec2 { float x,y; }; struct Temp { char data[0x34]; }; struct Flag { unsigned char value; }; struct Access;
struct ParamBase { char pad[8]; }; struct Param:ParamBase { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual float v4(Access*,unsigned int,unsigned int); };
struct Status { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); };
struct Posture { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual float v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual float v22(); };
struct Work { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual float v12(unsigned int); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual unsigned int v17(unsigned int); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual Param* v23(); };
struct Modules { char p0[12]; Posture* posture; char p1[0x54]; Work* work; char p2[20]; Status* status; }; struct Access { char pad[0xd8]; Modules* mods; };
extern "C" { extern const float lbl_113_rodata_88[]; Vec2* fn_113_C30C(Vec2*,float,float); void fn_8003DC64(Vec2*,float,Vec2*); Temp* fn_113_1E0A0(Temp*,const Vec2*,const Vec2*,const Vec2*,const Vec2*,const Vec2*,unsigned char,unsigned char); void* fn_113_1E164(void*,Temp*); void fn_113_4730(Temp*,short); void fn_113_BC00(Vec2*,const Vec2*); }
extern "C" void fn_113_1FA18(void* p0,char* owner,Access* access) {
 const float* cf=lbl_113_rodata_88; char* obj;
 access->mods->status->v12(); Param* param=access->mods->work->v23();
 float a=param->v4(access,0xfdb,0), b=param->v4(access,0xfd9,0); Vec2 v; fn_113_C30C(&v,b,a);
 if(access->mods->work->v17(0x22000000)==1) v.x*=param->v4(access,0xfb8,0);
 if(access->mods->posture->v9()<cf[2]) v.x=-v.x;
 float r2=access->mods->posture->v22(); if(r2<cf[4]) v.x*=r2;
 float wr=access->mods->work->v12(0x21000000); if(cf[2]!=wr) { fn_8003DC64(&v,-wr,&v); float r4=access->mods->posture->v9(); if(v.x*r4<cf[2]) v.x=cf[2]; }
 Flag flag={0}; obj=owner+0x10; Vec2 e,d,cv,b2,a2;
 a2.x=cf[3]; a2.y=cf[3]; b2.x=cf[2]; b2.y=cf[2]; cv.x=cf[3]; cv.y=cf[3]; d.x=cf[2]; d.y=cf[2]; e.x=cf[2]; e.y=cf[2];
 Temp temp; fn_113_1E0A0(&temp,&e,&d,&cv,&b2,&a2,0,0); fn_113_1E164(obj,&temp); fn_113_4730(&temp,0);
 Vec2 vel; vel.x=v.x; vel.y=cf[2]; fn_113_BC00((Vec2*)(obj+8),&vel);
 Vec2 p; p.x=param->v4(access,0xfda,0); p.y=cf[3]; fn_113_BC00((Vec2*)(obj+0x28),&p);
 obj[5]|=0x80; Flag flag2={0}; *(float*)(owner+0x58)=v.y; *(float*)(owner+0x5c)=-param->v4(access,0xfd4,0); *(float*)(owner+0x60)=param->v4(access,0xfd5,0); ((unsigned char*)owner)[0x55]|=0x80;
}