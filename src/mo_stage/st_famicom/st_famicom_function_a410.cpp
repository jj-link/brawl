// Partial decompilation: this has not been verified as a machine-code match.
#pragma force_active on

#include <types.h>
#include <ai/ai_mgr.h>
#include <gr/gr_gimmick.h>
#include <st/st_utility.h>
#include <st/stage.h>
#include <nw4r/math/math_arithmetic.h>
#include <revolution/OS/OSFastCast.h>

extern void* g_GameGlobal;
extern Stage* lbl_27_bss_5668;
extern "C" const float lbl_68_rodata_D0[];

extern "C" void fn_27_1F299C(aiMgr*, int);
extern "C" float fn_8016232C(float);
extern "C" float fn_801622C4(float);
extern "C" unsigned int fn_8004E96C(void*);

struct Parameters {
    char pad00[0x34];
    float value34;
    char pad38[8];
    float scale40;
    float scale44;
    float unk48;
};

struct GroundEntry {
    float x;
    float y;
    float z;
    float f0C;
    float f10;
    float f14;
    u8 b18;
    u8 b19;
    char pad1A[2];
    float f1C;
    float f20;
    u8 b24;
    char pad25[3];
};

struct Area {
    float x;
    float y;
    float unk08;
    float unk0C;
    u8 flag10;
    char pad11[3];
};

struct Rect {
    float left;
    float bottom;
    float unk08;
    float right;
    float top;
};

struct ObjectBase {
    char pad[0x3c];
};

#define V(n) virtual void v##n();

class Object : public ObjectBase {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
    V(24) V(25) V(26)
    virtual void setVisibility(unsigned long);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35)
    V(36) V(37) V(38) V(39)
    virtual Parameters* getParam();
    V(41) V(42) V(43) V(44) V(45) V(46) V(47)
    V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55)
    V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63)
    V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71)
    V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95)
    virtual void enableHit(unsigned long, unsigned long);
    virtual void disableHit(unsigned long, unsigned long);
    virtual void disableAttack(unsigned long);
    V(99) V(100) V(101) V(102) V(103) V(104) V(105)
    V(106) V(107) V(108) V(109) V(110) V(111) V(112)
    V(113) V(114) V(115) V(116) V(117) V(118) V(119)
    V(120) V(121) V(122) V(123) V(124) V(125) V(126)
    V(127) V(128) V(129) V(130) V(131) V(132) V(133)
    virtual int v134();
    virtual unsigned int v135();
    virtual unsigned int v136();
    virtual unsigned int v137();
    V(138)
    virtual unsigned int v139();
    V(140)

    char pad40[0x24];
    float f64;
    char pad68[4];
    u8 u6C;
    char pad6D[0xe3];
    u8 state;
    char pad151[3];
    float f154;
    char pad158[8];
    float f160;
    float f164;
    float f168;
    u8 u16C;
    u8 u16D;
    u8 u16E;
    char pad16F[5];
    u8 u174;
    u8 idx;
    u8 u176;
    char pad177;
    GroundEntry* entries;
    float* p17C;
    Rect* p180;
    Area* p184;
    char pad188;
    u8 u189;
    char pad18A[0x1e];
    int s1A8;
    char pad1AC;
    u8 u1AD;
    char pad1AE[2];
    int aiHandle;
};

#undef V

static inline void setVec2(Vec2f* out, float x, float y) {
    out->m_x = x;
    out->m_y = y;
}

static inline float clampSelect(float value, float low, float high) {
    float t = nw4r::math::FSelect(value - low, value, low);
    return nw4r::math::FSelect(t - high, high, t);
}

extern "C" void fn_68_A410(Object* self, float delta) {
    const float* c = lbl_68_rodata_D0;
    Vec3f hit;
    Vec3f normal;
    Vec3f start;
    Vec3f dir;
    unsigned int grounded;
    Parameters* p = self->getParam();

    if (p == 0) {
        return;
    }

    self->f154 = self->f154 - delta;
    if (self->f154 < c[0]) {
        self->f154 = c[0];
    }

    self->entries[self->idx].f1C =
        self->entries[self->idx].f1C - delta;
    if (self->entries[self->idx].f1C < c[0]) {
        self->entries[self->idx].f1C = c[0];
    }

    if (self->aiHandle != -1) {
        fn_27_1F299C(g_aiMgr, self->aiHandle);
        self->aiHandle = -1;
    }

    switch (self->u174) {
    case 1:
        self->f64 = c[1];
        break;
    case 2:
        self->f64 = p->scale40;
        break;
    case 3:
        self->f64 = p->scale44;
        break;
    default:
        self->f64 = c[1];
        break;
    }

    self->entries[self->idx].b19 = 0;

    switch (self->state) {
    case 6:
    case 10:
    case 11:
    case 12:
    case 14:
        if (self->f168 > c[0]) {
            GroundEntry* q = self->entries + self->idx;
            start.m_x = q->x;
            start.m_y = q->y;
            start.m_z = q->z;
            start.m_y += c[2];

            dir.m_x = c[0];
            dir.m_y = c[3];
            dir.m_z = c[0];
            hit.m_x = c[0];
            hit.m_y = c[0];
            hit.m_z = c[0];
            normal.m_x = c[0];
            normal.m_y = c[0];
            normal.m_z = c[0];

            if (stRayCheck(&start, &dir, &hit, &normal,
                           false, 0, false, 1) == 1 &&
                normal.m_y > c[0] &&
                self->entries[self->idx].y - self->f168 < hit.m_y) {
                if (self->u176 > 2) {
                    self->entries[self->idx].b19 = 1;
                }

                self->u176++;
                if (self->u176 > 5) {
                    self->u176 = 5;
                }

                for (u8 i = 0; i < 7; i++) {
                    Area* a = self->p184 + i;
                    if (a->flag10 == 0 &&
                        hit.m_x > a->x - c[4] &&
                        hit.m_x < c[4] + a->x &&
                        hit.m_y > a->y - c[4] &&
                        hit.m_y < c[4] + a->y) {
                        float value =
                            (self->entries[self->idx].x -
                             (hit.m_x - c[4])) / c[5];
                        self->entries[self->idx].f20 =
                            c[1] - clampSelect(value, c[0], c[1]);
                        break;
                    }
                }
                grounded = 1;
            } else {
                self->entries[self->idx].y =
                    self->entries[self->idx].y - self->f168 * delta;
                self->u176 = 0;
                grounded = 0;
            }
        }
        break;
    }

    switch (self->state) {
    case 0:
        self->setVisibility(0);
        self->disableHit(0, 0);
        self->v122();
        self->state = 1;
        break;

    case 1:
        if (c[0] == self->f154 &&
            self->entries[self->idx].b24 != 13 &&
            self->v134() != 0) {
            self->entries[self->idx].b24 = 5;
            self->v140();
            self->state = 4;
        }
        break;

    case 4:
        if (!((self->u6C >> 7) & 1)) {
            self->setVisibility(1);
        }
        if (self->u16C == 1) {
            self->u16C = 0;
            self->f154 = c[6];
        } else {
            self->f154 = c[0];
        }
        self->state = 5;
        break;

    case 5:
        if (c[0] == self->f154) {
            self->enableHit(0, 0);
            self->entries[self->idx].z = c[0];
            self->entries[self->idx].b24 = 0;
            self->state = 6;
        } else {
            float t = c[1] - self->f154 / c[6];
            if (t < c[0]) {
                t = c[0];
            }
            if (t > c[1]) {
                t = c[1];
            }

            if (self->entries[self->idx].b18 == 1) {
                self->entries[self->idx].x = self->p17C[0] + c[5] * t;
            } else {
                self->entries[self->idx].x = self->p17C[3] - c[5] * t;
            }

            if (self->f154 <= c[7]) {
                float u = c[1] - self->f154 / c[7];
                if (u < c[0]) {
                    u = c[0];
                }
                if (u > c[1]) {
                    u = c[1];
                }
                u16 angle = (u16)(int)(c[8] * u);
                float r = fn_8016232C(c[9] * __OSu16tof32(&angle));
                if (self->entries[self->idx].b18 == 1) {
                    self->entries[self->idx].z = self->p17C[2] - c[10] * r;
                } else {
                    self->entries[self->idx].z = self->p17C[5] - c[10] * r;
                }
            }
        }
        break;

    case 6:
        self->f160 = self->f160 - delta;
        if (self->f160 < c[0]) {
            self->f160 = c[0];
        }
        if (c[0] == self->f160 && self->u189 == 0) {
            self->v117();
        }

        if (self->entries[self->idx].b18 == 1) {
            if (self->u16D == 1) {
                self->entries[self->idx].x += self->f164 * delta;
            }
            if (self->entries[self->idx].x > self->p180->right) {
                self->setVisibility(0);
                self->disableHit(0, 0);
                self->disableAttack(0);
                self->u189 = 0;
                self->entries[self->idx].b24 = 3;
                self->state = 7;
            } else if (self->entries[self->idx].x >= self->p17C[9] - c[11] &&
                       self->entries[self->idx].x <= c[11] + self->p17C[9] &&
                       self->v135() == 1) {
                self->disableHit(0, 0);
                self->disableAttack(0);
                self->u189 = 0;
                self->entries[self->idx].b24 = 4;
                self->f154 = c[6];
                self->state = 8;
            }
        } else {
            if (self->u16D == 1) {
                self->entries[self->idx].x -= self->f164 * delta;
            }
            if (self->entries[self->idx].x < self->p180->left) {
                self->setVisibility(0);
                self->disableHit(0, 0);
                self->disableAttack(0);
                self->u189 = 0;
                self->entries[self->idx].b24 = 3;
                self->state = 7;
            } else if (self->entries[self->idx].x <= c[11] + self->p17C[6] &&
                       self->entries[self->idx].x >= self->p17C[6] - c[11] &&
                       self->v135() == 1) {
                self->disableHit(0, 0);
                self->disableAttack(0);
                self->u189 = 0;
                self->entries[self->idx].b24 = 4;
                self->f154 = c[6];
                self->state = 8;
            }
        }

        if (self->f168 > c[0]) {
            if (grounded == 1) {
                self->entries[self->idx].y = hit.m_y;
                self->f168 = p->value34;
                if (self->entries[self->idx].b19 == 1) {
                    if (c[12] != self->entries[self->idx].f20) {
                        self->state = 13;
                    } else if (self->entries[self->idx].b24 == 8) {
                        self->state = 13;
                    }
                }
                self->u16D = 1;
            }
            self->f168 += p->value34 * delta;
        } else {
            self->entries[self->idx].y -= self->f168 * delta;
            float accel = c[13] * p->value34;
            self->f168 = self->f168 + accel * delta;
        }

        if (self->u176 > 2 && self->v139() == 1) {
            self->v125();
        }
        {
            Vec2f b;
            Vec2f a(self->entries[self->idx].x - c[14], c[7] + self->entries[self->idx].y);
            setVec2(&b, c[14] + self->entries[self->idx].x, self->entries[self->idx].y - c[5]);
            self->aiHandle =
                g_aiMgr->setDangerZone(&a, &b, self->aiHandle, false, false);
        }
        break;

    case 7:
        if (self->entries[self->idx].b18 == 1) {
            self->entries[self->idx].x = self->p180->left;
        } else {
            self->entries[self->idx].x = self->p180->right;
        }
        self->state = 4;
        self->f154 = c[0];
        break;

    case 8:
        if (c[0] == self->f154) {
            self->setVisibility(0);
            self->state = 9;
        } else {
            float t = self->f154 / c[6];
            if (t < c[0]) {
                t = c[0];
            }
            if (t > c[1]) {
                t = c[1];
            }
            if (self->entries[self->idx].b18 == 1) {
                self->entries[self->idx].x = self->p17C[9] - c[11] * t;
            } else {
                self->entries[self->idx].x = self->p17C[6] + c[11] * t;
            }

            float u = c[1] - (self->f154 - c[7]) / c[7];
            if (u < c[0]) {
                u = c[0];
            }
            if (u > c[1]) {
                u = c[1];
            }
            if (self->entries[self->idx].b18 == 1) {
                self->entries[self->idx].y +=
                    u * ((self->p17C[10] - self->entries[self->idx].y) - c[15]);
            } else {
                self->entries[self->idx].y +=
                    u * ((self->p17C[7] - self->entries[self->idx].y) - c[15]);
            }

            float v = c[1] - (self->f154 - c[7]) / c[7];
            if (v < c[0]) {
                v = c[0];
            }
            if (v > c[1]) {
                v = c[1];
            }
            u16 angle = (u16)(int)(c[8] * v);
            float r = fn_801622C4(c[9] * __OSu16tof32(&angle));
            if (self->entries[self->idx].b18 == 1) {
                self->entries[self->idx].z = self->p17C[11] - c[10] * r;
            } else {
                self->entries[self->idx].z = self->p17C[8] - c[10] * r;
            }
        }
        break;

    case 9:
        if (self->entries[self->idx].b18 == 1) {
            *(Vec3f*)&self->entries[self->idx].x = *(Vec3f*)&self->p17C[3];
            self->entries[self->idx].y -= c[15];
            self->entries[self->idx].z -= c[10];
            self->entries[self->idx].b18 = 0;
            GroundEntry* entry = self->entries + self->idx;
            entry->f0C = c[0];
            entry->f10 = c[16];
            entry->f14 = c[0];
        } else {
            *(Vec3f*)&self->entries[self->idx].x = *(Vec3f*)&self->p17C[0];
            self->entries[self->idx].y -= c[15];
            self->entries[self->idx].z -= c[10];
            self->entries[self->idx].b18 = 1;
            GroundEntry* entry = self->entries + self->idx;
            entry->f0C = c[0];
            entry->f10 = c[0];
            entry->f14 = c[0];
        }
        ((grGimmick*)self)->setPos((Vec3f*)(self->entries + self->idx));
        self->u16C = 1;
        self->f154 = p->unk48;
        self->state = 1;
        break;

    case 10:
        self->f64 = c[1];
        if (grounded == 1 && self->entries[self->idx].b19 == 1) {
            if (c[12] != self->entries[self->idx].f20) {
                self->state = 13;
            } else if (self->entries[self->idx].b24 == 8) {
                self->state = 13;
            }
        }
        break;

    case 13:
        if (fn_8004E96C(g_GameGlobal) == 1) {
            self->v121();
            self->entries[self->idx].f20 = c[12];
        }
        break;

    case 11:
    case 12:
        self->f64 = c[1];
        if (self->s1A8 == 0) {
            switch (self->u16E) {
            case 0:
                break;
            case 1:
                if (self->entries[self->idx].b18 == 1) {
                    self->entries[self->idx].x += c[13] * (self->f164 * delta);
                } else {
                    self->entries[self->idx].x -= c[13] * (self->f164 * delta);
                }
                break;
            case 2:
                if (self->entries[self->idx].b18 == 1) {
                    self->entries[self->idx].x -= c[13] * (self->f164 * delta);
                } else {
                    self->entries[self->idx].x += c[13] * (self->f164 * delta);
                }
                break;
            }

            if (self->entries[self->idx].x < self->p180->left) {
                self->entries[self->idx].x = self->p180->right;
            }
            if (self->entries[self->idx].x > self->p180->right) {
                self->entries[self->idx].x = self->p180->left;
            }
        }

        if (self->f168 > c[0]) {
            if (grounded == 1) {
                if (self->s1A8 == 0) {
                    self->entries[self->idx].y = hit.m_y;
                }
                self->u16E = 0;
                self->f168 = c[0];
                if (self->state == 11) {
                    self->v123();
                }
                if (self->entries[self->idx].b19 == 1) {
                    if (c[12] != self->entries[self->idx].f20) {
                        self->v124();
                        self->entries[self->idx].f20 = c[12];
                    } else if (self->entries[self->idx].b24 == 8) {
                        self->v124();
                    }
                }
            }
        } else if (self->f168 < c[0]) {
            self->entries[self->idx].y -= self->f168 * delta;
            self->u176 = 0;
        } else if (self->v136() == 1 && self->v137() == 1) {
            self->entries[self->idx].b19 = 1;
            if (c[12] != self->entries[self->idx].f20) {
                self->v124();
                self->entries[self->idx].f20 = c[12];
            } else if (self->entries[self->idx].b24 == 8) {
                self->v124();
            }
        }

        if (self->s1A8 == 0) {
            float accel = c[13] * p->value34;
            self->f168 = self->f168 + accel * delta;
        }
        break;

    case 14:
        self->f64 = c[1];
        if (self->v136() == 1 && self->v137() == 1) {
            self->entries[self->idx].b19 = 1;
            if (c[12] != self->entries[self->idx].f20) {
                self->v124();
                self->entries[self->idx].f20 = c[12];
            } else if (self->entries[self->idx].b24 == 8) {
                self->v124();
            }
        }
        break;

    case 15:
        switch (self->u16E) {
        case 0:
            break;
        case 1:
            if (self->entries[self->idx].b18 == 1) {
                self->f168 = self->f164 * delta;
            } else {
                self->f168 = -(self->f164 * delta);
            }
            break;
        case 2:
            if (self->entries[self->idx].b18 == 1) {
                self->f168 = -(self->f164 * delta);
            } else {
                self->f168 = self->f164 * delta;
            }
            break;
        }
        self->entries[self->idx].x += self->f168;
        self->entries[self->idx].y += c[17] * (self->f164 * delta);
        Rect* bounds = self->p180;
        GroundEntry* entry = self->entries + self->idx;
        if (entry->x < bounds->left - c[4] ||
            entry->x > c[4] + bounds->right ||
            entry->y > c[4] + bounds->bottom ||
            entry->y < bounds->top - c[4]) {
            self->state = 17;
        }
        break;

    case 16:
        switch (self->u16E) {
        case 0:
            break;
        case 1:
            if (self->entries[self->idx].b18 == 1) {
                self->entries[self->idx].x += c[13] * (self->f164 * delta);
            } else {
                self->entries[self->idx].x -= c[13] * (self->f164 * delta);
            }
            break;
        case 2:
            if (self->entries[self->idx].b18 == 1) {
                self->entries[self->idx].x -= c[13] * (self->f164 * delta);
            } else {
                self->entries[self->idx].x += c[13] * (self->f164 * delta);
            }
            break;
        }
        self->entries[self->idx].y -= self->f168;
        self->f168 += c[13] * p->value34;

        Rect* bounds16 = self->p180;
        GroundEntry* entry16 = self->entries + self->idx;
        if (entry16->x < bounds16->left - c[4] ||
            entry16->x > c[4] + bounds16->right ||
            entry16->y > c[18] + bounds16->bottom ||
            entry16->y < bounds16->top - c[4]) {
            if (self->u1AD != 1 &&
                (self->v136() != 1 || self->v137() != 0)) {
                self->state = 17;
            }
        }
        break;

    case 17:
        self->f64 = c[1];
        self->setVisibility(0);
        self->v72();
        ((gfTask*)self)->exit();
        lbl_27_bss_5668->removeGround((Ground*)self);
        self->entries[self->idx].b24 = 13;
        self->state = 18;
        break;

    case 18:
        break;
    }
}
