#pragma force_active on
class Work {
public:
 virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
 virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
 virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
 virtual float getFloat(unsigned long);
 virtual void setFloat(float, unsigned long);
};
class Motion {
public:
 virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
 virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
 virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
 virtual void a12(); virtual void a13();
 virtual bool exists(int, bool);
 virtual void a15(); virtual void a16();
 virtual void setFrame(int, int, bool);
 virtual void a18();
 virtual float getRate(int);
 virtual void setRate(int, float);
};
class Posture {
public:
 virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
 virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
 virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
 virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
 virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
 virtual void a20(); virtual void a21(); virtual void a22();
 virtual void setScale(float);
};
struct Params { float a,b,c,d,e; };
struct CastResult { char pad[0x1f14]; Params* params; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_104_data_6F90[], lbl_104_data_2EDC[];
extern const float lbl_104_rodata_D0;
void fn_104_1576C(void*, char* self) {
 char* modules = *(char**)(self + 0xd8);
 Work* work = *(Work**)(modules + 0x64);
 Motion* motion = *(Motion**)(modules + 0x1c);
 float value = work->getFloat(0x21000001);
 float rate = work->getFloat(0x21000002);
 Params* p = ((CastResult*)__dynamic_cast(*(void**)(self + 8), 0x3c, lbl_104_data_6F90, lbl_104_data_2EDC, 1))->params;
 float scale = p->b + value * ((p->c - p->b) / p->a);
 (*(Posture**)(*(char**)(self + 0xd8) + 0xc))->setScale(scale);
 int zero = 0;
 if (motion->exists(zero, zero)) {
   int frame = (int)(p->d + p->e * value);
   motion->setFrame(zero, frame, zero);
   if (lbl_104_rodata_D0 == rate) rate = motion->getRate(0);
   motion->setRate(0, rate * scale);
 }
 work->setFloat(rate, 0x21000002);
}
}