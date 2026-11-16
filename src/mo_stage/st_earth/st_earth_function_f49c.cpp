#include <mt/mt_vector.h>

#pragma force_active on

struct Ground_base { char pad[0x3c]; };

struct Data {
    char p[0x24];
    float a;   // 0x24
    float b;   // 0x28
    float c;   // 0x2c
};

struct Sub {
    unsigned char b0;   // 0x0
    char p1[7];
    unsigned char b8;   // 0x8
    unsigned char b9;   // 0x9
    unsigned char ba;   // 0xa
    unsigned char bb;   // 0xb
};

class Ground : public Ground_base {
public:
#define V(n) virtual void vf##n();
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28)
    virtual void setVisibility(unsigned long);   // 0x74
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41)
    virtual Data* getData();                     // 0xa8
    V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
    V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62)
    V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72)
    V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82)
    V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92)
    V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102)
    V(103) V(104) V(105) V(106) V(107) V(108) V(109) V(110) V(111) V(112)
    V(113) V(114) V(115) V(116) V(117)
    virtual void fn_66_F97C();                   // 0x1d8
#undef V

    char pad1[0x110];        // 0x3c..0x14c (vptr occupies 4 bytes before base)
    unsigned char state;     // 0x150
    char pad2[3];
    float timer;             // 0x154
    char pad3[0xc];
    float f164;              // 0x164
    char pad4[0xc];
    float f174;              // 0x174
    char pad5[0xc];
    float f184;              // 0x184
    Sub* sub;                // 0x188
};

inline void initVec(Vec3f& v, float z, float y, float x) {
    v.m_x = x;
    v.m_y = y;
    v.m_z = z;
}

extern "C" {
extern const float lbl_66_rodata_1C8;
void* getInstance__9itManagerFv();
void* createItem__9itManagerF6itKindUliP16soResourceModuleUciii(void* self, int kind, unsigned long arg1, int arg2, void* mod, unsigned char arg4, int arg5, int arg6, int arg7);
void warp__8BaseItemFP5Vec3f(void* item, Vec3f* pos);

void fn_66_F49C(Ground* self, float delta) {
    if (self->sub != 0) {
        Data* d = self->getData();
        if (d != 0) {
            self->timer = self->timer - delta;
            if (self->timer < lbl_66_rodata_1C8) {
                self->timer = lbl_66_rodata_1C8;
            }
            switch (self->state) {
            case 0:
                self->setVisibility(0);
                self->state = 1;
                break;
            case 1:
                if (self->sub->b0 == 2) {
                    self->fn_66_F97C();
                    self->setVisibility(1);
                    self->timer = d->a;
                    self->state = 0x13;
                }
                break;
            case 0x13:
                if (lbl_66_rodata_1C8 == self->timer) {
                    Sub* s = self->sub;
                    switch (s->bb) {
                    case 0:
                        self->timer = d->b;
                        s->bb = 1;
                        self->sub->b8 = 2;
                        break;
                    case 1:
                        self->timer = d->c;
                        s->bb = 2;
                        self->sub->b8 = 2;
                        break;
                    case 2:
                        break;
                    }
                }
                if (self->sub->b8 == 4) {
                    self->state = 0x19;
                }
                break;
            case 0x19: {
                self->state = 0;
                Vec3f v;
                float z = self->f184;
                float y = self->f174;
                float x = self->f164;
                initVec(v, z, y, x);
                int idx = 0;
                Sub* s = self->sub;
                switch (s->ba) {
                case 0:
                    switch (s->bb) {
                    case 0: idx = 0; break;
                    case 1: idx = 3; break;
                    case 2: idx = 6; break;
                    case 3: idx = 9; break;
                    }
                    break;
                case 1:
                    switch (s->bb) {
                    case 0: idx = 1; break;
                    case 1: idx = 4; break;
                    case 2: idx = 7; break;
                    case 3: idx = 10; break;
                    }
                    break;
                case 2:
                    switch (s->bb) {
                    case 0: idx = 2; break;
                    case 1: idx = 5; break;
                    case 2: idx = 8; break;
                    case 3: idx = 11; break;
                    }
                    break;
                }
                void* it = getInstance__9itManagerFv();
                if (it != 0) {
                    int sp8 = 0xFFFF;
                    void* item = createItem__9itManagerF6itKindUliP16soResourceModuleUciii(it, 0x4D, idx, -1, 0, 0, 0xFFFF, 0, sp8);
                    if (item != 0) {
                        warp__8BaseItemFP5Vec3f(item, &v);
                    }
                }
                break;
            }
            }
        }
    }
}
}
