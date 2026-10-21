#pragma force_active on
extern "C" void endEffect__5ecMgrFUl(void*, unsigned long);
extern void* g_ecMgr;
extern const float lbl_27_rodata_4388;

struct Vec2f {
    float x, y;

    Vec2f(float a, float b) : x(a), y(b) {}
};

struct EffectInfo {
    short state;
    short pad2;
    float frames;
    int handle;
    char padC[0xE];
    short generator;
    Vec2f offset;
    float scale;
};

struct Gimmick {
    char pad[0xB0];
    EffectInfo* effects;
};

extern "C" void stopGimmickEffect__9grGimmickFUl(
    Gimmick* self, unsigned long index)
{
    if (self->effects[index].handle >= 0) {
        endEffect__5ecMgrFUl(g_ecMgr, self->effects[index].handle);

        EffectInfo& effect = self->effects[index];
        effect.state = 0;
        effect.frames = lbl_27_rodata_4388;
        effect.handle = -1;
        effect.generator = 0;
        effect.offset = Vec2f(lbl_27_rodata_4388, lbl_27_rodata_4388);
    }
}
