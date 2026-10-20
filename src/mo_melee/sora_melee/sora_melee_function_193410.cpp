#pragma force_active on
#pragma fp_contract off
struct Vec2 { float x,y; };
struct Vec3 { float x,y,z; };
struct Posture { virtual void s0();
virtual void s1();
virtual void s2();
virtual void s3();
virtual void s4();
virtual void s5();
virtual void s6();
virtual void s7();
virtual void s8(); virtual float direction(); };
struct Kinetic { virtual void s0();
virtual void s1();
virtual void s2();
virtual void s3();
virtual void s4();
virtual void s5();
virtual void s6();
virtual void s7();
virtual void s8();
virtual void s9();
virtual void s10();
virtual void s11();
virtual void s12(); virtual unsigned long long speed(short*); };
struct ModelBase { char pad[8]; };
struct Model : ModelBase { virtual void s0();
virtual void s1();
virtual void s2();
virtual void s3();
virtual void s4();
virtual void s5();
virtual void s6();
virtual void s7();
virtual void s8();
virtual void s9();
virtual void s10();
virtual void s11();
virtual void s12();
virtual void s13();
virtual void s14();
virtual void s15();
virtual void s16();
virtual void s17();
virtual void s18();
virtual void s19();
virtual void s20();
virtual void s21();
virtual void s22();
virtual void s23();
virtual void s24();
virtual void s25();
virtual void s26();
virtual void s27();
virtual void s28(); virtual void rotate(unsigned int,const Vec3*); virtual void t0();
virtual void t1();
virtual void t2(); virtual unsigned int node(int); };
struct Modules { char pad[4]; Model* model; char gap[4]; Posture* posture; char gap2[0x6c]; Kinetic* kinetic; };
struct Access { char pad[0xd8]; Modules* modules; };
extern "C" {
struct Constants { float zero,epsilon,threshold,degrees; };
extern const unsigned char lbl_27_rodata_26B0[];
float rsqrtf__Ff(float);
double atan2(double,double);
double __fabs(double);
inline float magnitude(const Vec2& v, const Constants* c) {
float sum=v.x*v.x+v.y*v.y;
if ((float)__fabs(sum)<=c->epsilon) return c->zero;
return sum*rsqrtf__Ff(sum);
}
inline Vec2 unpack(unsigned long long bits) { return *(Vec2*)&bits; }
float fn_27_193410(Access* a) {
const Constants* c=(const Constants*)lbl_27_rodata_26B0;
float dir=a->modules->posture->direction();
short id=-1;
float angle=c->zero;
Vec2 v=unpack(a->modules->kinetic->speed(&id));
float len=magnitude(v,c);
if(len>c->threshold) {
double y=v.y;
double x=v.x;
angle=c->degrees*(dir*(float)atan2(x,y));
unsigned int n=a->modules->model->node(0x12e);
if(n!=0xffffffff) {
Vec3 rot={angle,c->zero,c->zero};
a->modules->model->rotate(n,&rot);
}
}
return angle;
}
}
