#include <types.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <revolution/GX/GXTexture.h>
#include <gf/gf_copyefb.h>
#include <ec/ec_mgr.h>
#pragma force_active on

struct RawAccess {
    u8 data[0x34];
};

extern "C" {
extern char* lbl_8059DAF0;
extern char lbl_8059DAF8[3];
extern const f32 lbl_805A1970;

void fn_80064920(
    nw4r::g3d::ScnMdl**, s32, s32, s32*, u32, u32, u32, u32,
    u32, u32, u32, u32);

void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
    void*, nw4r::g3d::ScnMdl*, u32);

void* fn_8018D3F0(void*, const char*);
u32 fn_8018F394(void*);
void* fn_8018F340(void*, s32);
void* fn_8018F2EC(void*, u32);
void* fn_801B00FC(void*);

s32 fn_8018E3C0(void*);
void* fn_8018D6D8(void*, u32);
s32 fn_8018E40C(void*);
void* fn_8018D8E0(void*, u32);
s32 fn_8018E458(void*);
void* fn_8018DAE8(void*, u32);
s32 fn_8018E4A4(void*);
void* fn_8018DCF0(void*, u32);
s32 fn_8018E4F0(void*);
void* fn_8018DEF8(void*, u32);
s32 fn_8018E53C(void*);
void* fn_8018E100(void*, u32);

int strcmp(const char*, const char*);
}

struct TexPlttInfoData {
    s32 nameTex;
    char pad[0x30];
};

struct MatData {
    char pad0[0xC];
    u32 id;
    char pad1[0x1C];
    u32 numTexPlttInfo;
    s32 toTexPlttInfo;
};

template <class T>
class Res {
public:
    T* mpData;
    Res(void* p) : mpData((T*)p) {}
    T& ref() const { return *mpData; }
    template <class U>
    U* ofs_to_ptr(s32 ofs) const
    {
        u8* p = (u8*)mpData;
        if (ofs != 0)
            return (U*)(p + ofs);
        return 0;
    }
};

class TexPlttInfo : public Res<TexPlttInfoData> {
public:
    TexPlttInfo(void* p) : Res<TexPlttInfoData>(p) {}
    const char* GetTexName() const { return ofs_to_ptr<char>(ref().nameTex); }
};

class Mat : public Res<MatData> {
public:
    Mat(void* p) : Res<MatData>(p) {}
    u32 GetNumResTexPlttInfo() const { return ref().numTexPlttInfo; }
    TexPlttInfo GetResTexPlttInfo(u32 idx) const
    {
        TexPlttInfoData* pData = ofs_to_ptr<TexPlttInfoData>(ref().toTexPlttInfo);
        return TexPlttInfo(&pData[idx]);
    }
};

inline bool sameName(const char* a, const char* b)
{
    return strcmp(a, b) == 0;
}

inline f32 animationFrame(f32 value, const void* anim)
{
    if (anim == 0)
        return value;
    return lbl_805A1970;
}

extern "C" void fn_80064398(
    void* arg0,
    nw4r::g3d::ScnMdl** arg1,
    s32 arg2,
    s32 arg3,
    s32* arg4,
    u32 arg5,
    u32 arg6,
    u32 arg7,
    u32 arg8,
    u32 arg9,
    u32 arg10,
    u32 arg11,
    u32 arg12)
{
    u8* base = (u8*)arg0;
    u8* resources = *(u8**)(base + 4);
    if (resources == 0)
        return;

    u8* entry = *(u8**)(base + 0xC) + arg5 * 0x10;
    s16 index = *(s16*)(entry + 0x10);
    if (index < 0)
        return;

    fn_80064920(
        arg1, arg2, arg3, (s32*)(resources + *(s16*)(entry + 0x12) * 4),
        arg7, arg8, arg9, arg10, arg11, arg12,
        arg6, *(u32*)(g_ecMgr->unk40 + 8));

    if (*arg1 == 0)
        return;

    if (*(u32*)(base + 8) != 0) {
        if (fn_8018D3F0(*(void**)(base + 8), lbl_8059DAF8) != 0) {
            GXTexObj saved;
            u32 valid = gfCopyEFBMgr::getInstance()->isValid(1);
            if (valid == 1) {
                saved = *gfCopyEFBMgr::getInstance()->getCopyEFBTex(1);
            }

            if (valid != 0) {
                u32 modelResource = *(u32*)((u8*)*arg1 + 0xE8);
                char* name;
                s32 materialCount = (s32)fn_8018F394(&modelResource) - 1;
                name = lbl_8059DAF0;

                while (materialCount >= 0) {
                    Mat mat(fn_8018F340(&modelResource, materialCount));
                    for (s32 texCount = mat.GetNumResTexPlttInfo() - 1; texCount >= 0; --texCount) {
                        TexPlttInfo info = mat.GetResTexPlttInfo(texCount);

                        if (strcmp(info.GetTexName(), lbl_8059DAF8) == 0) {
                            u32 matID = mat.mpData->id;
                            RawAccess access;
                            __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
                                &access, *arg1, matID);
                            nw4r::g3d::ResTexObj resTexObj((void*)0);

                            if (sameName(name, name)) {
                                RawAccess access2;
                                __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
                                    &access2, *arg1, matID);
                                resTexObj = nw4r::g3d::ResTexObj(fn_801B00FC(&access2));
                            } else {
                                resTexObj = nw4r::g3d::ResTexObj(
                                    (u8*)fn_8018F2EC(&modelResource, matID) + 0x3C);
                            }

                            if (resTexObj.IsValid()) {
                                GXTexObj* dest = resTexObj.GetTexObj((GXTexMapID)texCount);
                                *dest = saved;
                            }
                        }
                    }
                    --materialCount;
                }
            }
        }
    }

    f32 value;
    u8* anim = entry;

    if (fn_8018E3C0((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4) &&
        ((nw4r::g3d::ResFile*)((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4))->GetResAnmChrNumEntries() > arg7) {
        anim = (u8*)fn_8018D6D8(
            (*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4, arg7);
        value = (f32)(s32)*(u16*)(anim + 0x1C);
        anim = (u8*)*(u32*)(anim + 0x20);
    } else if (fn_8018E40C((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4) &&
               ((nw4r::g3d::ResFile*)((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4))->GetResAnmVisNumEntries() > arg8) {
        anim = (u8*)fn_8018D8E0(
            (*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4, arg8);
        value = (f32)(s32)*(u16*)(anim + 0x1C);
        anim = (u8*)*(u32*)(anim + 0x20);
    } else if (fn_8018E458((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4) &&
               ((nw4r::g3d::ResFile*)((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4))->GetResAnmClrNumEntries() > arg11) {
        anim = (u8*)fn_8018DAE8(
            (*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4, arg11);
        value = (f32)(s32)*(u16*)(anim + 0x1C);
        anim = (u8*)*(u32*)(anim + 0x20);
    } else if (fn_8018E4A4((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4) &&
               ((nw4r::g3d::ResFile*)((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4))->GetResAnmTexPatNumEntries() > arg9) {
        anim = (u8*)fn_8018DCF0(
            (*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4, arg9);
        value = (f32)(s32)*(u16*)(anim + 0x2C);
        anim = (u8*)*(u32*)(anim + 0x34);
    } else if (fn_8018E4F0((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4) &&
               ((nw4r::g3d::ResFile*)((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4))->GetResAnmTexSrtNumEntries() > arg10) {
        anim = (u8*)fn_8018DEF8(
            (*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4, arg10);
        value = (f32)(s32)*(u16*)(anim + 0x1C);
        anim = (u8*)*(u32*)(anim + 0x24);
    } else if (fn_8018E53C((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4) &&
               ((nw4r::g3d::ResFile*)((*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4))->GetResAnmShpNumEntries() > arg12) {
        anim = (u8*)fn_8018E100(
            (*(u8**)(base + 4)) + *(s16*)(entry + 0x12) * 4, arg12);
        value = (f32)(s32)*(u16*)(anim + 0x20);
        anim = (u8*)*(u32*)(anim + 0x24);
    }

    *arg4 = (s32)animationFrame(value, anim);
}
