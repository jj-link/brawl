#pragma force_active on

struct Vec3f;
#include <snd/snd_3d_generator.h>

struct Vec3f {
    float x, y, z;
};

struct Vec2f {
    float x, y;

    Vec2f(float a, float b) : x(a), y(b) {}
};

struct SEInfo {
    short state;
    short pad2;
    float frames;
    int handle;
    unsigned int sndId;
    char pad10[8];
    unsigned short unk18;
    unsigned short generator;
    Vec2f offset;
    float scale;
};

struct GimmickPos {
    int unk0;
    unsigned int flags;
    Vec3f pos;
    char pad14[0x48];
    float prevX;
    char pad60[0xC];
    float prevY;
    char pad70[0xC];
    float prevZ;
    void updatePos() {
        if (flags & 8) {
            float z = prevZ;
            float y = prevY;
            float x = prevX;
            setPos(z, y, x);
        }
    }
    void setPos(float z, float y, float x) {
        pos.x = x;
        pos.y = y;
        pos.z = z;
    }
};

struct Ground_base {
    int unk0;
    char pad4[0x38];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void slot3();
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
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void slot25();
    virtual void setupMelee();
    virtual void slot27();
    virtual void setVisibilityByClipping();
    virtual void slot29();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void slot37();
    virtual void slot38();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix(float (*mtx)[4], unsigned long unk, unsigned long node);
};

class grGimmick : public Ground {
public:
    char pad40[0x60];
    snd3DGenerator* generators;
    char padA4[4];
    SEInfo* sounds;
    char padAC[0x28];
    GimmickPos* unkD4;
};

extern "C" {
void stopSE__14snd3DGeneratorFll(snd3DGenerator*, int, int);
int prepareSE__14snd3DGeneratorF5SndIDl(snd3DGenerator*, unsigned int, int);
void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);
int fn_800797A4(snd3DGenerator*, int);
void OSReport(const char*, ...);
}

extern const float lbl_27_rodata_4388;
extern char lbl_27_data_568B0[];

inline void updateSoundPos(grGimmick* self, unsigned long index)
{
        if (self->sounds[(int)index].sndId != -1) {
            unsigned short node = self->sounds[(int)index].unk18;
            if (node == 0) {
                Vec3f pos;
                GimmickPos* p = self->unkD4;

                if (p != 0) {
                    p->updatePos();
                    __memcpy(&pos, &self->unkD4->pos, sizeof(pos));
                } else {
                    pos.x = lbl_27_rodata_4388;
                    pos.y = lbl_27_rodata_4388;
                    pos.z = lbl_27_rodata_4388;
                }

                setPos__14snd3DGeneratorFP5Vec3f(
                    self->generators + self->sounds[(int)index].generator,
                    &pos);
            } else {
                float mtx[3][4];
                self->getNodeMatrix(mtx, 0, node);

                Vec3f pos;
                float z = mtx[2][3];
                float y = mtx[1][3];
                float x = mtx[0][3];
                pos.y = y;
                pos.x = x;
                pos.z = z;

                setPos__14snd3DGeneratorFP5Vec3f(
                    self->generators + self->sounds[(int)index].generator,
                    &pos);
            }
        }
}

extern "C" void startGimmickSE__9grGimmickFUl(grGimmick* self, unsigned long index)
{
    if (self->sounds[index].sndId != -1) {
        if (self->sounds[index].handle != -1 &&
            fn_800797A4(
                self->generators + self->sounds[index].generator,
                self->sounds[index].handle) != 0) {
            if (self->sounds[(int)index].handle >= 0) {
                stopSE__14snd3DGeneratorFll(
                    self->generators + self->sounds[(int)index].generator,
                    self->sounds[(int)index].handle,
                    0);

                SEInfo& sound = self->sounds[(int)index];
                sound.state = 0;
                sound.frames = lbl_27_rodata_4388;
                sound.handle = -1;
                sound.generator = 0;
                sound.offset = Vec2f(lbl_27_rodata_4388, lbl_27_rodata_4388);
            }
        }

        self->sounds[index].state = 1;
        self->sounds[index].frames = lbl_27_rodata_4388;
        self->sounds[index].handle = prepareSE__14snd3DGeneratorF5SndIDl(
            self->generators + self->sounds[index].generator,
            self->sounds[index].sndId,
            -1);

        if (self->sounds[index].handle == -1) {
            self->sounds[index].state = 0;
            OSReport(lbl_27_data_568B0, self->sounds[index].sndId, self->unk0);
            return;
        }

        updateSoundPos(self, index);
    }
}
