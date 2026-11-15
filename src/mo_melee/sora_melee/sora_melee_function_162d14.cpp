#include <types.h>
#pragma force_active on
struct Vec2f { float m_x; float m_y; Vec2f& operator=(const Vec2f& rhs) { ((u32*)this)[0] = ((const u32*)&rhs)[0]; ((u32*)this)[1] = ((const u32*)&rhs)[1]; return *this; } };
struct Vec3f { float m_x; float m_y; float m_z; };
class KineticModule { public:
 virtual void f0()=0; virtual void f1()=0; virtual void f2()=0; virtual void f3()=0; virtual void f4()=0; virtual void f5()=0; virtual void f6()=0; virtual void f7()=0; virtual void f8()=0; virtual void f9()=0; virtual void f10()=0; virtual void f11()=0; virtual void f12()=0; virtual Vec2f getVec(s16*)=0;
};
class Obj { public:
 virtual void s0()=0; virtual void s1()=0; virtual void s2()=0; virtual void s3()=0; virtual void s4()=0; virtual void s5()=0; virtual void s6()=0; virtual void s7()=0; virtual void s8()=0; virtual float s9()=0;
};
struct Enumeration { char pad[0xc]; Obj* m_obj; char pad2[0x6c]; KineticModule* m_kinetic; };
struct Accesser { char pad[0xd8]; const Enumeration* m_enumerationStart; };
extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int,Accesser*,int,Vec2f*,Vec3f*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, unsigned long, unsigned long);
}
extern "C" void fn_27_162D14(int a1,int a2,Vec2f* vec2,Accesser* accesser) {
 Vec2f tempA, tempB;
 s16 val=2;
 Vec2f result=accesser->m_enumerationStart->m_kinetic->getVec(&val);
 Vec2f v2;
 Vec2f sum;
 sum.m_x=vec2->m_x+result.m_x; sum.m_y=vec2->m_y+result.m_y;
 tempB=sum;
 tempA=sum;
 float f31 = accesser->m_enumerationStart->m_obj->s9();
 float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xBBD, 0);
 float f3 = f31 * c;
 if (tempA.m_x * f31 >= lbl_27_rodata_1FC0) f3 -= tempA.m_x;
 Vec3f v3={lbl_27_rodata_1FC0,lbl_27_rodata_1FC0,lbl_27_rodata_1FC0};
 v2.m_x=tempA.m_x+f3; v2.m_y=lbl_27_rodata_1FC0;
 fn_27_89D08(3,accesser,0x12,&v2,&v3);
}
