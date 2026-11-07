#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/so_photo_call_back.h>
#include <mt/mt_prng.h>
#pragma force_active on

class VisibilitySigned {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void setStatusDefault(unsigned int, int, bool);
};

extern "C" {
extern const float lbl_103_rodata_20, lbl_103_rodata_24;
extern char lbl_103_data_654[], lbl_103_data_22A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_103_1058C(void*, soModuleAccesser*);
Vec3f* fn_103_9594(Vec3f*, float, float, float);
}

extern "C" void fn_103_FE40(void* self, soModuleAccesser* accesser) {
    float low = soValueAccesser::getConstantFloat(accesser, 0xfbe, 0);
    float high = soValueAccesser::getConstantFloat(accesser, 0xfbf, 0);
    float value = low + (high - low) * randf();
    accesser->getWorkManageModule().setFloat(value, 0x21000004);
    accesser->getWorkManageModule().setFloat(soValueAccesser::getConstantFloat(accesser, 0xfbd, 0), 0x21000005);
    low = soValueAccesser::getConstantFloat(accesser, 0xfbe, 0);
    high = soValueAccesser::getConstantFloat(accesser, 0xfbf, 0);
    value = low + (high - low) * randf();
    accesser->getWorkManageModule().setFloat(value, 0x21000006);
    accesser->getWorkManageModule().setInt(soValueAccesser::getConstantInt(accesser, 0x5dc3, 0), 0x20000002);
    fn_103_1058C(self, accesser);
    accesser->getEffectModule().setSyncScale(false);
    Vec3f b, a;
    u32 handle = accesser->getEffectModule().req2D((EfID)0xed000a,
        fn_103_9594(&b, lbl_103_rodata_20, lbl_103_rodata_20, lbl_103_rodata_20),
        fn_103_9594(&a, lbl_103_rodata_20, lbl_103_rodata_20, lbl_103_rodata_20),
        lbl_103_rodata_24, 0);
    accesser->getEffectModule().setSyncScale(true);
    accesser->getWorkManageModule().setInt(handle, 0x10000042);
    ((VisibilitySigned*)&accesser->getVisibilityModule())->setStatusDefault(0, -1, true);
    char* object = (char*)__dynamic_cast(accesser->m_stageObject, 0x3c, lbl_103_data_654, lbl_103_data_22A0, 0);
    if (object) ((soPhotoCallBack*)(object + 0x186f0))->addCallback();
}