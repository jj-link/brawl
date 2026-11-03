#pragma force_active on
#include <types.h>

struct Message;
struct Vec3f { float x, y, z; };
struct WindowSetting {
    u32 flags;
    float f04, f08, f0C, f10;
    char _14[0x48 - 0x14];
};
struct ResMdl { void* m_dataPtr; };
struct ResNodeData { char pad0[0x38]; Vec3f translation; };
struct ScnMdlSimple { char pad0[0xE8]; void* m_resMdl; };

extern const float lbl_805A2228;
extern const char lbl_8059DF48[8];
extern const char lbl_8059DF50[8];
extern const char lbl_8059DF58[8];

extern "C" int sprintf(char*, const char*, ...);
extern "C" int attachMsgBuf__7MessageFUlPQ34nw4r3g3d12ScnMdlSimplePCcUcif(
    Message*, u32, ScnMdlSimple*, const char*, u8, int, float);
extern "C" void initWindowSetting__5MuMsgFPQ25MuMsg13WindowSetting(void*, WindowSetting*);
extern "C" ResNodeData* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(ResMdl*, const char*);

extern "C" void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
    void* self, u32 msgIndex, ScnMdlSimple* sceneModel, u32 boneTextIndex, float fontSize)
{
    char name[32];
    ResMdl mdl;
    Vec3f p1, p2;

    sprintf(name, lbl_8059DF48, boneTextIndex);
    attachMsgBuf__7MessageFUlPQ34nw4r3g3d12ScnMdlSimplePCcUcif(
        *(Message**)((char*)self + 0x8), msgIndex, sceneModel, name, 0, 3, fontSize);

    WindowSetting* ws = *(WindowSetting**)((char*)self + 0xC) + msgIndex;
    initWindowSetting__5MuMsgFPQ25MuMsg13WindowSetting(self, ws);

    mdl.m_dataPtr = sceneModel->m_resMdl;

    sprintf(name, lbl_8059DF50, boneTextIndex);
    p1 = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&mdl, name)->translation;

    sprintf(name, lbl_8059DF58, boneTextIndex);
    p2 = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&mdl, name)->translation;
    float f = lbl_805A2228 / fontSize;

    ws->f04 = p1.x * f;
    ws->f08 = -p1.y * f;
    ws->f0C = p2.x * f;
    ws->f10 = -p2.y * f;
}
