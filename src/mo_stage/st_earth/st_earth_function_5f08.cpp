#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on
struct Data { char pad[0x7c]; float a,b,c; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
#define V(n) virtual void n();
V(processDefault) V(processBegin) V(processAnim) V(processUpdate)
V(processPreMapCorrection) V(processMapCorrection) V(processFixPosition) V(processPreCollision)
V(processCollision) V(processCatch) V(processHit) V(processCamera) V(processFixCamera)
V(processEffect) V(processGameProc) V(processEnd) V(renderPre) V(renderOpa) V(renderXlu)
V(processDebug) V(renderDebug) V(init) V(fn_66_5A34) V(fn_66_5A9C) V(loadGroundData)
V(bindData) V(setupMelee) V(setVisibility) V(setVisibilityByClipping) V(setVisibilityAttachedEffect)
V(receiveCollMsg) V(fn_66_6498) V(receiveCollMsg_Heading) V(receiveCollMsg_Wall)
V(receiveCollMsg_Attack) V(unloadData) V(fn_66_2D00) V(startup) V(setNode) V(fn_66_6BC)
virtual Data* fn_66_2CF8();
V(fn_66_2CF4) V(fn_66_2BF4) V(fn_66_2CEC) V(fn_66_2CE0) V(fn_66_2CD0)
V(fn_66_BBC) V(getNodeIndex)
virtual void getNodePosition(Vec3f*, unsigned long, unsigned long);
#undef V
char pad40[0x80];
unsigned long node1, node2;
char padc8[0x91];
unsigned char flag, state, sound;
char pad15c[0xc];
float limit, speed, damping, reset, velocity, timer;
char pad180[4];
Vec3f* pos;
char pad188[0x10];
snd3DGenerator generator;
};
extern "C" const float lbl_66_rodata_138;
extern "C" void fn_66_5F08(Ground* self, float delta) {
    Data* data = self->fn_66_2CF8();
    if (data) {
        float old = self->timer;
        self->timer = old - delta;
        if (self->timer < lbl_66_rodata_138)
            self->timer = lbl_66_rodata_138;
        if (lbl_66_rodata_138 == self->timer) {
            if (lbl_66_rodata_138 != old) {
                self->speed = data->a;
                self->damping = data->c;
                self->sound = 1;
                Vec3f position;
                self->getNodePosition(&position, self->node1, self->node2);
                self->generator.setPos(&position);
                self->generator.playSE((SndID)0x1cd5, 0, 0, -1);
            }
            switch (self->state) {
            case 0:
                if (self->pos->m_y >= self->limit * data->b)
                    self->state = 1;
                else
                    self->velocity += data->a * delta;
                break;
            case 1: {
                self->velocity = self->velocity * (self->damping * delta) - self->speed * delta;
                if (self->pos->m_y <= lbl_66_rodata_138) {
                    self->state = 2;
                    self->speed = self->speed * self->damping;
                }
                break;
            }
            case 2: {
                self->velocity = self->velocity * (self->damping * delta) + self->speed * delta;
                if (self->pos->m_y >= lbl_66_rodata_138) {
                    self->state = 1;
                    self->speed = self->speed * self->damping;
                    if (self->sound == 1) {
                        Vec3f position;
                        self->getNodePosition(&position, self->node1, self->node2);
                        self->generator.setPos(&position);
                        self->generator.playSE((SndID)0x1cd6, 0, 0, -1);
                        self->sound = 0;
                    }
                }
                break;
            }
            }
            self->pos->m_y += self->velocity;
            self->reset = lbl_66_rodata_138;
            self->flag = 0;
        }
    }
}
