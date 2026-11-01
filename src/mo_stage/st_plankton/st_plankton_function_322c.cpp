#include <nw4r/math/math_arithmetic.h>

#pragma force_active on
#pragma pool_data on

typedef unsigned char u8;

struct StageData {
    char pad[0x28];
    float duration;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Rect {
    float a;
    float b;
    float c;
    float d;
};

struct GroundBase {
    char pad[0x3c];
};

#define S(n) virtual void slot##n();

class Ground : public GroundBase {
public:
    S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
    S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19)
    S(20) S(21) S(22) S(23) S(24) S(25) S(26) S(27) S(28)
    virtual void setVisibility(unsigned long);
    S(30) S(31) S(32) S(33) S(34) S(35) S(36) S(37) S(38) S(39)
    S(40) S(41)
    virtual StageData* fn_74_2F7C();
    S(43) S(44) S(45) S(46) S(47) S(48) S(49)
    virtual void getNodePosition(Vec3*, unsigned long, unsigned long);
    S(51) S(52) S(53) S(54) S(55) S(56) S(57) S(58) S(59)
    S(60) S(61) S(62) S(63) S(64) S(65) S(66) S(67) S(68) S(69)
    S(70) S(71) S(72) S(73) S(74) S(75) S(76) S(77) S(78) S(79)
    S(80) S(81) S(82) S(83) S(84) S(85) S(86) S(87) S(88) S(89)
    S(90) S(91) S(92) S(93) S(94) S(95) S(96) S(97) S(98) S(99)
    S(100) S(101) S(102) S(103) S(104) S(105) S(106) S(107) S(108) S(109)
    S(110) S(111) S(112) S(113) S(114) S(115)
    virtual void fn_74_36CC();
    S(117)
    virtual unsigned long fn_74_3734();

    char pad40[0x84];
    void* nodeData;
    char padC8[0x88];
    u8 state;
    char pad151[3];
    float timer;
    u8 sound;
    char pad159[3];
    float fade;
    float cooldown;
    float x;
    float y;
    float z;
    int active;
    float pos[2];
    union {
        unsigned long raw;
        struct {
            unsigned long enabled : 3;
            unsigned long other : 3;
            unsigned long unused : 26;
        } bits;
    } flags;
    char pad180[0x30];
    Rect rect;
};

#undef S

static inline float ClampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" {
extern const float lbl_74_rodata_B0[];
extern void* g_sndSystem;
void fn_8009EF8C(void*, const void*);
void fn_80077174(void*, int, int, float);

void fn_74_322C(Ground* self, float dt) {
    const float* k = lbl_74_rodata_B0;

    if (self->active == 0)
        return;

    StageData* data = self->fn_74_2F7C();
    if (data == 0)
        return;

    self->timer -= dt;
    if (self->timer < k[0])
        self->timer = k[0];

    self->fade -= dt;
    if (self->fade < k[0])
        self->fade = k[0];

    self->cooldown -= dt;
    if (self->cooldown < k[0])
        self->cooldown = k[0];

    switch (self->state) {
    case 0:
        self->setVisibility(0);
        self->x = k[2];
        self->y = k[2];
        self->z = k[2];
        self->flags.bits.enabled = 1;
        self->state = 1;
        /* fall through */
    case 1:
        if (self->fn_74_3734() == 1) {
            self->flags.raw &= 0x03FFFFFFUL;

            Rect r;
            Vec3 node;
            self->getNodePosition(&node, 0, (unsigned long)self->nodeData);

            r.c = k[3];
            r.d = k[4];
            r.a = k[4];
            r.b = k[3];

            fn_8009EF8C(self->pos, &node);
            self->rect = r;
            self->state = 4;
        } else {
            break;
        }
        /* fall through */
    case 4:
        self->setVisibility(1);
        self->x = k[1];
        self->y = k[1];
        self->z = k[1];

        if (k[0] == self->cooldown) {
            self->fn_74_36CC();
            self->cooldown = k[5];
        }

        self->timer = data->duration;

        switch (self->sound) {
        case 0:
            self->fade = k[6];
            break;
        case 1:
        case 4:
            break;
        case 6:
            self->fade = k[0];
            break;
        }

        self->sound = 4;
        self->state = 6;
        /* fall through */
    case 6:
        if (self->fn_74_3734() == 1) {
            self->state = 4;
            break;
        } else {
            float ratio = self->timer / data->duration;
            float f = ClampRange(ratio, k[2], k[1]);
            self->x = f;
            self->y = f;
            self->z = f;

            if (k[2] == f)
                self->state = 0;

            if (f <= k[7] && self->sound == 1) {
                self->fade = k[7] * data->duration;
                self->sound = 6;
            }
        }
        break;
    }

    switch (self->sound) {
    case 0:
    case 1:
        break;
    case 4: {
        float v = k[1] - self->fade / k[6];
        float f = ClampRange(v, k[0], k[1]);

        fn_80077174(g_sndSystem, 0, 0, f);
        if (k[1] == f)
            self->sound = 1;
        break;
    }
    case 6: {
        float v = self->fade / (k[7] * data->duration);
        float f = ClampRange(v, k[0], k[1]);

        fn_80077174(g_sndSystem, 0, 0, f);
        if (k[0] == f)
            self->sound = 0;
        break;
    }
    default:
        break;
    }
}
}
