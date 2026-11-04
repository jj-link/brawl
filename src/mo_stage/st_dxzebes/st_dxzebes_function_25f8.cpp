#include <st/st_melee.h>
#include <gr/gr_madein.h>
#include <mt/mt_prng.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" const float lbl_84_rodata_0[];

struct State {
    unsigned char current, next;
    short timer;
    float base, position, velocity, amount;
};

extern "C" void fn_84_25F8(stMelee* self, int a, State* s, int b, int c) {
    const float* k = lbl_84_rodata_0;
    if (s->current != s->next) {
        s->current = s->next;
        switch (s->next) {
        case 0:
            ((grMadein*)self->getGround(a))->setMotion(0);
            self->getGround(a)->setMotionRatio(k[0x28/4]);
            self->getGround(a)->setMotionFrame(k[0x28/4], 0);
            ((grMadein*)self->getGround(a))->startEntity();
            ((grMadein*)self->getGround(b))->setMotion(0);
            ((grMadein*)self->getGround(b))->startEntityAutoLoop();
            ((grMadein*)self->getGround(c))->startEntity();
            s->timer = 0;
            s->position = k[0x28/4];
            s->velocity = k[0x28/4];
            break;
        case 1:
            ((grMadein*)self->getGround(a))->setMotion(1);
            self->getGround(a)->setMotionRatio(k[0xa0/4]);
            self->getGround(a)->setMotionFrame(k[0x28/4], 0);
            ((grMadein*)self->getGround(a))->startEntity();
            ((grMadein*)self->getGround(b))->setMotion(1);
            ((grMadein*)self->getGround(b))->startEntity();
            ((grMadein*)self->getGround(c))->endEntity();
            break;
        case 2:
            s->timer = (short)(int)(k[0xec/4] + k[0xc4/4] * randf());
            break;
        case 3:
            ((grMadein*)self->getGround(a))->setMotion(2);
            self->getGround(a)->setMotionRatio(k[0xa0/4]);
            self->getGround(a)->setMotionFrame(k[0x28/4], 0);
            ((grMadein*)self->getGround(a))->startEntity();
            ((grMadein*)self->getGround(b))->setMotion(2);
            ((grMadein*)self->getGround(b))->startEntity();
            s->amount = k[0x28/4];
            break;
        }
    }
    switch (s->current) {
    case 0: {
        if (s->timer++ > 20) {
            s->amount -= k[0xa0/4];
            s->timer = 0;
            if (s->amount < k[0x28/4]) s->amount = k[0x28/4];
        }
        if (s->position > k[0x1a8/4])
            s->velocity -= k[0x1ac/4];
        else if (s->position < k[0x1b0/4])
            s->velocity += k[0x1ac/4];
        s->velocity *= k[0x138/4];
        if (s->velocity > k[0x74/4]) s->velocity = k[0x74/4];
        else if (s->velocity < k[0x1b4/4]) s->velocity = k[0x1b4/4];
        s->position += s->velocity;
        if (s->position > k[0x88/4]) s->position = k[0x88/4];
        else if (s->position < k[0xe0/4]) s->position = k[0xe0/4];
        if (nw4r::ut::Abs(s->position) < k[0x1a8/4] && nw4r::ut::Abs(s->velocity) < k[0x1a8/4]) {
            s->position = k[0x28/4];
            s->velocity = k[0x28/4];
        }
        Ground* ground = self->getGround(a);
        float* data = *(float**)((char*)ground + 0xd4);
        data[0xac/4] = s->base + s->position;
        data[0xb0/4] = k[0x28/4];
        data[0xb4/4] = k[0x28/4];
        data = *(float**)((char*)ground + 0xd4);
        data[0x12c/4] = s->base + s->position;
        data[0x130/4] = k[0x28/4];
        data[0x134/4] = k[0x28/4];
        float rate = k[0x9c/4];
        if (s->amount > rate) {
            s->next = 1;
            self->playSeBasic((SndID)0x1dac, k[0x28/4]);
        } else {
            rate = rate * s->amount / rate;
        }
        self->getGround(a)->setMotionFrame(rate, 0);
        break;
    }
    case 1:
        if (((grMadein*)self->getGround(a))->isEndEntity()) s->next = 2;
        break;
    case 2:
        if (--s->timer < 0) s->next = 3;
        break;
    case 3:
        if (((grMadein*)self->getGround(a))->isEndEntity()) s->next = 0;
        break;
    }
}
