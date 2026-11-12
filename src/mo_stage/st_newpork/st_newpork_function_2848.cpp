#pragma force_active on

extern "C" {
void setAttack__8grMadeinFfP5Vec3f(void*, float, void*);
void createAttackPointNormal__8grMadeinFP21soCollisionAttackData(void*, void*);
void setSleepAttack__10grYakumonoFb(void*, bool);
void createSoundWork__9grGimmickFUlUl(void*, unsigned long, unsigned long);
void fn_27_27C150(void*, int);
void fn_27_27C1E8(void*, int, void*, int);
extern const float lbl_69_rodata_88;
extern const float lbl_69_rodata_8C;
}

struct Attack {
    int damage;
    char pad04[20];
    int knock;
    int base;
    int growth;
    float field24;
    float value;
    int field2C;
    unsigned angle : 9;
    unsigned rest30 : 18;
    unsigned type : 5;
    unsigned kind : 2;
    unsigned sound : 5;
    unsigned rest34a : 3;
    unsigned flag : 1;
    unsigned rest34b : 21;
    unsigned field38;
    unsigned flag3C : 1;
    unsigned rest3C : 31;
};

extern "C" Attack* getOverwriteAttackData__8grMadeinFv(void*);

struct IntPair {
    unsigned long a, b;
};

struct Vec2 {
    float x, y;
    Vec2() {}
};

struct Sound {
    unsigned long id, a, b;
    unsigned short c, pad;
    Vec2 pos;
    char rest[16];
};

struct Work {
    char pad[12];
    Sound sound[7];
};

struct Other {
    char pad[0x28];
    int value;
};

struct Object {
    char pad[0xA8];
    Work* work;
    char pad2[0xB0];
    Other* other;
};

struct Ev {
    int kind;
    float frame;
    int z;
};

#define P(a, b) {2, a, 0}, {3, b, 0}

static Ev evA[26] = {
    P(29.0f, 62.0f), P(73.0f, 106.0f), P(152.0f, 186.0f), P(211.0f, 242.0f),
    P(287.0f, 341.0f), P(382.0f, 414.0f), P(455.0f, 483.0f), P(520.0f, 553.0f),
    P(557.0f, 606.0f), P(630.0f, 662.0f), P(697.0f, 721.0f), P(743.0f, 788.0f),
    P(812.0f, 837.0f)
};
static Ev evB[34] = {
    P(31.0f, 61.0f), P(93.0f, 119.0f), P(161.0f, 183.0f), P(210.0f, 250.0f),
    P(279.0f, 303.0f), P(331.0f, 362.0f), P(391.0f, 420.0f), P(470.0f, 483.0f),
    P(511.0f, 540.0f), P(572.0f, 600.0f), P(633.0f, 660.0f), P(692.0f, 722.0f),
    P(750.0f, 783.0f), P(813.0f, 841.0f), P(895.0f, 932.0f), P(962.0f, 992.0f),
    P(1024.0f, 1051.0f)
};
static Ev evD[2] = {
    P(7.0f, 40.0f)
};
static Ev evC[36] = {
    P(31.0f, 61.0f), P(93.0f, 121.0f), P(160.0f, 192.0f), P(214.0f, 245.0f),
    P(271.0f, 302.0f), P(332.0f, 361.0f), P(393.0f, 423.0f), P(452.0f, 483.0f),
    P(512.0f, 550.0f), P(571.0f, 602.0f), P(633.0f, 661.0f), P(691.0f, 722.0f),
    P(752.0f, 784.0f), P(812.0f, 848.0f), P(873.0f, 905.0f), P(930.0f, 966.0f),
    P(992.0f, 1023.0f), P(1053.0f, 1078.0f)
};

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_deadassign off

extern "C" void fn_69_2848(
    Object* o, float f, void* v, unsigned angle, int enabled
) {
    setAttack__8grMadeinFfP5Vec3f(o, f, v);
    o->other->value = 4;

    createAttackPointNormal__8grMadeinFP21soCollisionAttackData(
        o, getOverwriteAttackData__8grMadeinFv(o)
    );

    getOverwriteAttackData__8grMadeinFv(o)->damage = 100;
    getOverwriteAttackData__8grMadeinFv(o)->knock = 50;
    getOverwriteAttackData__8grMadeinFv(o)->base = 0;
    getOverwriteAttackData__8grMadeinFv(o)->growth = 70;
    getOverwriteAttackData__8grMadeinFv(o)->value = lbl_69_rodata_88;
    getOverwriteAttackData__8grMadeinFv(o)->angle = angle;
    getOverwriteAttackData__8grMadeinFv(o)->flag3C = 0;
    getOverwriteAttackData__8grMadeinFv(o)->type = 2;
    getOverwriteAttackData__8grMadeinFv(o)->kind = 2;
    getOverwriteAttackData__8grMadeinFv(o)->sound = 3;
    getOverwriteAttackData__8grMadeinFv(o)->flag = 0;

    setSleepAttack__10grYakumonoFb(o, true);

    if (enabled) {
        createSoundWork__9grGimmickFUlUl(o, 7, 1);

        Vec2 l0, v0, v1, v2, v3, v4, v5, v6;
        Vec2 l6, l5, l4, l3, l2, l1;

        v0.x = lbl_69_rodata_8C;
        v0.y = lbl_69_rodata_8C;
        *(IntPair*)&l0 = *(IntPair*)&v0;
        o->work->sound[0].id = 0x1CEF;
        o->work->sound[0].a = 0;
        o->work->sound[0].c = 0;
        o->work->sound[0].b = 0;
        o->work->sound[0].pos = l0;

        v1.x = lbl_69_rodata_8C;
        v1.y = lbl_69_rodata_8C;
        *(IntPair*)&l1 = *(IntPair*)&v1;
        o->work->sound[1].id = 0x1CEE;
        o->work->sound[1].a = 0;
        o->work->sound[1].c = 0;
        o->work->sound[1].b = 0;
        o->work->sound[1].pos = l1;

        v2.x = lbl_69_rodata_8C;
        v2.y = lbl_69_rodata_8C;
        *(IntPair*)&l2 = *(IntPair*)&v2;
        o->work->sound[2].id = 0x1CEA;
        o->work->sound[2].a = 0;
        o->work->sound[2].c = 0;
        o->work->sound[2].b = 0;
        o->work->sound[2].pos = l2;

        v3.x = lbl_69_rodata_8C;
        v3.y = lbl_69_rodata_8C;
        *(IntPair*)&l3 = *(IntPair*)&v3;
        o->work->sound[3].id = 0x1CEB;
        o->work->sound[3].a = 0;
        o->work->sound[3].c = 0;
        o->work->sound[3].b = 0;
        o->work->sound[3].pos = l3;

        v4.x = lbl_69_rodata_8C;
        v4.y = lbl_69_rodata_8C;
        *(IntPair*)&l4 = *(IntPair*)&v4;
        o->work->sound[4].id = 0x1CEC;
        o->work->sound[4].a = 0;
        o->work->sound[4].c = 0;
        o->work->sound[4].b = 0;
        o->work->sound[4].pos = l4;

        v5.x = lbl_69_rodata_8C;
        v5.y = lbl_69_rodata_8C;
        *(IntPair*)&l5 = *(IntPair*)&v5;
        o->work->sound[5].id = 0x1CE9;
        o->work->sound[5].a = 0;
        o->work->sound[5].c = 0;
        o->work->sound[5].b = 0;
        o->work->sound[5].pos = l5;

        v6.x = lbl_69_rodata_8C;
        v6.y = lbl_69_rodata_8C;
        *(IntPair*)&l6 = *(IntPair*)&v6;
        o->work->sound[6].id = 0x1CED;
        o->work->sound[6].a = 0;
        o->work->sound[6].c = 0;
        o->work->sound[6].b = 0;
        o->work->sound[6].pos = l6;

        fn_27_27C150(o, 4);
        fn_27_27C1E8(o, 0, evA, 0x1A);
        fn_27_27C1E8(o, 1, evB, 0x22);
        fn_27_27C1E8(o, 2, evC, 0x24);
        fn_27_27C1E8(o, 3, evD, 2);
    }
}

#pragma pop
