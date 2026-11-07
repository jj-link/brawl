#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void fn_123_6E08(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual int slot14(bool, bool); virtual void slot15(); virtual void slot16(); virtual void slot17(bool, int, bool);
};
class SituationView { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int slot3(); };
extern "C" {
float fn_123_FBC0(void*, soModuleAccesser*);
extern const float lbl_123_rodata_28;
extern const float lbl_123_rodata_2C;
}
extern "C" void fn_123_F9FC(void* self, soModuleAccesser* accesser) {
    if (reinterpret_cast<Object_vptr_0*>(accesser->m_enumerationStart->m_collisionAttackModule)->slot14(false, false)) {
        float base = soValueAccesser::getConstantFloat(accesser, 0xfbe, 0);
        float ratio = fn_123_FBC0(self, accesser) - base;
        if (lbl_123_rodata_28 != ratio) {
            if (!reinterpret_cast<SituationView*>(accesser->m_enumerationStart->m_situationModule)->slot3()) {
                float low = soValueAccesser::getConstantFloat(accesser, 0xfbe, 0);
                ratio /= soValueAccesser::getConstantFloat(accesser, 0xfba, 0) - low;
            } else {
                float low = soValueAccesser::getConstantFloat(accesser, 0xfbe, 0);
                ratio /= soValueAccesser::getConstantFloat(accesser, 0xfbb, 0) - low;
            }
        }
        if (ratio > lbl_123_rodata_2C) ratio = lbl_123_rodata_2C;
        else if (ratio < lbl_123_rodata_28) ratio = lbl_123_rodata_28;
        float low = soValueAccesser::getConstantFloat(accesser, 0xfc0, 0);
        ratio *= soValueAccesser::getConstantFloat(accesser, 0xfc1, 0) - low;
        ratio += soValueAccesser::getConstantFloat(accesser, 0xfc0, 0);
        reinterpret_cast<Object_vptr_0*>(accesser->m_enumerationStart->m_collisionAttackModule)->slot17(false, (int)ratio, false);
    }
}