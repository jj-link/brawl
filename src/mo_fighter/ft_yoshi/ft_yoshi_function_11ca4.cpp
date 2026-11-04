#include <ft/ft_common_data_accesser.h>
#pragma force_active on
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Accesser;
struct Situation {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual int getKind();
};
struct Kinetic {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void* getEnergy(int);
 virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
 virtual void v11(); virtual void v12(); virtual Vec2 getSumSpeed(const short&);
 virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual void v18(); virtual void v19(); virtual void v20();
 virtual void changeKinetic(int, Accesser*);
};
struct Work {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual float getFloat(int); virtual void setFloat(float, int);
};
struct Ground {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void reset();
};
struct ModelBase { char pad[8]; };
struct Model : ModelBase {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void scale(int, Vec3*); virtual void v25(); virtual void v26();
 virtual void setA(int,float); virtual void setB(int,float);
};
struct Visibility {
 virtual void v0(); virtual void v1(); virtual void set(int,int);
};
struct Modules {
 char pad0[4]; Model* model; char pad1[4]; Ground* ground;
 char pad2[4]; Situation* situation; char pad3[0x40];
 Visibility* visibility; char pad4[8]; Work* work; char pad5[0x14]; Kinetic* kinetic;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" {
extern const unsigned char lbl_95_data_7A88[], lbl_95_data_2C38[], lbl_95_data_810C[];
extern const float lbl_95_rodata_B0, lbl_95_rodata_B4;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_95_11ADC(void*, const Vec2*);
}
extern "C" void fn_95_11CA4(void*, Accesser* accesser) {
 Modules* modules = accesser->modules;
 Work* work = modules->work;
 Situation* situation = modules->situation;
 Kinetic* kinetic = modules->kinetic;
 Ground* ground = modules->ground;
 Model* model = modules->model;
 char* params = *(char**)((char*)g_ftCommonDataAccesser.getData((ftKind)4) + 0x7c);
 short mask = -1;
 Vec2 speed;
 Vec2 sum = kinetic->getSumSpeed(mask);
 __memcpy(&speed, &sum, sizeof(speed));
 if (situation->getKind() == 0) {
   kinetic->changeKinetic(6, accesser);
   speed.x *= *(float*)(params + 0x88);
   void* stop = __dynamic_cast(kinetic->getEnergy(3), 0, lbl_95_data_7A88, lbl_95_data_2C38, 1);
   fn_95_11ADC(stop, &speed);
 } else {
   kinetic->changeKinetic(10, accesser);
   speed.x *= *(float*)(params + 0x88);
   speed.y *= *(float*)(params + 0x8c);
   void* stop = __dynamic_cast(kinetic->getEnergy(3), 0, lbl_95_data_7A88, lbl_95_data_2C38, 1);
   Vec2 tmp = {speed.x, lbl_95_rodata_B0};
   fn_95_11ADC(stop, &tmp);
   ((char*)stop)[6] = 1;
   void* gravity = __dynamic_cast(kinetic->getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1);
   *(float*)((char*)gravity + 0xc) = speed.y;
 }
 Vec3 scale = {lbl_95_rodata_B4, lbl_95_rodata_B4, lbl_95_rodata_B4};
 model->scale(2, &scale);
 if (lbl_95_rodata_B0 != work->getFloat(0x21000008)) ground->reset();
 float zero = lbl_95_rodata_B0;
 work->setFloat(zero, 0x21000008);
 model->setA(3, lbl_95_rodata_B0);
 model->setB(2, lbl_95_rodata_B0);
 accesser->modules->visibility->set(1,1);
}