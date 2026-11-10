#pragma force_active on
#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>

#define P1D8(s) (*(f32**)((s) + 0x1D8))

class Obj3cBase {
public:
    char pad[0x3c];
};

class Obj3c : public Obj3cBase {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27(u32 arg);
};

extern "C" {
extern const f32 lbl_53_rodata_0[];
extern u8 lbl_53_data_0[];
void startEntity__8grMadeinFv(void* p);
f32 randf__Fv();
void playSeBasic__7stMeleeF5SndIDf(void* self, u32 sndId, f32 pan);
void fn_27_263984(void* p, f32 f);
void fn_8003E918(Matrix* m, f32 f);
void fn_8003F074(Matrix* m, f32 x, f32 y, f32 z);
void fn_27_279FC8(void* p, void* src, int arg);
void setFrame__16gfModelAnimationFd(void* anim, f64 frame);
void setMotion__8grMadeinFUl(void* p, u32 motion);
void setIdentity__6MatrixFv(Matrix* m);
void fn_53_129C(void* self, Matrix* m, int init);
}

extern "C" void fn_53_1E88(void* p, f32 dt) {
    const u8* dd;
    const f32* rd;
    char* self;
    s32 st;
    f32 t;

    rd = lbl_53_rodata_0;
    dd = lbl_53_data_0;
    self = (char*)p;

    if (*(u8*)(self + 0x228) != 0) {
        return;
    }
    st = *(s32*)(self + 0x368);
    switch (st) {
    case 0:
        goto S0;
    case 0x3AB:
        goto S3AB;
    case 0x3BF:
        goto S3BF;
    case 0x3CB:
        goto S3CB;
    case 0x3D5:
        goto S3D5;
    case 0x3ED:
        goto S3ED;
    case 0x474:
        goto S474;
    case 0x479:
    case 0x489:
        goto S479;
    default:
        return;
    }

S0:
    *(s32*)(self + 0x364) = *(s32*)(dd + 0x24C);
    *(s32*)(self + 0x368) = 0x3AB;
S3AB:
    *(f32*)(self + 0x36C) = P1D8(self)[0];
LRAND:
    t = rd[13] * randf__Fv();
    if (P1D8(self)[3] < t) {
        goto S3CB;
    }
    goto S3BF;

S3BF_dec:
    *(f32*)(self + 0x36C) = *(f32*)(self + 0x36C) - dt;
    *(s32*)(self + 0x364) = *(s32*)(dd + 0x250);
    *(s32*)(self + 0x368) = 0x3BF;
    return;

S3BF:
    if (rd[0] < *(f32*)(self + 0x36C)) {
        goto S3BF_dec;
    }
    {
        f32 f30 = P1D8(self)[2] - P1D8(self)[1];
        f32 r = randf__Fv();
        *(f32*)(self + 0x36C) = P1D8(self)[1] + f30 * r;
    }
    goto LRAND;

S3CB_nz:
    *(s32*)(self + 0x364) = *(s32*)(dd + 0x254);
    *(s32*)(self + 0x368) = 0x3CB;
    return;

S3CB:
    if (*(u8*)(self + 0x4B0) != 0) {
        goto S3CB_nz;
    }
    goto S3D5;

S3D5_dec:
    *(f32*)(self + 0x36C) = *(f32*)(self + 0x36C) - dt;
    *(s32*)(self + 0x364) = *(s32*)(dd + 0x258);
    *(s32*)(self + 0x368) = 0x3D5;
    return;

S3D5:
    if (P1D8(self)[4] < *(f32*)(self + 0x36C)) {
        goto S3D5_dec;
    }
    {
        u8 a = *(u8*)(self + 0x370);
        u8 b = *(u8*)(self + 0x371);
        if (a == b) {
            *(bool*)(self + 0x370) = (a == 0);
        } else {
            *(u8*)(self + 0x371) = a;
            t = rd[13] * randf__Fv();
            *(bool*)(self + 0x370) = (t <= rd[32]);
        }
    }
    playSeBasic__7stMeleeF5SndIDf(self, 0x1BB0, *(u8*)(self + 0x370) != 0 ? rd[33] : rd[34]);
    goto S3ED;

S3ED_dec:
    *(f32*)(self + 0x36C) = *(f32*)(self + 0x36C) - dt;
    *(s32*)(self + 0x364) = *(s32*)(dd + 0x25C);
    *(s32*)(self + 0x368) = 0x3ED;
    return;

S3ED:
    if (rd[0] < *(f32*)(self + 0x36C)) {
        goto S3ED_dec;
    }
    {
        f32 f30 = P1D8(self)[8] + (P1D8(self)[7] + (P1D8(self)[5] + P1D8(self)[6]));
        f32 x = f30 * randf__Fv();
        if (x <= P1D8(self)[5]) {
            *(u8*)(self + 0x372) = 0;
        } else {
            f32 y = x - P1D8(self)[5];
            if (y <= P1D8(self)[6]) {
                *(u8*)(self + 0x372) = 1;
            } else {
                f32 z = y - P1D8(self)[6];
                if (z <= P1D8(self)[7]) {
                    *(u8*)(self + 0x372) = 0;
                } else {
                    *(u8*)(self + 0x372) = 1;
                }
            }
        }
    }

S2160:
    {
        u8 c374 = *(u8*)(self + 0x374);
        if (c374 == 0 && *(u8*)(self + 0x375) == 0) {
            *(u8*)(self + 0x374) = 1;
            *(u8*)(self + 0x373) = 1;
        } else {
            *(u8*)(self + 0x375) = c374;
            t = rd[26] * randf__Fv();
            u8 v = (t <= P1D8(self)[9]);
            *(u8*)(self + 0x374) = v;
            *(u8*)(self + 0x373) = v;
        }
    }

    setIdentity__6MatrixFv((Matrix*)(self + 0x234));
    if (*(u8*)(self + 0x370) != 0) {
        fn_8003E918((Matrix*)(self + 0x234), rd[35]);
        char* o208 = *(char**)(self + 0x208);
        fn_27_263984(*(void**)(o208 + 0x14C), rd[36]);
    } else {
        char* o208 = *(char**)(self + 0x208);
        fn_27_263984(*(void**)(o208 + 0x14C), rd[13]);
    }
    {
        Vec3f v(rd[37], rd[0], rd[0]);
        fn_8003F074((Matrix*)(self + 0x234), v.m_x, v.m_y, v.m_z);
    }

    if (*(u8*)(self + 0x372) != 0) {
        s32 m11;
        s32 m10;
        s32 m9;
        s32 m8;
        s32 m7;
        s32 m6;
        s32 m5;
        s32 m4;
        s32 m3;
        s32 m2;
        s32 m1;
        s32 m0;

        m0 = *(s32*)(self + 0x234);
        m1 = *(s32*)(self + 0x238);
        m2 = *(s32*)(self + 0x23C);
        m3 = *(s32*)(self + 0x240);
        m4 = *(s32*)(self + 0x244);
        m5 = *(s32*)(self + 0x248);
        m6 = *(s32*)(self + 0x24C);
        m7 = *(s32*)(self + 0x250);
        m8 = *(s32*)(self + 0x254);
        m9 = *(s32*)(self + 0x258);
        m10 = *(s32*)(self + 0x25C);
        m11 = *(s32*)(self + 0x260);

        *(s32*)(self + 0x398) = m0;
        *(s32*)(self + 0x39C) = m1;
        *(s32*)(self + 0x3A0) = m2;
        *(s32*)(self + 0x3A4) = m3;
        *(s32*)(self + 0x3A8) = m4;
        *(s32*)(self + 0x3AC) = m5;
        *(s32*)(self + 0x3B0) = m6;
        *(s32*)(self + 0x3B4) = m7;
        *(s32*)(self + 0x3B8) = m8;
        *(s32*)(self + 0x3BC) = m9;
        *(s32*)(self + 0x3C0) = m10;
        *(s32*)(self + 0x3C4) = m11;
        *(s32*)(self + 0x3C8) = m0;
        *(s32*)(self + 0x3CC) = m1;
        *(s32*)(self + 0x3D0) = m2;
        *(s32*)(self + 0x3D4) = m3;
        *(s32*)(self + 0x3D8) = m4;
        *(s32*)(self + 0x3DC) = m5;
        *(s32*)(self + 0x3E0) = m6;
        *(s32*)(self + 0x3E4) = m7;
        *(s32*)(self + 0x3E8) = m8;
        *(s32*)(self + 0x3EC) = m9;
        *(s32*)(self + 0x3F0) = m10;
        *(s32*)(self + 0x3F4) = m11;
        *(u8*)(self + 0x388) = 1;
        *(s32*)(self + 0x38C) = *(s32*)(dd + 0);
        *(s32*)(self + 0x390) = 0;

        startEntity__8grMadeinFv(*(void**)(self + 0x1F4));
        (*(Obj3c**)(self + 0x1F4))->slot27(1);
        startEntity__8grMadeinFv(*(void**)(self + 0x20C));
        fn_27_279FC8(*(void**)(self + 0x1F4), self + 0x398, 0);
        setMotion__8grMadeinFUl(*(void**)(self + 0x1F4), 0);
        {
            char* g = *(char**)(self + 0x1F4);
            void* anim = *(void**)(*(char**)(g + 0x48));
            if (anim != 0) {
                setFrame__16gfModelAnimationFd(anim, rd[0]);
            }
        }
        fn_27_279FC8(*(void**)(self + 0x20C), self + 0x398, 0);
    }
    *(f32*)(self + 0x394) = rd[38];
    goto S474;

S474_dec:
    *(f32*)(self + 0x394) = *(f32*)(self + 0x394) - dt;
    *(s32*)(self + 0x364) = *(s32*)(dd + 0x260);
    *(s32*)(self + 0x368) = 0x474;
    return;

S474:
    if (rd[0] < *(f32*)(self + 0x394)) {
        goto S474_dec;
    }
    fn_53_129C(self, (Matrix*)(self + 0x234), 1);
    *(s32*)(self + 0x364) = *(s32*)(dd + 0x264);
    *(s32*)(self + 0x368) = 0x479;
    return;

S489:
    *(s32*)(self + 0x364) = *(s32*)(dd + 0x268);
    *(s32*)(self + 0x368) = 0x489;
    return;

S479:
    if (*(u8*)(self + 0x229) != 0) {
        goto S489;
    }
    if (*(u8*)(self + 0x372) != 0 && *(u8*)(self + 0x388) != 0) {
        goto S489;
    }
    {
        f32 f30 = P1D8(self)[2] - P1D8(self)[1];
        f32 r = randf__Fv();
        *(f32*)(self + 0x36C) = P1D8(self)[1] + f30 * r;
    }
    goto LRAND;
}
