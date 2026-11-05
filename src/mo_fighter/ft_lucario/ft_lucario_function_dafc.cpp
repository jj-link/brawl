#pragma force_active on
#pragma always_inline on
#pragma inline_depth(8)
struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };
struct Accesser;
class Kinetic { public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void* getEnergy(int);
 virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual Vec2f getSumSpeed(const short&);
};
class StopEnergy { public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void resetEnergy(int, Vec2f*, Vec3f*, Accesser*);
};
class GravityEnergy { public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13();
 unsigned char _04, _05; char pad[6]; float _0c, _10, _14, _18, _1c;
};
class Work { public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12();
 virtual void f13(int);
};
class Ground { public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
};
struct Modules { char pad0[0xc]; Ground* ground; char pad1[0x54]; Work* work; char pad2[0x14]; Kinetic* kinetic; };
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" {
extern const char lbl_118_data_620C[], lbl_118_data_17B0[], lbl_118_data_6708[];
extern const float lbl_118_rodata_30;
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
Vec3f* fn_118_8DF0(Vec3f*, float, float, float);
void fn_27_89DAC(int, Accesser*);
void fn_118_8E70(Accesser*, int);
}
extern "C" void fn_118_DAFC(void*, Accesser* accesser) {
 Modules* modules = accesser->modules;
 Work* work = modules->work;
 Kinetic* kinetic = modules->kinetic;
 StopEnergy* stop = static_cast<StopEnergy*>(__dynamic_cast(kinetic->getEnergy(3), 0, lbl_118_data_620C, lbl_118_data_17B0, 1));
 short mask = 1;
 Vec2f scaled;
 Vec2f original = kinetic->getSumSpeed(mask);
 *reinterpret_cast<unsigned int*>(&scaled) = *reinterpret_cast<unsigned int*>(&original);
 *(reinterpret_cast<unsigned int*>(&scaled) + 1) = *(reinterpret_cast<unsigned int*>(&original) + 1);
 scaled.x /= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfb8, 0);
 Vec2f speed;
 speed.x = scaled.x;
 speed.y = lbl_118_rodata_30;
 Vec3f rotation;
 stop->resetEnergy(6, &speed, fn_118_8DF0(&rotation, lbl_118_rodata_30, lbl_118_rodata_30, lbl_118_rodata_30), accesser);
 reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
 GravityEnergy* gravity = static_cast<GravityEnergy*>(__dynamic_cast(kinetic->getEnergy(1), 0, lbl_118_data_6708, lbl_118_data_17B0, 1));
 gravity->_0c = lbl_118_rodata_30;
 reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
 fn_27_89DAC(2, accesser);
 fn_27_89DAC(0, accesser);
 accesser->modules->ground->f9();
 work->f13(0x21000004);
 fn_118_8E70(accesser, 0);
}
