#pragma force_active on

#include <gr/gr_tengan_event.h>
#include <gr/gr_madein.h>
#include <snd/snd_3d_generator.h>
#include <st/st_melee.h>
#include <gf/gf_3d_scene.h>
#include <nw4r/ut/ut_algorithm.h>

struct TenganWork {
    char pad000[0x9c];
    int active;
    char pad0a0[0x164];
    int kind;
    snd3DGenerator sound;
    int groundIndex;
    int direction;
    char pad218[4];
    grTenganEvent event21c;
    grTenganEvent event2c8;
    grTenganEvent event374;
    grTenganEvent event420;
    grTenganEvent event4cc;
    grTenganEvent event578;
    grTenganEvent event624;
    grTenganEvent event6d0;
    grTenganEvent event77c;
    grTenganEvent event828;
    grTenganEvent event8d4;
    grTenganEvent event980;
    grTenganEvent eventa2c;
    grTenganEvent eventad8;
    grTenganEvent eventb84;
    grTenganEvent eventc30;
    grTenganEvent eventcdc;
    grTenganEvent eventd88;
    char padE34[0x20];
    unsigned char pending;
    char padE55[0x4b];
    int soundHandle;
    char padEa4[4];
    unsigned char quakeFlag;
    char padEa9[0x3f];
    int delayedSound;
    float soundTimer;
};

struct SceneFlags {
    unsigned int top : 8;
    unsigned int rest : 24;
};

extern "C" {
extern const float lbl_60_rodata_0[];

void fn_60_4D48(TenganWork*, float);
void fn_60_5154(TenganWork*, float);
void fn_60_551C(TenganWork*, float);

unsigned int fn_60_230C(TenganWork*, float);
unsigned int fn_60_2EB4(TenganWork*, float);
unsigned int fn_60_3158(TenganWork*, float);
unsigned int fn_60_2C64(TenganWork*, float);
unsigned int fn_60_2DB8(TenganWork*, float);
unsigned int fn_60_3E48(TenganWork*, float);
unsigned int fn_60_3B3C(TenganWork*, float);
unsigned int fn_60_40AC(TenganWork*, float);
unsigned int fn_60_34D4(TenganWork*, float);
unsigned int fn_60_420C(TenganWork*, float);
unsigned int fn_60_4454(TenganWork*, float);
unsigned int fn_60_4670(TenganWork*, float);

void cmRemoveQuake__Fi(int);
void cmReqQuake__FiP5Vec3f(int, Vec3f*);

void fn_60_56B4(TenganWork* self, float delta)
{
    const float* rd = lbl_60_rodata_0;
    Vec3f soundPos;
    Vec3f pos;
    Vec3f rot;
    Vec3f quakeSecond;
    Vec3f quakeFirst;
    Vec3f quakeLarge;

    if (self->active == 0)
        return;

    if (self->event21c.isReadyEnd() == true &&
        self->event2c8.isReadyEnd() && !self->pending) {
        switch (self->kind) {
        case 0:
            fn_60_4D48(self, delta);
            break;
        case 1:
            fn_60_5154(self, delta);
            break;
        case 2:
            fn_60_551C(self, delta);
            break;
        }
    }

    if (self->delayedSound != -1) {
        self->soundTimer -= delta;
        if (self->soundTimer < rd[0]) {
            int handle = self->sound.prepareSE((SndID)self->delayedSound, 0);
            if (handle != -1) {
                soundPos.m_x = rd[0];
                soundPos.m_y = rd[0x4c / 4];
                soundPos.m_z = rd[0];
                self->sound.setPos(&soundPos);
                self->sound.startSE(handle, 0);
            }
            self->delayedSound = -1;
        }
    }

    self->event21c.update(delta);
    self->event2c8.update(delta);
    self->event374.update(delta);
    self->eventad8.update(delta);
    self->eventb84.update(delta);
    self->event420.update(delta);
    self->event4cc.update(delta);
    self->event578.update(delta);
    self->event624.update(delta);
    self->event6d0.update(delta);
    self->event77c.update(delta);
    self->event828.update(delta);
    self->event8d4.update(delta);
    self->event980.update(delta);
    self->eventa2c.update(delta);
    self->eventc30.update(delta);
    self->eventcdc.update(delta);
    self->eventd88.update(delta);

    if (self->event420.isEvent() &&
        self->event420.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_230C(self, delta) == 1)
        self->event420.end();

    if (self->event4cc.isEvent() &&
        self->event4cc.m_framesElapsed >= rd[0x40 / 4]) {
        unsigned int finished;
        if (self->event4cc.isReadyEnd() == true) {
            cmRemoveQuake__Fi(1);
            ((stMelee*)self)->stopSeBasic(self->soundHandle, rd[0x30 / 4]);
            self->quakeFlag = 0;
            finished = 1;
        } else {
            if (!self->quakeFlag) {
                quakeFirst.m_x = rd[0];
                quakeFirst.m_y = rd[0];
                quakeFirst.m_z = rd[0];
                cmReqQuake__FiP5Vec3f(1, &quakeFirst);
            } else {
                quakeSecond.m_x = rd[0];
                quakeSecond.m_y = rd[0];
                quakeSecond.m_z = rd[0];
                cmReqQuake__FiP5Vec3f(1, &quakeSecond);
            }
            finished = 0;
        }
        if (finished == 1)
            self->event4cc.end();
    }

    if (self->event578.isEvent() &&
        self->event578.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_2EB4(self, delta) == 1)
        self->event578.end();

    if (self->event624.isEvent() &&
        self->event624.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_3158(self, delta) == 1)
        self->event624.end();

    if (self->event6d0.isEvent() &&
        self->event6d0.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_2C64(self, delta) == 1)
        self->event6d0.end();

    if (self->event77c.isEvent() &&
        self->event77c.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_2DB8(self, delta) == 1)
        self->event77c.end();

    if (self->event828.isEvent() &&
        self->event828.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_3E48(self, delta) == 1)
        self->event828.end();

    if (self->event8d4.isEvent() &&
        self->event8d4.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_3B3C(self, delta) == 1)
        self->event8d4.end();

    if (self->event980.isEvent() &&
        self->event980.m_framesElapsed >= rd[0x40 / 4]) {
        switch (self->event980.getPhase()) {
        case 0: {
            cmRemoveQuake__Fi(1);
            self->event980.setPhase(1);
            ((SceneFlags*)((char*)g_gfSceneRoot + 0x64))->top = 1;
            quakeLarge.m_x = rd[0];
            quakeLarge.m_y = rd[0];
            quakeLarge.m_z = rd[0];
            cmReqQuake__FiP5Vec3f(3, &quakeLarge);
            ((stMelee*)self)->playSeBasic((SndID)0x1c58, rd[0]);
            break;
        }
        case 1:
            if (self->event980.isReadyEnd() == true) {
                cmRemoveQuake__Fi(1);
                unsigned int* flags = (unsigned int*)((char*)g_gfSceneRoot + 0x64);
                *flags &= 0x00ffffff;
                self->event980.end();
                ((stMelee*)self)->playSeBasic((SndID)0x1c59, rd[0]);
            }
            break;
        }
    }

    if (self->eventa2c.isEvent() &&
        self->eventa2c.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_40AC(self, delta) == 1)
        self->eventa2c.end();

    if (self->event21c.isEvent() &&
        self->event21c.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_34D4(self, delta) == 1)
        self->event21c.end();

    if (self->eventc30.isEvent() &&
        self->eventc30.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_420C(self, delta) == 1)
        self->eventc30.end();

    if (self->eventcdc.isEvent() &&
        self->eventcdc.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_4454(self, delta) == 1)
        self->eventcdc.end();

    if (self->eventd88.isEvent() &&
        self->eventd88.m_framesElapsed >= rd[0x40 / 4] &&
        fn_60_4670(self, delta) == 1)
        self->eventd88.end();

    if (self->pending == 1 &&
        !self->eventcdc.isEvent() &&
        !self->eventd88.isEvent() &&
        !self->event828.isEvent()) {
        int index = 0;
        switch (self->kind) {
        case 0:
            index = 3;
            break;
        case 1:
            index = 0x12;
            break;
        case 2:
            index = 0x13;
            break;
        }
        if (((grMadein*)((Stage*)self)->getGround(index))->isEndEntity() == true) {
            ((grMadein*)((Stage*)self)->getGround(index))->setMotion(0);
            ((grMadein*)((Stage*)self)->getGround(index))->startEntityAutoLoop();
            self->pending = 0;
        }
    }

    if (self->eventad8.isReadyEnd() && self->groundIndex != -1) {
        ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->startEntityAutoLoop();
        self->eventad8.end();
        self->eventb84.start();
    }

    if (self->eventb84.isReadyEnd() && self->groundIndex != -1) {
        pos.m_x = rd[0];
        pos.m_y = rd[0];
        pos.m_z = rd[0];
        rot.m_x = rd[0];
        rot.m_y = rd[0];
        rot.m_z = rd[0];

        switch (self->eventb84.getPhase()) {
        case 0:
            if (self->groundIndex == 0x10) {
                if (self->direction == 0)
                    ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->setMotion(2);
                else
                    ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->setMotion(3);
                ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->startEntity();
                self->eventb84.setPhase(self->eventb84.getPhase() + 1);
            } else {
                self->eventb84.setPhase(3);
            }
            break;

        case 1:
            if (((grMadein*)((Stage*)self)->getGround(self->groundIndex))->isEndEntity() == true) {
                if (self->direction == 0)
                    rot.m_y = rd[0x68 / 4];
                else
                    rot.m_y = rd[0];
                ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->setRot(&rot);
                ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->setMotion(1);
                ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->startEntityAutoLoop();
                self->eventb84.setPhase(self->eventb84.getPhase() + 1);
            }
            break;

        case 2:
            pos = ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->getPos();
            if (self->direction == 0)
                pos.m_x -= rd[0x34 / 4];
            else
                pos.m_x += rd[0x34 / 4];
            ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->setPos(&pos);
            if ((float)fabs(pos.m_x) > rd[0x10 / 4])
                self->eventb84.setPhase(self->eventb84.getPhase() + 1);
            break;

        case 3:
            ((grMadein*)((Stage*)self)->getGround(self->groundIndex))->endEntity();
            self->eventb84.end();
            break;
        }
    }
}
}
