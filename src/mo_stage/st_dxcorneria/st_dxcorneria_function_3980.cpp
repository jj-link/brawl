#include <types.h>
#include <gr/gr_madein.h>
#include <so/collision/so_collision_attack_part.h>
#pragma force_active on

extern Vec3f lbl_82_bss_24;
extern const f32 lbl_82_rodata_48;
extern const f32 lbl_82_rodata_AC;

static inline void configureAttack(soCollisionAttackData* d, Vec3f* pos, f32 size) {
    d->m_nodeIndex = 0;
    d->m_power = 30;
    d->m_vector = 10;
    d->m_reactionEffect = 80;
    d->m_reactionFix = 0;
    d->m_reactionAdd = 70;
    d->m_size = size;
    d->m_offsetPos = *pos;
    d->m_attribute = soCollisionAttackData::Attribute_Electric;
    d->m_targetSituation = (soCollision::SituationMask)7;
    d->m_targetCategory = (soCollision::CategoryMask)1023;

    *(u32*)((u8*)d + 0x34) |= 0x01000000;
    *(u32*)((u8*)d + 0x34) &= ~0x00800000UL;
    *(u32*)((u8*)d + 0x38) &= ~0x8000UL;
    d->m_soundLevel = soCollisionAttackData::Sound_Level_Large;
    *(u32*)((u8*)d + 0x30) &= ~0x200UL;
    d->m_soundAttribute = soCollisionAttackData::Sound_Attribute_Fire;
    d->m_targetPart = (soCollision::PartMask)15;
    d->m_serialHitFrame = 16;
    *(u32*)((u8*)d + 0x34) &= ~0x00400000UL;
    *(u32*)((u8*)d + 0x38) &= ~0x7f00UL;
    *(u32*)((u8*)d + 0x34) |= 0x00380000;
    *(u32*)((u8*)d + 0x38) |= 0x80;
    *(u32*)((u8*)d + 0x38) &= ~0x60UL;
    *(u32*)((u8*)d + 0x3c) |= 0x80000000UL;
}

extern "C" void fn_82_3980(void* unused, grMadein* arg) {
    Vec3f* pos = &lbl_82_bss_24;
    grMadein* self = arg;

    self->setAttack(lbl_82_rodata_48, pos);
    *(f32*)((u8*)self + 0x1a8) = lbl_82_rodata_AC * pos->m_x;
    *((u8*)self + 0x1ae) = 0;

    soCollisionAttackData* d = self->getOverwriteAttackData();
    configureAttack(d, pos, lbl_82_rodata_48);
    self->setAttackPreset(grMadein::Attack_Overwrite);
}
