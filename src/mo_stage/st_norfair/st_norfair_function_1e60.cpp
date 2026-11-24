#include <types.h>
#include <gr/gr_tengan_event.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct NorfairDangerPositions {
    Vec2f first;
    Vec2f second;
};

struct NorfairGroundCopy {
    Vec3f center;
    float padding;
};

struct NorfairPlayerPosition {
    Vec3f position;
    float padding;
};

struct NorfairItemPair {
    unsigned long id;
    unsigned long value;
    NorfairItemPair(unsigned long a, unsigned long b) : id(a), value(b) {}
};

extern "C" {
extern const float lbl_54_rodata_0[];
float randf__Fv();
long randi__Fl(long);
extern void* g_GameGlobal;
extern void* g_ecMgr;
extern void* g_sndSystem;
extern void* g_aiMgr;
extern void* g_gfSceneRoot;
extern void* lbl_27_bss_5668;
void setDrawPrio__5ecMgrFi(void*, int);
unsigned long setEffect__5ecMgrF4EfID(void*, int);
void setPos__5ecMgrFUlP5Vec3f(void*, unsigned long, Vec3f*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void* getGround__5StageFi(void*, int);
void getPos__9grGimmickFv(Vec3f*, void*);
void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
void startEntity__8grMadeinFv(void*);
void endEntity__8grMadeinFv(void*);
int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(void*, Vec2f*, Vec2f*, int, bool, bool);
void fn_27_1F299C(void*, int);
void cmReqQuake__FiP5Vec3f(int, Vec3f*);
void cmRemoveQuake__Fi(int);
void fn_8009E090(float);
unsigned int fn_8004E96C(void*);
unsigned int getPlayerPosition__7stMeleeFiP5Vec3f(int, Vec3f*);
void* getInstance__9itManagerFv();
void fn_27_2AA7AC(void*, NorfairItemPair, int, Vec3f*, int, int, int);
void setCurrentFrame__11gfSceneRootFf(void*, float);
}

struct NorfairStageBase { char pad[0x3c]; };

#define NR_V8(p) \
    virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); \
    virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();

class NorfairStage : public NorfairStageBase {
public:
    NR_V8(a) NR_V8(b) NR_V8(c) NR_V8(d) NR_V8(e) NR_V8(f) NR_V8(g) NR_V8(h) NR_V8(i) NR_V8(j)
    virtual float getTime();
};

struct NorfairParams {
    float probabilityScale;
    float timeLimit;
};

struct NorfairEventData {
    float minimum;
    float maximum;
    float weights[4];
};

class NorfairEventSource {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual NorfairEventData* slot3(int index);
    virtual void slot4();
    virtual void slot5();
    virtual float slot6();
};

#define NR_EVENT(off) reinterpret_cast<grTenganEvent*>(self + (off))

extern "C" void fn_54_1E60(NorfairStage* stage, float delta)
{
    unsigned char* self = reinterpret_cast<unsigned char*>(stage);
    const float* constants = lbl_54_rodata_0;
    NorfairGroundCopy saved;
    NorfairDangerPositions bounds;
    NorfairPlayerPosition player;
    Vec3f itemPos;
    Vec3f itemQuake;
    Vec3f groundPos;
    Vec3f quake;
    grTenganEvent* ev;
    Vec3f* pos;
    unsigned char* a;
    int* dp;
    NorfairParams* params = *reinterpret_cast<NorfairParams**>(self + 0x9c);
    if (params == 0)
        return;

    *reinterpret_cast<float*>(self + 0x794) += delta;
    NorfairEventSource* source = *reinterpret_cast<NorfairEventSource**>(self + 0x82c);
    NorfairEventData* data = source->slot3(self[0x79a]);
    if (data == 0) {
        self[0x79a] = 1;
        *reinterpret_cast<float*>(self + 0x794) = constants[0];
        *reinterpret_cast<float*>(self + 0x790) = constants[0];
        return;
    }

    switch (self[0x78d]) {
    case 0: {
        float random = randf__Fv();
        float maximum = data->maximum;
        float minimum = data->minimum;
        float range = maximum - minimum;
        self[0x78d] = 1;
        random = range * random;
        *reinterpret_cast<float*>(self + 0x790) += minimum + random;
        break;
    }
    case 1:
        if (*reinterpret_cast<float*>(self + 0x794) >= *reinterpret_cast<float*>(self + 0x790)) {
            if (self[0x798] != 0 && NR_EVENT(0x61c)->isEvent())
                NR_EVENT(0x61c)->end();

            unsigned char* gameInfo =
                *reinterpret_cast<unsigned char**>(static_cast<char*>(g_GameGlobal) + 8);
            if (gameInfo == 0)
                return;

            unsigned int delay = 0;
            switch ((gameInfo[9] >> 5) & 7) {
            case 0:
                if (constants[0] != stage->getTime() && stage->getTime() < params->timeLimit) {
                    delay = 1;
                    *reinterpret_cast<float*>(self + 0x794) = constants[0];
                }
                break;
            }

            if (delay != 1) {
                float a = data->weights[0];
                float b = data->weights[1];
                float c = data->weights[2];
                float d = data->weights[3];

                switch (self[0x799]) {
                case 1: a *= params->probabilityScale; break;
                case 2: b *= params->probabilityScale; break;
                case 3: c *= params->probabilityScale; break;
                case 4: d *= params->probabilityScale; break;
                }

                float total = d + (c + (a + b));
                a /= total;
                b /= total;
                c /= total;
                d /= total;
                float r = randf__Fv();

                if (r < a)
                    self[0x798] = 1;
                else if (r < a + b)
                    self[0x798] = 2;
                else if (r < c + (a + b))
                    self[0x798] = 3;
                else if (r < d + (c + (a + b)))
                    self[0x798] = 4;
                else
                    self[0x798] = 0;

                unsigned char selected = self[0x798];
                self[0x799] = selected;
                self[0x79a] = self[0x79a] + 1;
                self[0x78d] = 0;

                switch (selected) {
                case 3: {
                    NR_EVENT(0x570)->end();
                    NR_EVENT(0x570)->start();
                    int count = randi__Fl(5) + 1;
                    if (count >= 5)
                        count = 5;
                    for (int k = 0; k < count; ++k) {
                        int idx = randi__Fl(5);
                        if (idx >= 4)
                            idx = 4;
                        reinterpret_cast<grTenganEvent*>(self + 0xAC * idx + 0x214)->start();
                    }
                    break;
                }
                case 1:
                    NR_EVENT(0x570)->end();
                    NR_EVENT(0x570)->start();
                    NR_EVENT(0x61c)->end();
                    NR_EVENT(0x61c)->start();
                    NR_EVENT(0x61c)->setPhase(0);
                    break;
                case 2:
                    NR_EVENT(0x570)->end();
                    NR_EVENT(0x570)->start();
                    NR_EVENT(0x61c)->end();
                    NR_EVENT(0x61c)->start();
                    NR_EVENT(0x61c)->setPhase(10);
                    break;
                case 4: {
                    float choice = randf__Fv();
                    if (choice < constants[19])
                        self[0x7ec] = 0;
                    else if (choice < constants[20])
                        self[0x7ec] = 2;
                    else
                        self[0x7ec] = 4;
                    NR_EVENT(0x6c8)->end();
                    NR_EVENT(0x6c8)->start();
                    self[0x830] = 0;
                    self[0x78c] = 1;
                    break;
                }
                }
            }
        }
        break;
    }

    ev = NR_EVENT(0x214);
    a = self;
    pos = reinterpret_cast<Vec3f*>(self + 0x1d8);
    dp = reinterpret_cast<int*>(self);

    for (int i = 0; i < 5; ++i) {
        ev->update(delta);
        if (ev->isReadyEnd() == 1) {
            switch (ev->getPhase()) {
            case 0: {
                setDrawPrio__5ecMgrFi(g_ecMgr, 1);
                unsigned long effect = setEffect__5ecMgrF4EfID(g_ecMgr, 0x3c0001);
                setDrawPrio__5ecMgrFi(g_ecMgr, -1);
                setPos__5ecMgrFUlP5Vec3f(g_ecMgr, effect, pos);
                ev->setPhase(1);
                *reinterpret_cast<float*>(a + 0x224) = constants[0];
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1bc7, 0, 0, 0, -1);

                getPos__9grGimmickFv(&groundPos, getGround__5StageFi(stage, i + 10));
                saved.center = groundPos;
                bounds.first.m_x = saved.center.m_x - constants[11];
                bounds.first.m_y = constants[7] + saved.center.m_y;
                bounds.second.m_x = constants[11] + saved.center.m_x;
                bounds.second.m_y = saved.center.m_y - constants[18];
                dp[525] = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
                    g_aiMgr, &bounds.first, &bounds.second, dp[525], false, false);
                break;
            }
            case 1: {
                float t = *reinterpret_cast<float*>(a + 0x224) + delta;
                *reinterpret_cast<float*>(a + 0x224) = t;
                if (t > constants[21]) {
                    *reinterpret_cast<float*>(a + 0x224) = constants[0];
                    ev->setPhase(2);
                    startEntity__8grMadeinFv(getGround__5StageFi(stage, i + 10));
                }
                break;
            }
            case 2: {
                float t = *reinterpret_cast<float*>(a + 0x224) + delta;
                *reinterpret_cast<float*>(a + 0x224) = t;
                if (t > constants[13]) {
                    ev->end();
                    endEntity__8grMadeinFv(getGround__5StageFi(stage, i + 10));
                    if (dp[525] != -1)
                        fn_27_1F299C(g_aiMgr, dp[525]);
                    dp[525] = -1;
                }
                break;
            }
            }
        }
        ++ev;
        ++pos;
        a += 0xAC;
        ++dp;
    }

    switch (self[0x798]) {
    case 1:
    case 2:
    case 3:
        NR_EVENT(0x570)->update(delta);
        if (NR_EVENT(0x570)->isEvent()) {
            if (NR_EVENT(0x570)->isReadyEnd() == 1) {
                cmRemoveQuake__Fi(1);
                NR_EVENT(0x570)->end();
            } else if (NR_EVENT(0x570)->m_framesElapsed >= constants[18]) {
                quake.m_x = constants[0];
                quake.m_y = constants[0];
                quake.m_z = constants[0];
                cmReqQuake__FiP5Vec3f(1, &quake);
            }
        }
        break;
    case 4:
        break;
    }

    NR_EVENT(0x61c)->update(delta);
    NR_EVENT(0x6c8)->update(delta);

    if (NR_EVENT(0x6c8)->isEvent()) {
        switch (NR_EVENT(0x6c8)->getPhase()) {
        case 0: {
            itemQuake.m_x = constants[0];
            itemQuake.m_y = constants[0];
            itemQuake.m_z = constants[0];
            cmReqQuake__FiP5Vec3f(1, &itemQuake);
            fn_8009E090(constants[3]);
            NR_EVENT(0x6c8)->m_manualFramesLeft += delta;

            if (fn_8004E96C(g_GameGlobal) == 1 &&
                NR_EVENT(0x6c8)->m_manualFramesLeft >= constants[22]) {
                int j;
                unsigned int spawn = 0;
                for (j = 0; j < 4; ++j) {
                    if (getPlayerPosition__7stMeleeFiP5Vec3f(j, &player.position) == 1) {
                        if (self[0x7ee + j] == 1) {
                            if (self[0x831] == 1 && j == 0)
                                self[0x830] = 1;
                            spawn = 1;
                        } else if (!(player.position.m_y >= constants[18])) {
                            int groundIndex = j + 15;
                            startEntity__8grMadeinFv(getGround__5StageFi(stage, groundIndex));
                            setPos__9grGimmickFP5Vec3f(getGround__5StageFi(stage, groundIndex), &player.position);
                        }
                    }
                }

                unsigned char* gameInfo =
                    *reinterpret_cast<unsigned char**>(static_cast<char*>(g_GameGlobal) + 8);
                if (gameInfo != 0 && static_cast<signed char>(gameInfo[0x16]) == 0)
                    spawn = 0;

                if (spawn == 1) {
                    itemPos = reinterpret_cast<Vec3f*>(self + 0x7b0)[self[0x7ec]];
                    itemPos.m_y += constants[23];

                    void* manager = getInstance__9itManagerFv();
                    unsigned long itemId = *reinterpret_cast<unsigned long*>(
                        static_cast<char*>(lbl_27_bss_5668) + 0x44);
                    fn_27_2AA7AC(manager, NorfairItemPair(itemId, 0), 1, &itemPos, -1, -1, -1);
                }

                NR_EVENT(0x6c8)->setPhase(1);
                self[0x78c] = 3;
            }
            break;
        }
        case 1:
            for (int j = 0; j < 4; ++j) {
                void* ground = getGround__5StageFi(stage, j + 15);
                if (ground != 0)
                    endEntity__8grMadeinFv(ground);
            }
            NR_EVENT(0x6c8)->end();
            break;
        }
    }

    if (NR_EVENT(0x61c)->isEvent() && self[0x798] == 0)
        NR_EVENT(0x61c)->end();

    switch (self[0x78c]) {
    case 0:
        setCurrentFrame__11gfSceneRootFf(g_gfSceneRoot, constants[0]);
        break;
    case 1: {
        float frame = constants[0];
        NorfairEventSource* anm =
            *reinterpret_cast<NorfairEventSource**>(static_cast<char*>(g_gfSceneRoot) + 0x54);
        if (anm != 0)
            frame = anm->slot6();
        if (frame >= constants[24]) {
            setCurrentFrame__11gfSceneRootFf(g_gfSceneRoot, constants[24]);
            self[0x78c] = 2;
        }
        break;
    }
    case 2:
        setCurrentFrame__11gfSceneRootFf(g_gfSceneRoot, constants[24]);
        break;
    case 3: {
        float frame = constants[0];
        NorfairEventSource* anm =
            *reinterpret_cast<NorfairEventSource**>(static_cast<char*>(g_gfSceneRoot) + 0x54);
        if (anm != 0)
            frame = anm->slot6();
        if (frame < constants[24]) {
            setCurrentFrame__11gfSceneRootFf(g_gfSceneRoot, constants[0]);
            self[0x78c] = 0;
        }
        break;
    }
    }
}
