#include <so/so_value_accesser.h>
#include <so/damage/so_damage.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_8B8[];
extern "C" void fn_8003DC64(Vec2f*, float, Vec2f*);
class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual void fn_27_FF68();
    virtual void fn_27_FFAC(int, soModuleAccesser*, soDamageLog*, float, float);
};
extern "C" void fn_27_6316C(Class_C80* self, soModuleAccesser* accesser, soDamageLog* log, float angle, float reaction) {
    const unsigned long values = (unsigned long)lbl_27_rodata_8B8;
    Vec2f out;
    Vec2f in(reaction, *(const float*)(values + 0));
    fn_8003DC64(&in, *(const float*)(values + 32) * angle, &out);
    reaction /= soValueAccesser::getConstantFloat(accesser, 0x7DA, 0);
    float frame = reaction * soValueAccesser::getConstantFloat(accesser, 0x7D2, 0);
    log->m_height = -1;
    log->m_level = (soDamage::Level)4;
    log->m_speed.m_x = *(const float*)(values + 0);
    log->m_speed.m_y = *(const float*)(values + 0);
    log->m_angle = *(const float*)(values + 0);
    log->m_lr = *(const float*)(values + 12);
    log->m_hitStopFrame = 0;
    log->m_attribute = (soCollisionAttackData::Attribute)0;
    log->m_damageAdd = *(const float*)(values + 0);
    log->m_attackerTaskId = -1;
    log->m_attackerTeamNo = -1;
    log->m_hitStopDelay = *(const float*)(values + 12);
    log->m_isDamageAir = false;
    ((unsigned char*)log)[0x45] &= ~0x3E;
    log->m_reaction = reaction;
    log->m_frame = frame;
    Vec2f zero(*(const float*)(values + 0), *(const float*)(values + 0));
    log->m_speed = out;
    self->fn_27_FFAC(5, accesser, log, frame, zero.m_y);
}
