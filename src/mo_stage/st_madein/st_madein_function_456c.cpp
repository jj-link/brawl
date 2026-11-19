#include <gr/gr_madein.h>
#include <gr/gr_tengan_event.h>
#include <mt/mt_common.h>
#include <nw4r/ut/ut_algorithm.h>
#include <nw4r/math/math_arithmetic.h>
#include <st/st_melee.h>
#include <st/stage.h>
#pragma force_active on

extern "C" {
extern const float lbl_65_rodata_0[];
float randf__Fv();
}

struct MadeinState {
    char pad000[0x284];
    grTenganEvent event;
    char pad330[0xac];
    grTenganEvent otherEvent;
    char pad488[0x368];
    float timer;
    char pad7f4[0x121];
    unsigned char stopped;
    char pad916[2];
    Vec3f pos;
    Vec3f target;
    unsigned char direction;
    unsigned char turning;
    char pad932[2];
    float speed;
    float directionTimer;
    float unusedTimer;
    float distance;
    unsigned int groundId;
    char pad948[0xc];
    unsigned char playerEnabled[4];
    char pad958[0x8f];
    unsigned char playerCount[4];
    char pad9eb[9];
    unsigned char active;
    char pad9f5[3];
    Vec3f effectPos;
};

extern "C" int fn_65_456C(MadeinState* self, float delta) {
    const float* rd = lbl_65_rodata_0;
    Stage* stage = (Stage*)self;
    stMelee* melee = (stMelee*)self;
    Vec3f rot;
    Vec3f playerPos;

    switch (self->event.getPhase()) {
    case 0:
        self->playerEnabled[3] = 1;
        self->playerEnabled[2] = 1;
        self->playerEnabled[1] = 1;
        self->playerEnabled[0] = 1;
        ((grMadein*)stage->getGround(0x37))->setMotion(1);
        ((grMadein*)stage->getGround(0x37))->startEntityAutoLoop();
        self->stopped = 0;
        self->directionTimer = rd[0];
        self->unusedTimer = rd[0];
        if (rd[0x10 / 4] - rd[0x6c / 4] * randf__Fv() < rd[0])
            self->direction = 1;
        else
            self->direction = 0;
        self->turning = 0;
        self->speed = rd[0];
        ((grMadein*)stage->getGround(0x33))->setMotion(0);
        ((grMadein*)stage->getGround(0x33))->startEntityAutoLoop();
        ((grMadein*)stage->getGround(self->groundId))->setMotion(0);
        ((grMadein*)stage->getGround(self->groundId))->startEntityAutoLoop();
        self->event.setPhase(1);
        self->playerCount[0] = 0;
        self->playerCount[1] = 0;
        self->playerCount[2] = 0;
        self->playerCount[3] = 0;
        self->active = 1;
        self->effectPos.m_x = self->target.m_x;
        self->effectPos.m_y = self->target.m_y;
        break;

    case 1:
        if (!self->otherEvent.isEvent()) {
            self->event.end();
            ((grMadein*)stage->getGround(0x5d))->endEntity();
            ((grMadein*)stage->getGround(0x5e))->endEntity();
            ((grMadein*)stage->getGround(0x5f))->endEntity();
            ((grMadein*)stage->getGround(0x60))->endEntity();
            ((grMadein*)stage->getGround(0x37))->endEntity();
            ((grMadein*)stage->getGround(0x33))->endEntity();
            ((grMadein*)stage->getGround(self->groundId))->endEntity();
            self->active = 0;
            return 1;
        }
        if ((float)(double)nw4r::ut::Abs(self->pos.m_x - self->target.m_x) > self->distance) {
            ((grMadein*)stage->getGround(0x37))->setMotion(2);
            ((grMadein*)stage->getGround(0x37))->startEntity();
            melee->playSeBasic((SndID)0x1cab, rd[0]);
            self->event.setPhase(2);
            self->stopped = 1;
            self->timer = rd[0];
            self->active = 0;
        }
        break;

    case 2:
        self->timer += rd[0x84 / 4] * delta;
        if (self->timer > rd[0x10 / 4] &&
            ((grMadein*)stage->getGround(0x37))->isEndEntity() == 1 &&
            !self->otherEvent.isEvent()) {
            self->event.end();
            ((grMadein*)stage->getGround(0x5d))->endEntity();
            ((grMadein*)stage->getGround(0x5e))->endEntity();
            ((grMadein*)stage->getGround(0x5f))->endEntity();
            ((grMadein*)stage->getGround(0x60))->endEntity();
            ((grMadein*)stage->getGround(0x37))->endEntity();
            ((grMadein*)stage->getGround(0x33))->endEntity();
            ((grMadein*)stage->getGround(self->groundId))->endEntity();
            self->active = 0;
            return 1;
        }
        break;
    }

    if (!self->stopped) {
        if (!self->turning)
            self->directionTimer -= delta;
        if (self->directionTimer < rd[0])
            self->directionTimer = rd[0];
        if (self->pos.m_x < rd[0x124 / 4] && !self->direction)
            self->directionTimer = rd[0];
        if (self->pos.m_x > rd[0x70 / 4] && self->direction == 1)
            self->directionTimer = rd[0];

        if (rd[0] == self->directionTimer) {
            self->directionTimer =
                rd[0x128 / 4] +
                (rd[0x12c / 4] - rd[0x128 / 4] * randf__Fv());
            if (!self->direction) {
                self->direction = 1;
                rot.m_x = rd[0];
                rot.m_y = rd[0];
                rot.m_z = rd[0];
            } else {
                self->direction = 0;
                rot.m_x = rd[0];
                rot.m_y = rd[0xc4 / 4];
                rot.m_z = rd[0];
            }
            ((grMadein*)stage->getGround(0x37))->setRot(&rot);
        }

        if (!self->direction) {
            if (self->speed > rd[0x130 / 4])
                self->speed -= rd[0x120 / 4] * (rd[0x88 / 4] * delta);
            if (self->speed > rd[0])
                self->turning = 1;
            else
                self->turning = 0;
        } else {
            if (self->speed < rd[0x134 / 4])
                self->speed += rd[0x120 / 4] * (rd[0x88 / 4] * delta);
            if (self->speed < rd[0])
                self->turning = 1;
            else
                self->turning = 0;
        }

        self->pos.m_x += self->speed * delta;
        ((grMadein*)stage->getGround(0x37))->setPos(&self->pos);
        float differenceX;
        differenceX = self->pos.m_x - self->target.m_x;
        differenceX = (float)(double)nw4r::math::FAbs(differenceX);
        float posX = self->pos.m_x;
        float targetX = self->target.m_x;
        if (differenceX > rd[0x24 / 4]) {
            if (targetX < posX)
                self->target.m_x = targetX + rd[0x138 / 4];
            else
                self->target.m_x = targetX - rd[0x138 / 4];
        }
        ((grMadein*)stage->getGround(self->groundId))->setPos(&self->target);
        self->effectPos.m_x = self->target.m_x;
        self->effectPos.m_y = self->target.m_y;
        self->effectPos.m_z = rd[0x7c / 4];
    }

    float height = rd[0xcc / 4];
    unsigned int show;
    for (int i = 0; i < 4; ++i) {
        if (stMelee::getPlayerPosition(i, &playerPos) == 1) {
            show = 0;
            float difference = self->target.m_x - playerPos.m_x;
            float distance = mtSqrtf(difference * difference);
            float limit = rd[0x7c / 4];
            if (self->groundId != 0x34)
                limit = rd[0xd8 / 4];

            if ((float)(double)nw4r::ut::Abs(distance) > limit) {
                if (self->playerCount[i] >= 2)
                    self->playerEnabled[i] = 0;
                else
                    self->playerCount[i]++;
                show = 1;
            }
            if (playerPos.m_y > height) {
                if (self->playerCount[i] >= 2)
                    self->playerEnabled[i] = 0;
                else
                    self->playerCount[i]++;
                show = 1;
            }
            if (show == 1) {
                int id = i + 0x5d;
                ((grMadein*)stage->getGround(id))->setPos(&playerPos);
                ((grMadein*)stage->getGround(id))->startEntity();
            } else {
                ((grMadein*)stage->getGround(i + 0x5d))->endEntity();
            }
        } else {
            ((grMadein*)stage->getGround(i + 0x5d))->endEntity();
        }
    }
    return 0;
}
