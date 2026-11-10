#include <ft/ft_common_data_accesser.h>
#include <types.h>
#pragma force_active on
extern "C" { extern const float lbl_27_rodata_264C; extern ftCommonDataAccesser g_ftCommonDataAccesser; extern void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int); }
class Work { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual float getFloat(int); virtual void setFloat(float,int); };
class Target { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual Vec3f getVec3f(); virtual void setVec3f(const Vec3f&); };
struct P { char pad0[0xc]; Target* target; char pad1[0x54]; Work* work; };
struct Self { char pad[0xd8]; P* p; };
extern "C" int fn_27_19075C(Self* self) {
 Vec3f out;
 P* p=self->p;
 Work* work=p->work;
 Target* target=p->target;
 void* data=getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser,9);
 float off=*(float*)((char*)(*(void**)((char*)data+0x90))+0xc);
 unsigned int result=0;
 float sum=work->getFloat(0x21000004);
 sum+=off;
 work->setFloat(sum,0x21000004);
 Vec3f v=target->getVec3f();
 out.m_x=v.m_x;
 out.m_z=v.m_z;
 out.m_y=v.m_y+sum;
 if(out.m_y<=lbl_27_rodata_264C) { out.m_y=lbl_27_rodata_264C; result=1; }
 target->setVec3f(out);
 return result;
}
