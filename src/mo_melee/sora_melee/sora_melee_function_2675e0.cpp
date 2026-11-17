#include <types.h>
#include <gr/gr_gimmick.h>

#pragma force_active on

extern const float lbl_27_rodata_42CC;
extern const float lbl_27_rodata_42E4;

struct AttackView {
    int power;
    Vec3f offset;
    float size;
    int vector, effect, fix, add;
    float slip, stop, delay;
    unsigned int node : 9;
    unsigned int category : 10;
    unsigned int situation : 3;
    unsigned int targetLr : 1;
    unsigned int part : 4;
    unsigned int attribute : 5;
    unsigned int soundLevel : 2;
    unsigned int soundAttribute : 5;
    unsigned int setOff : 1;
    unsigned int noThru : 1;
    unsigned int noScale : 1;
    unsigned int shield : 1;
    unsigned int reflect : 1;
    unsigned int absorb : 1;
    unsigned int subShield : 9;
    unsigned int pad : 10;
    unsigned int serial : 16;
    unsigned int direct : 1;
    unsigned int invincible : 1;
    unsigned int xlu : 1;
    unsigned int lr : 3;
    unsigned int isCatch : 1;
    unsigned int noTeam : 1;
    unsigned int noStop : 1;
    unsigned int noEffect : 1;
    unsigned int noTransaction : 1;
    unsigned int region : 5;
    unsigned int shape : 1;
    unsigned int pad2 : 31;
};

extern "C" void setSoCollisionAttackData__10grYakumonoFP21soCollisionAttackDataPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
    void* self, soCollisionAttackData* data, grGimmick::AttackData* s, grGimmick::AttackDetails* x)
{
    AttackView* d = (AttackView*)data;
    d->node = s->m_nodeIndex;
    d->power = s->m_power;
    d->vector = s->m_vector;
    d->effect = s->m_reactionEffect;
    d->fix = s->m_reactionFix;
    d->add = s->m_reactionAdd;
    d->size = s->m_size;
    d->offset = s->m_offsetPos;
    d->noScale = s->m_noScale;
    d->attribute = s->m_attribute;
    d->setOff = s->m_isSetOffOn;
    d->noThru = s->m_noSetOffThru;
    d->soundLevel = s->m_soundLevel;
    d->soundAttribute = s->m_soundAttribute;
    d->lr = 0;
    d->shape = *((u8*)s + 0x49);
    d->subShield = 1;
    d->situation = 0;
    d->situation |= (s->m_targetSituationAir ? 2 : 0);
    d->situation = (d->situation & 2) | (s->m_targetSituationGround != 0);
    d->direct = 0;
    d->category = 1023;
    d->targetLr = 0;
    d->part = 15;
    d->shield = 1;
    d->reflect = 0;
    d->absorb = 0;
    d->serial = s->m_serialHitFrame;
    d->slip = lbl_27_rodata_42CC;
    d->stop = lbl_27_rodata_42E4;
    d->delay = lbl_27_rodata_42E4;
    d->invincible = 0;
    d->xlu = 0;
    d->isCatch = 0;
    d->noTeam = 0;
    d->noStop = 0;
    d->noEffect = 0;
    d->noTransaction = 0;
    d->region = 0;
    if (x) {
        d->category = x->m_targetCategory;
        d->situation |= (x->m_targetSituationODD ? 4 : 0);
        d->lr = x->m_lrCheck;
        d->stop = x->m_hitStopFrame;
    }
}
