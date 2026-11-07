#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_78_28B4();
    virtual void fn_78_290C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_78_2BF0();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_78_26A4();
    virtual void startup();
    virtual void setNode();
    virtual void fn_78_58C();
    virtual void fn_78_1C40();
    virtual void fn_78_26A0();
    virtual void fn_78_1760();
    virtual void fn_78_2698();
    virtual void fn_78_268C();
    virtual void fn_78_267C();
    virtual void fn_78_266C();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f*, unsigned long, unsigned long);
};

struct Obj : public Ground {
    char pad40[0xc4 - 0x40];
    unsigned long nodeIdx;
    char padC8[0x154 - 0xc8];
    float f154;
    char pad158[0xc];
    float f164;
    char pad168[4];
    float f16c;
    unsigned char b170;
    char pad171[3];
    float f174;
    float f178;
    unsigned char b17c;
    unsigned char b17d;
};

extern void* g_ecMgr;
extern "C" void setEffect__5ecMgrF4EfIDP5Vec3f(void*, int, Vec3f*);
extern "C" void startGimmickSE__9grGimmickFUl(void*, unsigned long);

extern "C" void fn_78_2980(Obj* o, float dt) {
    float a = o->f154 - dt;
    o->f154 = a;
    if (a < 0.0f) o->f154 = 0.0f;
    if (o->f174 < -7.0f) o->f174 = -7.0f;
    float d = o->f174 - o->f164;
    o->f178 = o->f174;
    float v = 0.02f + o->f16c;
    float r = nw4r::ut::Abs(d) / 7.0f;
    if (d < 0.0f) v -= 0.5f * r;
    else v += 0.5f * r;
    v -= 0.02f;
    v *= 0.95f;
    if (v > 2.0f) v = 2.0f;
    else if (v < -2.0f) v = -2.0f;
    if (nw4r::ut::Abs(o->f164) - o->f178 < 0.2f && nw4r::ut::Abs(v) < 0.2f) {
        o->f164 = o->f178;
        o->f16c = 0.0f;
    } else {
        o->f16c = v;
        o->f164 = o->f164 + v;
        if (o->f164 > 7.0f) o->f164 = 7.0f;
        else if (o->f164 < -7.0f) o->f164 = -7.0f;
    }
    if (o->b17c != o->b17d || o->b170 == 1) {
        Vec3f pos;
        o->getNodePosition(&pos, 0, o->nodeIdx);
        setEffect__5ecMgrF4EfIDP5Vec3f(g_ecMgr, 0x5d0001, &pos);
        startGimmickSE__9grGimmickFUl(o, 0);
    }
    o->f174 = 0.0f;
    o->b17d = o->b17c;
    o->b17c = 0;
    o->b170 = 0;
}
