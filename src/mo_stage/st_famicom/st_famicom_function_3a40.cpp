#include <gr/ground.h>
#include <mt/mt_vector.h>
#include <orch_helpers.h>
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_LinkList.h>
#include <snd/snd_3d_generator.h>
#include <sr/sr_common.h>
#include <math.h>
#include <new>
#pragma force_active on
class Class_540 {
public:
    virtual void fn_68_22E4();
    virtual int fn_68_2358();
};
class Class_1870 {
public:
    virtual void fn_68_94B0();
    virtual int fn_68_8978();
};
class Class_2428 {
public:
    virtual void fn_68_E3F0();
    virtual int fn_68_D810();
};
struct Node {
    nw4r::ut::LinkListNode link;
    grCollStatus* status;
    u8 state;
};
typedef nw4r::ut::LinkList<Node, 0> CollisionList;
struct Entry {
    Vec3f pos;
    float a, b, c;
    u8 flag;
    char pad[3];
    float timer;
};
struct Particle {
    Vec3f pos;
    char p[13];
    u8 active;
    char q[6];
    float value;
    u8 kind;
    char r[3];
};
struct Output {
    Vec3f pos;
    unsigned id;
    u8 flag;
};
struct Info {
    char pad[40];
    u8 count;
};
class FamicomGround : public Ground {
public:
    virtual void* getStageData();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_68_24C8();
    virtual void fn_68_24C0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_68_24B8();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_68_3414();
    virtual void fn_68_35D8();
    virtual void fn_68_3698();
    virtual void fn_68_380C();
    virtual void fn_68_38C4();
    virtual void fn_68_B30();
    virtual void fn_68_B38();
    virtual void fn_68_B40();
    virtual void fn_68_2FCC();
    virtual void fn_68_3010();
    virtual void fn_68_3018();
    virtual void fn_68_B48();
    virtual void fn_68_B28();
    virtual void fn_68_3038();
    virtual void fn_68_3E2C();
    virtual void fn_68_404C();
    virtual void fn_68_3030();
    virtual void fn_68_3028();
    virtual void fn_68_D58();
    virtual void fn_68_3E88();
    virtual void fn_68_3EC0();
    virtual void fn_68_3F34();
    virtual Node* fn_68_3FB8(CollisionList*, grCollStatus*);
    char pad9c[0xc0];
    Particle* particles;
    Output* output;
    char pad164[4];
    unsigned ids[31];
    snd3DGenerator sound;
    CollisionList list;
    Entry entries[62];
    char pad9b8[6];
    u8 count;
};
extern "C" {
extern const float lbl_68_rodata_20[];
extern int lbl_68_data_8E0;
bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(
    Ground*, grCollStatus*, int*);
void fn_801341D8(grCollStatus*, void*);
void fn_801342C8(grCollStatus*, Vec2f*);
}
inline float clampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
extern "C" void fn_68_3A40(FamicomGround* self, grCollStatus* status) {
    const float* k = lbl_68_rodata_20;
    u8 i;
    u8 count;
    u8 nearest;
    float distance;
    double best[1];
    if (!isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(
            self, status, &lbl_68_data_8E0))
        return;
    if (((int)((*(unsigned*)((char*)status + 8) << 8) & 0xff800000) >> 24) != 2)
        return;
    Vec3f point;
    Class_540* owner = *(Class_540**)((char*)status + 0x60);
    if (owner->fn_68_2358() == 2) {
        float matrix[14];
        fn_801341D8(status, matrix);
        float y = matrix[3];
        point.m_x = matrix[2];
        point.m_y = y;
        point.m_z = k[3];
    } else {
        Vec2f p;
        fn_801342C8(status, &p);
        float y = p.m_y;
        point.m_x = p.m_x;
        point.m_y = y;
        point.m_z = k[3];
    }
    count = self->count;
    nearest = 250;
    best[0] = k[23];
    i = 0;
    Vec3f pos, c, d;
    for (; i != count; ++i) {
        self->getNodePosition(&pos, 0, self->ids[i]);
        Vec3fSub_vb75923(&d, &pos, &point);
        c = d;
        float sum = c.m_z * c.m_z + (c.m_x * c.m_x + c.m_y * c.m_y);
        if ((float)fabs((double)sum) <= k[17])
            distance = k[3];
        else
            distance = sum * rsqrtf(sum);
        if (best[0] > distance) {
            best[0] = distance;
            nearest = i;
        }
    }
    if (nearest == 250)
        return;
    Node* node = self->fn_68_3FB8(&self->list, status);
    if (node) {
        node->state = 2;
        return;
    }
    self->entries[nearest].b = k[22];
    self->entries[nearest].flag = 1;
    self->entries[nearest].timer = k[21];
    self->entries[nearest + 1].b = k[22];
    self->entries[nearest + 1].flag = 1;
    self->entries[nearest + 1].timer = k[21];
    node = (Node*)operator new(sizeof(Node), Heaps::StageInstance);
    if (node) {
        ((int*)node)[0] = 0;
        ((int*)node)[1] = 0;
    }
    if (!node)
        return;
    node->status = status;
    node->state = 2;
    self->list.PushBack(node);
    self->sound.playSE((SndID)0x1ce4, 0, 0, -1);
    self->output->pos = self->entries[nearest].pos;
    self->output->pos.m_x += k[24];
    self->output->id = status->m_taskId;
    self->output->flag = 0;
    Info* info = (Info*)self->getStageData();
    if (info) {
        u8 j;
        u8 n = info->count;
        for (j = 0; j != n; ++j) {
            Particle* p = &self->particles[j];
            if (p->kind != 13 &&
                p->pos.m_x > point.m_x - k[25] &&
                p->pos.m_x < k[25] + point.m_x &&
                p->pos.m_y > point.m_y &&
                p->pos.m_y < k[2] + point.m_y &&
                p->active == 1) {
                float t = (p->pos.m_x - (point.m_x - k[25])) / k[2];
                p->value = k[20] - clampRange(t, k[3], k[20]);
            }
        }
    }
}
