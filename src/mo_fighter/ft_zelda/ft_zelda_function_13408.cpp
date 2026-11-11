#pragma force_active on
#pragma opt_propagation off
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_104_data_6E28[], lbl_104_data_2EDC[], lbl_104_data_80B4[], lbl_104_data_2404[];
extern const float lbl_104_rodata_A8, lbl_104_rodata_AC;
double cos(double); double sin(double);
float fn_104_136DC(float);
}
struct Accesser { char pad[0xd8]; const void* modules; };
struct Work {
virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
virtual float getFloat(unsigned long); virtual void setFloat(float,unsigned long);
virtual void m14(); virtual void m15(); virtual void m16(); virtual int isFlag(unsigned long);
};
struct Posture {
virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual float getA();
virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15(); virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19(); virtual void p20(); virtual void p21(); virtual void p22(); virtual void set64(float);
};
struct Controller {
virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15(); virtual float get48(); virtual void c17(); virtual float get50();
};
struct Kinetic { virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3(); virtual void k4(); virtual void k5(); virtual void* getEnergy(int); };
struct Vec { float x, y; };
inline void stick(Controller* c, Vec* v) { v->x=c->get48(); v->y=c->get50(); }
extern "C" void fn_104_13408(void*, Accesser* accesser) {
const void* e=accesser->modules;
Work* work=*(Work**)((const char*)e+0x64);
Controller* controller=*(Controller**)((const char*)e+0x5c);
Posture* posture=*(Posture**)((const char*)e+0xc);
Kinetic* kinetic=*(Kinetic**)((const char*)e+0x7c);
float* data=*(float**)((char*)__dynamic_cast(*(void**)((char*)accesser+8),0x3c,lbl_104_data_6E28,lbl_104_data_2EDC,1)+0x207c);
if (!work->isFlag(0x22000000)) {
float facing=posture->getA();
Vec s; stick(controller, &s);
float angle=work->getFloat(0x21000002);
if (fn_104_136DC(s.y)>data[8]) {
angle += facing * (data[9] * s.y);
if (fn_104_136DC(angle)>data[10]) {
float limit=data[10];
angle = angle > lbl_104_rodata_A8 ? limit : -limit;
}
work->setFloat(angle,0x21000002);
}
float speed=work->getFloat(0x21000003); speed += data[6];
if (speed>data[7]) speed=data[7];
work->setFloat(speed,0x21000003);
float base=(facing>lbl_104_rodata_A8)?lbl_104_rodata_A8:lbl_104_rodata_AC;
Vec velocity;
velocity.x=speed*(float)cos(base+angle);
velocity.y=speed*(float)sin(base+angle);
float* target=(float*)__dynamic_cast(kinetic->getEnergy(0),0,lbl_104_data_80B4,lbl_104_data_2404,1);
target[2]=velocity.x; target[3]=velocity.y;
}
float val=work->getFloat(0x21000001);
float result = data[2]+val*((data[3]-data[2])/data[1]);
posture->set64(result);
}