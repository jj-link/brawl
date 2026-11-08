#include <st/st_melee.h>
#include <gr/gr_madein.h>
#include <gr/gr_tengan_event.h>
#include <mt/mt_prng.h>
#include <nw4r/math/math_arithmetic.h>
#include <revolution/OS/OSFastCast.h>

#pragma force_active on
#pragma fp_contract off

extern "C" {
extern const float lbl_60_rodata_0[];
extern const char lbl_60_data_464[];
float fn_801622C4(float);
float fn_8016232C(float);
}

#define EVENT ((grTenganEvent*)(b + 0xd88))
#define POS ((Vec3f*)(b + 0xebc))
#define ROT ((Vec3f*)(b + 0xecc))
#define TIMER (*(float*)(b + 0xed8))

inline float clampValue(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" int fn_60_4670(stMelee* self, float delta) {
    const float* rd = lbl_60_rodata_0;
    u8* b = (u8*)self;
    Vec3f node;
    Vec3f scale1;
    Vec3f scale2;

    switch (EVENT->getPhase()) {
    case 0: {
        b[0xeb8] = 0;
        b[0xeb9] = 0;
        b[0xeba] = 0;
        EVENT->setPhase(EVENT->getPhase() + 1);

        *POS = *(Vec3f*)(b + 0xe34);
        POS->m_y += rd[0xc4 / 4];

        u32 random = randi(8);
        if (random >= 7)
            random = 7;
        b[0xec8] = random + 3;
        ROT->m_x = rd[0];
        ROT->m_y = rd[0];
        ROT->m_z = rd[0];
        TIMER = rd[0];
        break;
    }
    }

    float elapsed = TIMER + delta;
    float ratio = elapsed / rd[0x40 / 4];
    TIMER = elapsed;
    if (ratio > rd[0x24 / 4]) {
        TIMER = elapsed - rd[0x40 / 4];
        ratio -= rd[0x24 / 4];
    }

    float t = clampValue(ratio, rd[0], rd[0x24 / 4]);

    u16 angle1 = (u16)(rd[0xc8 / 4] * t);
    ROT->m_x = rd[0x20 / 4] +
        rd[0x1c / 4] * fn_801622C4(rd[0xcc / 4] * __OSu16tof32(&angle1));
    u16 angle2 = (u16)(rd[0xc8 / 4] * t);
    ROT->m_y = rd[0x4c / 4] *
        fn_8016232C(rd[0xcc / 4] * __OSu16tof32(&angle2));
    u16 angle3 = (u16)(rd[0xc8 / 4] * t);
    ROT->m_z = rd[0xd0 / 4] *
        fn_8016232C(rd[0xcc / 4] * __OSu16tof32(&angle3));

    ((grMadein*)self->getGround(0x21))->setRot(ROT);

    switch (b[0xeb9]) {
    case 0:
        if (b[0xeb8] >= 2) {
            scale1.m_x = rd[0x24 / 4];
            scale1.m_y = rd[0x24 / 4];
            scale1.m_z = rd[0x24 / 4];
            ((grMadein*)self->getGround(0x21))->setPos(POS);
            ((grMadein*)self->getGround(0x21))->setScale(&scale1);
            ((grMadein*)self->getGround(0x21))->setMotion(0);
            ((grMadein*)self->getGround(0x21))->startEntity();
            ++b[0xeb9];
        }
        break;
    case 1:
        if (((grMadein*)self->getGround(0x21))->isEndEntity()) {
            ((grMadein*)self->getGround(0x21))->setMotion(1);
            ((grMadein*)self->getGround(0x21))->startEntityAutoLoop();
            ++b[0xeb9];
        }
        break;
    case 2:
        if (b[0xeba] == 2) {
            ((grMadein*)self->getGround(0x21))->setMotion(2);
            ((grMadein*)self->getGround(0x21))->startEntity();
            ++b[0xeb9];
        }
        break;
    case 3:
        if (((grMadein*)self->getGround(0x21))->isEndEntity()) {
            ((grMadein*)self->getGround(0x21))->endEntity();
            ++b[0xeb9];
        }
        break;
    }

    switch (b[0xeba]) {
    case 0:
        if (b[0xeb9] >= 2) {
            scale2.m_x = rd[0xd4 / 4];
            scale2.m_y = rd[0xd4 / 4];
            scale2.m_z = rd[0xd4 / 4];
            ROT->m_y = rd[0xd8 / 4] +
                rd[0x94 / 4] * (rd[0x2c / 4] * randf());
            ((grMadein*)self->getGround(0x22))->setScale(&scale2);
            ((grMadein*)self->getGround(0x22))->setRot(ROT);
            ((grMadein*)self->getGround(0x22))->setPos(POS);
            ((grMadein*)self->getGround(0x22))->setMotion(0);
            ((grMadein*)self->getGround(0x22))->startEntity();
            ((grMadein*)self->getGround(0x23))->setRot(ROT);
            ((grMadein*)self->getGround(0x23))->setPos(POS);
            ((grMadein*)self->getGround(0x23))->setMotion(0);
            ((grMadein*)self->getGround(0x23))->startEntity();
            ((grMadein*)self->getGround(0x24))->setRot(ROT);
            self->playSeBasic((SndID)0x1c63, rd[0]);
            ++b[0xeba];
        }
        break;
    case 1: {
        self->getGround(0x23)->getNodePosition(&node, 0, lbl_60_data_464);
        ((grMadein*)self->getGround(0x22))->setPos(&node);
        node.m_x -= rd[0xdc / 4];
        node.m_y -= rd[0x1c / 4];
        node.m_z += rd[0x1c / 4];
        ((grMadein*)self->getGround(0x24))->setPos(&node);
        ((grMadein*)self->getGround(0x24))->startEntity();
        if (((grMadein*)self->getGround(0x23))->isEndEntity()) {
            ((grMadein*)self->getGround(0x23))->endEntity();
            ((grMadein*)self->getGround(0x22))->endEntity();
            ((grMadein*)self->getGround(0x24))->endEntity();
            if (b[0xec8] == 0) {
                ++b[0xeba];
            } else {
                --b[0xec8];
                b[0xeba] = 0;
            }
        }
        break;
    }
    }

    switch (b[0xeb8]) {
    case 0:
        if (((grMadein*)self->getGround(0x13))->isEndEntity()) {
            ((grMadein*)self->getGround(0x13))->setMotion(6);
            ((grMadein*)self->getGround(0x13))->startEntity();
            ++b[0xeb8];
            self->playSeBasic((SndID)0x1c62, rd[0]);
        }
        break;
    case 1:
        if (((grMadein*)self->getGround(0x13))->isEndEntity()) {
            ((grMadein*)self->getGround(0x13))->setMotion(7);
            ((grMadein*)self->getGround(0x13))->startEntityAutoLoop();
            self->zoomOutCamera(rd[0x44 / 4], rd[0xbc / 4]);
            ++b[0xeb8];
        }
        break;
    case 2:
        if (b[0xeba] == 2 && b[0xeb9] == 4) {
            ((grMadein*)self->getGround(0x13))->setMotion(8);
            ((grMadein*)self->getGround(0x13))->startEntity();
            ++b[0xeb8];
            self->zoomInCamera();
        }
        break;
    case 3:
        if (((grMadein*)self->getGround(0x13))->isEndEntity()) {
            EVENT->end();
            return 1;
        }
        break;
    }
    return 0;
}
