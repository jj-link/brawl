#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct soCollisionAttackData {
    int m_power;
    Vec3f m_offsetPos;
    float m_size;
    int m_vector;
    int m_reactionEffect;
    int m_reactionFix;
    int m_reactionAdd;
    float m_slipChance;
    float m_hitStopFrame;
    float m_hitStopDelay;
    unsigned int m_nodeIndex : 9;
    unsigned int m_targetCategory : 10;
    unsigned int m_targetSituation : 3;
    unsigned int m_targetLr : 1;
    unsigned int m_targetPart : 4;
    unsigned int m_attribute : 5;
    unsigned int m_soundLevel : 2;
    unsigned int m_soundAttribute : 5;
    unsigned int m_isClankable : 1;
    unsigned int m_unk2 : 1;
    unsigned int m_unk3 : 1;
    unsigned int m_isShieldable : 1;
    unsigned int m_isReflectable : 1;
    unsigned int m_isAbsorbable : 1;
    unsigned int m_subShield : 9;
    unsigned int m_pad1 : 10;
    unsigned int m_serialHitFrame : 16;
    unsigned int m_isDirect : 1;
    unsigned int m_isInvalidInvincible : 1;
    unsigned int m_isInvalidXlu : 1;
    unsigned int m_lrCheck : 3;
    unsigned int m_isCatch : 1;
    unsigned int m_noTeam : 1;
    unsigned int m_noHitStop : 1;
    unsigned int m_noEffect : 1;
    unsigned int m_noTransaction : 1;
    unsigned int m_region : 5;
    unsigned int m_shapeType : 1;
    unsigned int m_pad2 : 31;
};

extern "C" void setAttackGimmickDetails__10grYakumonoFP21soCollisionAttackDataffffiP5Vec3fiiiiUlUlUlbUlQ221soCollisionAttackData9AttributeQ221soCollisionAttackData10SoundLevelQ221soCollisionAttackData14SoundAttributebbbbbbUlUlbbbQ221soCollisionAttackData7LrCheckbbbbbQ221soCollisionAttackData6Regionb(
    void* self,
    soCollisionAttackData* attackData,
    float size, float tripRate, float hitstopMultiplier, float sdiMultiplier,
    int power, Vec3f* offsetPos,
    int vector, int reactionEffect, int reactionFix, int reactionAdd,
    unsigned long nodeIndex, unsigned long collisionCategoryMask,
    unsigned long collisionSituationMask, int unk1, unsigned long collisionPartMask,
    int attribute, int soundLevel, int soundAttr,
    int isClankable, int unk2, int unk3, int isShieldable, int isReflectable, int isAbsorbable,
    unsigned long addedShieldDamage, unsigned long detectionRate,
    int unk5, int ignoreInvincibility, int ignoreIntangibility,
    int lrCheck, int unk6, int unk7, int disableHitstop, int disableHitGfx, int disableFlinch,
    int region, int isShapeCapsule)
{
    if (attackData) {
        attackData->m_power = power;
        attackData->m_offsetPos = *offsetPos;
        attackData->m_size = size;
        attackData->m_vector = vector;
        attackData->m_reactionEffect = reactionEffect;
        attackData->m_reactionFix = reactionFix;
        attackData->m_reactionAdd = reactionAdd;
        attackData->m_slipChance = tripRate;
        attackData->m_hitStopFrame = hitstopMultiplier;
        attackData->m_hitStopDelay = sdiMultiplier;
        attackData->m_nodeIndex = nodeIndex;
        attackData->m_targetCategory = collisionCategoryMask;
        attackData->m_targetSituation = collisionSituationMask;
        attackData->m_targetLr = unk1;
        attackData->m_targetPart = collisionPartMask;
        attackData->m_attribute = attribute;
        attackData->m_soundLevel = soundLevel;
        attackData->m_soundAttribute = soundAttr;
        attackData->m_isClankable = isClankable;
        attackData->m_unk2 = unk2;
        attackData->m_unk3 = unk3;
        attackData->m_isShieldable = isShieldable;
        attackData->m_isReflectable = isReflectable;
        attackData->m_isAbsorbable = isAbsorbable;
        attackData->m_subShield = addedShieldDamage;
        attackData->m_serialHitFrame = detectionRate;
        attackData->m_isDirect = unk5;
        attackData->m_isInvalidInvincible = ignoreInvincibility;
        attackData->m_isInvalidXlu = ignoreIntangibility;
        attackData->m_lrCheck = lrCheck;
        attackData->m_isCatch = unk6;
        attackData->m_noTeam = unk7;
        attackData->m_noHitStop = disableHitstop;
        attackData->m_noEffect = disableHitGfx;
        attackData->m_noTransaction = disableFlinch;
        attackData->m_region = region;
        attackData->m_shapeType = isShapeCapsule;
    }
}
