#include <types.h>
#include <gf/gf_pad_system.h>
#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#include <ty/ty_fig_listmng.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

class VObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void* vf12(void* out, s32 flag);
    virtual void vf13(void* p);
};

struct AnimResult {
    u32 flags;
    nw4r::g3d::ResTex tex[8];
    nw4r::g3d::ResTex pal[8];
};

struct Rec1C {
    char pad0[0x1C];
    u16 w;
    u16 h;
};

struct Wrap {
    char pad0[4];
    Rec1C* rec;
};

struct Mid {
    char pad0[0x10];
    VObj* unk10;
};

struct Node {
    char pad0[0xC];
    void* unkC;
    char pad1[4];
    Mid* unk14;
};

struct SlotRec {
    s32 u0;
    s32 kind;
    s32 v8;
    s32 vC;
    u32 p10;
    u32 p14;
    s32 u18;
    s32 kind1c;
    s32 v20;
    s32 u24;
};

struct FigSelf {
    char unk0[0xF4];
    s32 unkF4;
    char unkF8[0xC];
    MuObject* unk104;
    char unk108[0xC];
    MuObject* unk114;
    char unk118[0x34];
    MuObject* unk14C;
    Node* unk150;
    Node* unk154;
    Node* unk158;
    Node* unk15C;
    Node* unk160;
    char unk164[0xB64 - 0x164];
    VObj* unkB64;
    char unkB68[8];
    void* unkB70;
    char unkB74[0xD78 - 0xB74];
    MuMsg* unkD78;
    s32 unkD7C;
    s32 unkD80[0x41];
    SlotRec* unkE84;
    s32 unkE88;
    s32 unkE8C[0x80];
    tyFigListDataManager* unk108C;
    s32 unk1090;
    s32 unk1094;
};

extern "C" {
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
void fn_800B6E08(void* obj, float* vec);
void fn_800B7AA4(void* obj, s32 mode, float value);
void fn_800B7224(void* obj, void* mat, char* name, void* tex);
void* fn_8018D3F0(void* table, char* name);
s32 fn_8004E7A0(s32 g, s32 zero, u8 idx);
s32 fn_8004E7EC(s32 g);
s32 fn_8004E7C8(s32 g);
u32* fn_8004E580(s32 g);
u32* fn_8004E594(s32 g);

extern char lbl_8059E0B0[6];
extern char lbl_8059E0B8[2];
extern char lbl_80456AD8[];
extern s32 g_GameGlobal;
extern float lbl_805A2248;
extern float lbl_805A2258;
extern float lbl_805A2264;
extern float lbl_805A2268;
extern float lbl_805A226C;
extern float lbl_805A2270;
}

extern "C" void fn_800BCA9C(FigSelf* self, s32 arg1)
{
    u16 id;
    s32 figIdx;
    MuObject* o;
    SlotRec* rec2;
    Rec1C* fd;
    void* tab;
    float vA[3];
    float vB[3];
    char name[0x20];
    gfPadStatus pad;

    s32 idx = self->unk1094 + (self->unk1090 << 2);
    SlotRec* rec = self->unkE84 + idx;
    if (arg1 == 3) {
        arg1 = self->unkE8C[idx];
    }

    self->unkB64->vf13(self->unkB70);
    {
        u32 i = 0x14;
        char* p = (char*)self + 0x50;
        do {
            self->unkB64->vf13(((Node*)*(void**)(p + 0x100))->unkC);
            i++;
            p += 4;
        } while (i <= 0x18);
    }

    if (arg1 == 2) {
        switch (rec->kind) {
        case 0: {
            VObj* obj;
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->unkB64, self->unk150->unkC, lbl_8059E0B0);
            fn_800B7AA4(self->unk150, 4, (float)rec->v8);
            obj = self->unk150->unk14->unk10;
            AnimResult buf80;
            Wrap* w = (Wrap*)obj->vf12(&buf80, 0);
            Rec1C* r = w->rec;
            vA[0] = lbl_805A2258 * (float)r->w;
            vA[1] = lbl_805A2258 * (float)r->h;
            vA[2] = lbl_805A2264;
            fn_800B6E08(self->unk150, vA);
            fn_800B7AA4(self->unk104, 2, lbl_805A2248);
            break;
        }
        case 1: {
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->unkB64, self->unkB70, lbl_8059E0B0);
            id = (u16)rec->v8;
            figIdx = self->unk108C->getBilTexFileIdxFigId(id);
            self->unk108C->getBilTexNameFigId(id, name);
            tab = &self->unkD80[figIdx];
            fd = (Rec1C*)fn_8018D3F0(tab, name);
            if (fd != NULL) {
                o = self->unk14C;
                nw4r::g3d::ResMat mat = o->m_resMdl.GetResMat(lbl_80456AD8);
                fn_800B7224(o, *(void**)((char*)mat.ptr() + 0xC), name, tab);
                vB[0] = lbl_805A2258 * (float)fd->w;
                vB[1] = lbl_805A2258 * (float)fd->h;
                vB[2] = lbl_805A2264;
                tyFigListData* d = self->unk108C->getFigDataId((u32)id);
                vB[0] = vB[0] * *(float*)((char*)d + 0x58);
                vB[1] = vB[1] * *(float*)((char*)d + 0x5C);
                fn_800B6E08(self->unk14C, vB);
            }
            fn_800B7AA4(self->unk104, 2, lbl_805A2248);
            break;
        }
        case 2: {
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->unkB64, self->unk154->unkC, lbl_8059E0B0);
            g_gfPadSystem->getSysPadStatus(self->unkF4, &pad);
            MuObject* padObj = self->unk104;
            float f;
            if (pad.m_error != 0) {
                f = lbl_805A2248;
            } else {
                switch (pad.m_controllerType) {
                case 0: f = lbl_805A2264; break;
                case 1: f = lbl_805A2268; break;
                case 2: f = lbl_805A226C; break;
                case 3: f = lbl_805A2270; break;
                default: f = lbl_805A2264; break;
                }
            }
            if (f >= lbl_805A2248) {
                fn_800B7AA4(padObj, 2, f);
            }
            rec2 = self->unkE84 + (self->unk1094 + (self->unk1090 << 2));
            s32 bgmId = g_sndSystem->getBGMId();
            if (bgmId == rec2->v8) {
                self->unk104->setFrameTex(lbl_805A2264);
            } else {
                self->unk104->setFrameTex(lbl_805A2248);
            }
            break;
        }
        case 3:
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->unkB64, self->unk158->unkC, lbl_8059E0B0);
            fn_800B7AA4(self->unk104, 2, lbl_805A2248);
            break;
        case 4:
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->unkB64, self->unk15C->unkC, lbl_8059E0B0);
            fn_800B7AA4(self->unk104, 2, lbl_805A2248);
            break;
        case 5:
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->unkB64, self->unk160->unkC, lbl_8059E0B0);
            fn_800B7AA4(self->unk104, 2, lbl_805A2248);
            break;
        default:
            break;
        }
    } else {
        fn_800B7AA4(self->unk104, 2, lbl_805A2248);
    }

    if (arg1 == 2) {
        self->unk114->setFrameTex(lbl_805A2264 + (float)rec->kind);
    } else {
        self->unk114->setFrameTex(lbl_805A2248);
    }

    u32 r30 = rec->p10;
    switch (rec->kind1c) {
    case 1:
        if (rec->v20 == 0) {
            if (fn_8004E7EC(g_GameGlobal) == 0) {
                r30 = rec->p14;
            }
        } else if (rec->v20 == 1) {
            if (fn_8004E7C8(g_GameGlobal) == 0) {
                r30 = rec->p14;
            }
        }
        break;
    case 2: {
        u32* arr = fn_8004E580(g_GameGlobal);
        s32 n = rec->v20 * 3 + 1;
        if ((arr[n / 32] & (1 << (n % 32))) == 0) {
            r30 = rec->p14;
        }
        break;
    }
    case 3: {
        u32* arr = fn_8004E594(g_GameGlobal);
        s32 n = rec->v20;
        if ((arr[n / 32] & (1 << (n % 32))) == 0) {
            r30 = rec->p14;
        }
        break;
    }
    case 4:
        if (fn_8004E7A0(g_GameGlobal, 0, (u8)(rec->v20 - 1)) == 0) {
            r30 = rec->p14;
        }
        break;
    default:
        break;
    }

    switch (arg1) {
    case 0:
        self->unkD78->setFontColor(0, 0x8e, 0x8e, 0x8d, 0xff);
        self->unkD78->printf(0, lbl_8059E0B8);
        self->unkD78->setFontColor(1, 0x8a, 0x98, 0x8e, 0xff);
        self->unkD78->printf(1, lbl_8059E0B8);
        break;
    case 1:
        self->unkD78->setFontColor(0, 0x8e, 0x8e, 0x8d, 0xff);
        self->unkD78->printf(0, lbl_8059E0B8);
        self->unkD78->setFontColor(1, 0x8a, 0x98, 0x8e, 0xff);
        self->unkD78->printIndex(1, r30, NULL);
        break;
    case 2:
        self->unkD78->setFontColor(0, 0, 0, 0, 0xff);
        self->unkD78->printIndex(0, rec->vC, NULL);
        self->unkD78->setFontColor(1, 0xd9, 0xd9, 0xd9, 0xff);
        self->unkD78->printIndex(1, r30, NULL);
        break;
    default:
        break;
    }
}
