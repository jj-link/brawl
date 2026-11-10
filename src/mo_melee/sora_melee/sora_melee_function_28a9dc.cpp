#pragma force_active on
typedef unsigned int u32;
struct Vec { float x,y,z; Vec() {} Vec(float a,float b,float c){x=a;y=b;z=c;} };
class DB4 {
public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual Vec v4();
virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
virtual Vec v14(int);
virtual void v15(); virtual void v16(); virtual void v17(); virtual float v18();
virtual void v19(); virtual void v20(); virtual void v21(); virtual float v22();
virtual void v23(); virtual float v24();
};
class Obj2 { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual u32 v4(u32);
};
struct Pad { u32 pad; };
class Base { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
};
class A04: public Pad, public Base { public:
virtual void a(u32,Vec*,Vec*,Vec*);
virtual void filler23(); virtual void b(u32,Vec*); virtual void filler25(); virtual void filler26(); virtual void filler27(); virtual void filler28(); virtual void c(u32,const Vec&); virtual void filler30(); virtual void d(u32,Vec*);
};
extern "C" {
extern float lbl_27_rodata_4610;
void fn_27_28A9DC(char* self) {
Vec scale;
Vec rot;
Vec pos;
u32 result;
float value=((DB4*)(self+0xDB4))->v22();
scale.z=value; scale.y=value; scale.x=value;
pos=((DB4*)(self+0xDB4))->v4();
rot=((DB4*)(self+0xDB4))->v14(0);
result=((Obj2*)(self+0x2AAC))->v4(0x10000015);
if(result==0) {
rot.y+=((DB4*)(self+0xDB4))->v18();
((A04*)(self+0xA04))->a(0,&scale,&rot,&pos);
return;
}
((A04*)(self+0xA04))->d(0,&pos);
((A04*)(self+0xA04))->b(0,&scale);
float y=((DB4*)(self+0xDB4))->v18();
((A04*)(self+0xA04))->c(0,Vec(lbl_27_rodata_4610,y,lbl_27_rodata_4610));
((A04*)(self+0xA04))->c(result,rot);
}
}
