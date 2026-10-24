#pragma force_active on
extern "C" {
extern char lbl_27_data_87F80[];
extern char lbl_27_data_248[];
extern const char lbl_27_rodata_7628[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct Vec3 { float x,y,z; Vec3() {} Vec3(float a,float b,float c):x(a),y(b),z(c) {} Vec3(const Vec3& v):x(v.x),y(v.y),z(v.z) {} };
struct Cfg {float f0; char pad[0x24]; float f28, f2c;};
struct Obj {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual void get4(Vec3*);
virtual void set5(int, unsigned long);
virtual void call6(unsigned long, const Vec3&, const Vec3&, int, int, float);
virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
virtual float get12(unsigned long);
};
struct Pos { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual Vec3 get(); };
extern "C" void fn_27_32E048(void*, unsigned char* obj) {
    const float* k = (const float*)lbl_27_rodata_7628;
    unsigned char* d = *(unsigned char**)(obj + 0xD8);
    Obj* a = *(Obj**)(d+0x64);
    Pos* b = *(Pos**)(d+0xC);
    float t = a->get12(0x21000001);
    Cfg* cfg = *(Cfg**)((unsigned char*)__dynamic_cast(*(void**)(obj+8),0x3c,lbl_27_data_87F80,lbl_27_data_248,1)+0x1fe4);
    float r=t/cfg->f0;
    if (!(r > k[0])) { if (r < k[1]) r=k[1]; }
    Obj* c=*(Obj**)(*(unsigned char**)(obj+0xD8)+0x88);
    c->call6(0xb000b,b->get(),Vec3(k[3],k[3],k[3]),0,-1,k[4]);
    a->set5((int)(cfg->f28+cfg->f2c*t),0x20000001);
}