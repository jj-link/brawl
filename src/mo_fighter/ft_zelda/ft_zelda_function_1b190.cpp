#pragma force_active on
typedef unsigned long long u64;
struct Vec2f { float m_x, m_y; };
struct Vec3f { float m_x, m_y, m_z; };
struct Parameters { Vec2f p[4]; };
struct Kinetic {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual Vec3f getPos();
 virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8();
 virtual float getLr();
 virtual void dA(); virtual void dB(); virtual void dC();
 virtual u64 getSpeed(const short*);
 virtual void dE(); virtual void dF(); virtual void dG(); virtual void dH();
 virtual void dI(); virtual void dJ(); virtual void dK(); virtual void dL();
 virtual float getScale();
};
struct Work {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual int call(unsigned int);
};
struct Modules {
 char pad[0xc]; Kinetic* posture; char pad1[0x54]; Work* work;
 char pad2[0x14]; Kinetic* kinetic;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Floats { char pad[8]; float f8; float fc; };
struct Data { char pad[0x88]; Floats* floats; };
struct Object { char pad[0x60]; Accesser* accesser; };
extern "C" {
void fn_27_13CC24(void*);
void fn_104_A024(Parameters*);
void fn_27_13FE28(void*, const Vec3f&, float, float, const Vec2f&, const Parameters&, const Parameters&, int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, unsigned long, unsigned long);
extern const float lbl_104_rodata_E0;
extern const float lbl_104_rodata_E4;
}
extern "C" void fn_104_1B190(Object* object, void* output) {
 Kinetic* posture;
 fn_27_13CC24(object);
 Accesser* accesser = object->accesser;
 Floats* f = (*reinterpret_cast<Data**>(reinterpret_cast<unsigned char*>(object) + 0x1FF74))->floats;
 Parameters b;
 fn_104_A024(&b);
 b.p[0].m_x = lbl_104_rodata_E0;
 b.p[1].m_x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xbd6, 0);
 b.p[2].m_x = lbl_104_rodata_E0;
 b.p[3].m_x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xbd8, 0);
 b.p[0].m_y = -f->f8;
 b.p[1].m_y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xbd1, 0);
 b.p[2].m_y = f->fc;
 b.p[3].m_y = f->fc;
 Parameters a;
 fn_104_A024(&a);
 a.p[0].m_x = lbl_104_rodata_E0;
 a.p[1].m_x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xbbc, 0);
 a.p[2].m_x = lbl_104_rodata_E0;
 a.p[3].m_x = lbl_104_rodata_E4;
 a.p[0].m_y = lbl_104_rodata_E0;
 a.p[1].m_y = lbl_104_rodata_E0;
 a.p[2].m_y = lbl_104_rodata_E0;
 a.p[3].m_y = lbl_104_rodata_E0;
 short flag = -1;
 Vec2f speed;
 *(u64*)&speed = accesser->modules->kinetic->getSpeed(&flag);
 posture = accesser->modules->posture;
 float lr = posture->getLr();
 fn_27_13FE28(output, posture->getPos(), posture->getScale(), lr, speed, a, b, 0x000e0013);
 Work* work = accesser->modules->work;
 *reinterpret_cast<int*>(static_cast<char*>(output) + 0x100) = work->call(0x10000040);
}