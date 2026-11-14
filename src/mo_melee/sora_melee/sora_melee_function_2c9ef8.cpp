#include <types.h>
#include <ec/ec_mgr.h>
#include <gf/gf_3d_scene.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern "C" {
void* fn_800607C8(ecMgr* mgr, u32 key);
void* fn_800F1820(void* a, void* b, void* c, void* d, int e, int f, int g, int h);
void fn_27_2D6974(void* p, int a, int b, int c, int d);
void fn_27_2D6C18(void* p, int a, int b);
extern u8* lbl_27_bss_7328;
extern char lbl_27_data_7B3F0[];
extern char lbl_27_data_7B458[];
extern const float lbl_27_rodata_61E8;
extern const float lbl_27_rodata_61F0;
}

class NullableVtbl {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
};

struct ModelEntry {
    char pad0[0xC];
    NullableVtbl* model;
};

struct Rec {
    char pad0[0x304];
    float first[0x71];
    float second[0x71];
    char tail[0x70C - 0x304 - 0x71 * 8];
};

struct Self {
    char pad000[0x44];
    u8 flag44;
    char pad045[0x674 - 0x045];
    u8 sub674[0x6A6 - 0x674];
    u8 flag6A6;
    char pad6A7[0x4474 - 0x6A7];
    u32 effect4474;
    u32 effect4478;
    char pad447C[0x448C - 0x447C];
    s32 recordIndex;
    char pad4490[0x4494 - 0x4490];
    Rec records[1];
    char pad4BA0[0x1ADBC - 0x4BA0];
    u32 unk1ADBC;
    char pad1ADC0[0x1AF0C - 0x1ADC0];
    ModelEntry** unk1AF0C;
    ModelEntry** unk1AF10;
    ModelEntry** unk1AF14;
    void* unk1AF18;
    u8 sub1AF1C[0x1AF20 - 0x1AF1C];
    u32 unk1AF20;
    nw4r::g3d::ScnMdl* unk1AF24;
    u8 unk1AF28;
    s8 unk1AF29;
    u8 unk1AF2A;
    char pad1AF2B[0x1AF3C - 0x1AF2B];
    u8 sub1AF3C[0x1AFA4 - 0x1AF3C];
    u32 unk1AFA4;
    u32 arr1AFA8[12];
    u32 unk1AFD8;
    u32 unk1AFDC;
    u32 unk1AFE0;
    u32 unk1AFE4;
    u32 unk1AFE8;
    char pad1AFEC[0x1B000 - 0x1AFEC];
    s32 unk1B000;
    char pad1B004[0x1B00C - 0x1B004];
    s32 unk1B00C;
    s32 unk1B010;
};

inline void setOptions(NullableVtbl* m, int v) {
    if (m != NULL) {
        m->slot6(1, v);
        m->slot6(6, v);
        m->slot6(7, v);
    }
}

inline void setModelOpts(ecMgr* mgr, u32 key, int v) {
    NullableVtbl* m = (NullableVtbl*)fn_800607C8(mgr, key);
    setOptions(m, v);
}

inline void setEntryOpts(ModelEntry* e, int v) {
    NullableVtbl* m = e->model;
    setOptions(m, v);
}

inline bool isCounted(int i) {
    switch (i) {
    case 37: case 38: case 39:
    case 70: case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79:
    case 80: case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89:
        return false;
    default:
        return true;
    }
}

extern "C" void fn_27_2C9EF8(Self* self, s32 mode) {
    ecMgr* mgr = g_ecMgr;
    u32 handle;
    NullableVtbl* model;

    self->unk1AF28 = mode;
    switch ((s8)(u8)mode) {
    case 3:
        self->unk1AF2A = 0;
        self->unk1AF29 = 0;
        setModelOpts(mgr, self->unk1ADBC, 1);
        self->unk1AF18 = fn_800F1820(self->sub1AF1C, self->sub674, (void*)self->unk1AF20,
                                     self->unk1AF24, 0x7C, 0x2A, 0x2B, 0xFF);
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->unk1AF24);
        break;
    default:
        switch (mode) {
        case 2:
            self->unk1B000 = 3;
            mgr->setMdlAnmIdx(*(u32*)(lbl_27_bss_7328 + 0x1AF94), 3, 1);
            setModelOpts(mgr, self->unk1AFA4, 0);
            self->unk1AF28 = 2;
            handle = self->unk1AFA4;
            self->unk1B00C = *(s32*)(lbl_27_bss_7328 + 0x4388);
            self->unk1B010 = *(s32*)(lbl_27_bss_7328 + 0x438C);
            self->unk1AF2A = 0;
            break;
        case 1:
            setModelOpts(mgr, self->unk1AFDC, 0);
            if (self->flag44 == 0) {
                setModelOpts(mgr, self->unk1AFE8, 0);
                model = self->unk1AF14[1]->model;
                setOptions(model, 0);
            }
            self->unk1AF28 = 1;
            handle = self->unk1AFDC;
            self->unk1AF2A = 0x10;
            {
                Rec* rec = &self->records[self->recordIndex];
                int count = 0;
                for (int i = 0; i < 0x60; i++) {
                    int valid;
                    if (((int)rec->first[i] != 0 || (int)rec->second[i] != 0) &&
                        (lbl_27_rodata_61E8 != rec->first[i] || isCounted(i))) {
                        valid = 1;
                    } else {
                        valid = 0;
                    }
                    if (valid) {
                        count++;
                    }
                }
                fn_27_2D6974(self->sub1AF3C, count, 8, 1, 0);
                fn_27_2D6C18(self->sub1AF3C, 1, 1);
            }
            break;
        }

        self->unk1AF29 = 1;
        mgr->setMdlAnmIdx(handle, 0, 1);
        mgr->setMdlAnmIdx(handle, 0, 0x10);
        mgr->setMdlEnableUpdate(handle, false, 0x10);
        {
            float frame;
            if (mode == 2) {
                frame = lbl_27_rodata_61F0;
            } else {
                frame = (float)(s8)self->unk1AF29;
            }
            mgr->setMdlFrame(handle, frame, 0x10);
        }

        {
            char* p = (char*)self;
            for (u32 i = 0; i < 12; i++, p += 4) {
                mgr->setParent(*(u32*)(p + 0x1AFA8), handle, lbl_27_data_7B3F0, false);
                setModelOpts(mgr, *(u32*)(p + 0x1AFA8), 1);
            }
        }

        setModelOpts(mgr, self->unk1AFE0, 1);
        setModelOpts(mgr, self->unk1AFE4, 1);

        mgr->setParent(self->unk1AFD8, handle, lbl_27_data_7B3F0, false);
        setModelOpts(mgr, self->unk1AFD8, 0);

        mgr->setParent(self->unk1AFE0, handle, lbl_27_data_7B458, false);
        setModelOpts(mgr, self->effect4474, 1);
        setModelOpts(mgr, self->effect4478, 1);

        if (self->flag6A6 != 0) {
            setEntryOpts(self->unk1AF10[0], 1);
            for (int i = 0; i < 8; i++) {
                setEntryOpts(self->unk1AF0C[i], 1);
            }
        }
        break;
    }
}
