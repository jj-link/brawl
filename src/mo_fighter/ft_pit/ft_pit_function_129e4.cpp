#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on
extern "C" { void fn_112_12974(void*, const void*); float randf__Fv(); extern const float lbl_112_rodata_50; extern const float lbl_112_rodata_60; }
struct CtrlFlags { unsigned char byteFlag; short count; };
class PitSubmodule { public: virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(short*); };
class PitData { public: virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual float getValue(int); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual soParamAccesser* getContainer(); };
static inline unsigned char* at(void* p,int n){return (unsigned char*)p+n;}
static inline void* ptr(void* p,int n){return *(void**)at(p,n);}
extern "C" void fn_112_129E4(void*, unsigned char* self,unsigned char* fighter) {
CtrlFlags flags; flags.count=1;
PitSubmodule* sub=(PitSubmodule*)ptr(ptr(fighter,0xD8),0x7C); sub->v14(&flags.count);
sub=(PitSubmodule*)ptr(ptr(fighter,0xD8),0x7C); sub->v13();
PitData* data=(PitData*)ptr(ptr(fighter,0xD8),0x64); soParamAccesser* params=data->getContainer();
PitData* dataAgain=(PitData*)ptr(ptr(fighter,0xD8),0x64);
float f30=params->getParamFloat((soModuleAccesser*)fighter,0xFA4,0);
Vec3f p;
float v=dataAgain->getValue(0x11000001);
p.m_x=v*f30;
p.m_y=params->getParamFloat((soModuleAccesser*)fighter,0xFA5,0);
float r=randf__Fv();
float f31=params->getParamFloat((soModuleAccesser*)fighter,0xFA9,0);
float f1=params->getParamFloat((soModuleAccesser*)fighter,0xFA8,0);
p.m_z=f1+r*(f31-f1);
flags.byteFlag=0; fn_112_12974(self+0x18,&p);
float n6=-params->getParamFloat((soModuleAccesser*)fighter,0xFA6,0);
Vec3f q; q.m_x=lbl_112_rodata_50; q.m_y=n6; q.m_z=lbl_112_rodata_50; fn_112_12974(self+0x24,&q);
float n7=-params->getParamFloat((soModuleAccesser*)fighter,0xFA7,0);
Vec3f s; s.m_x=lbl_112_rodata_60; s.m_y=n7; s.m_z=lbl_112_rodata_60; fn_112_12974(self+0x48,&s); self[0x15]|=0x80;
}