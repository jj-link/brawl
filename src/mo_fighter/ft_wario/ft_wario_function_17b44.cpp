#pragma force_active on
class Class_70F0 {
public:
 virtual void fn_110_6E04();
 virtual void fn_110_FF5C();
 virtual void fn_110_12CAC();
 virtual void fn_110_12CA4();
 virtual void fn_110_12C9C();
 virtual void fn_110_12C94(int, int);
 virtual void fn_110_12C8C();
 virtual void fn_110_12C84(int);
 virtual void fn_110_12C7C();
 virtual void fn_110_12C74();
 virtual void fn_110_12C6C();
 virtual void fn_110_12C64();
 virtual float fn_110_12C5C(int);
 virtual void fn_110_12C54(float, int);
 virtual void fn_110_12C04();
 virtual void fn_110_12C4C();
 virtual void fn_110_12C3C();
 virtual void fn_110_12C2C();
 virtual void fn_110_12C1C();
};
class Class_80F8 {
public:
 virtual void fn_110_15550();
 virtual void fn_110_15548();
 virtual void fn_110_15540();
 virtual void fn_110_15538();
 virtual void fn_110_15530();
 virtual void fn_110_15528();
 virtual void fn_110_15520();
 virtual void fn_110_15518();
 virtual void fn_110_1550C();
 virtual void fn_110_15504();
 virtual void fn_110_154FC();
 virtual void fn_110_154F4();
 virtual void fn_110_154F0();
 virtual void fn_110_154EC();
 virtual void fn_110_154E8();
 virtual void fn_110_154E4();
 virtual void fn_110_154DC();
 virtual void fn_110_154D8();
 virtual float fn_110_154D0();
};
class Kinetic {
public:
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void* getEnergy(int);
};
struct Vec2 { float x, y; };
struct Params { char pad[0x5c]; float max, rate, dec; };
struct Fighter { char pad[0x2980]; Params* params; };
struct Modules { char pad[0x5c]; Class_80F8* motion; char pad2[4]; Class_70F0* work; char pad3[0x14]; Kinetic* kinetic; };
struct Accesser { char pad[8]; void* object; char pad2[0xcc]; Modules* modules; };
extern "C" {
extern const unsigned char lbl_110_data_60DC[], lbl_110_data_168C[], lbl_110_data_5EF0[], lbl_110_data_212C[];
extern const float lbl_110_rodata_140;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_110_B860(Vec2*, const Vec2*);
void fn_110_155E8(void*, Accesser*);
void fn_110_17B44(void* self, Accesser* accesser) {
 Modules* modules = accesser->modules;
 Class_70F0* work = modules->work;
 Class_80F8* motion = modules->motion;
 void* energy = __dynamic_cast(modules->kinetic->getEnergy(0), 0, lbl_110_data_60DC, lbl_110_data_168C, 1);
 Vec2 zero;
 zero.x = lbl_110_rodata_140;
 zero.y = lbl_110_rodata_140;
 fn_110_B860((Vec2*)((char*)energy + 0x10), &zero);
 Params* params = ((Fighter*)__dynamic_cast(accesser->object, 0x3c, lbl_110_data_5EF0, lbl_110_data_212C, 1))->params;
 float speed = motion->fn_110_154D0();
 float value = work->fn_110_12C5C(0x21000000) - params->dec;
 if (speed > lbl_110_rodata_140) {
  value += params->rate * speed;
  if (value > params->max) value = params->max;
 }
 work->fn_110_12C54(value, 0x21000000);
 if (value >= params->max) work->fn_110_12C84(0x20000002);
 else work->fn_110_12C94(0, 0x20000002);
 fn_110_155E8(self, accesser);
}
}