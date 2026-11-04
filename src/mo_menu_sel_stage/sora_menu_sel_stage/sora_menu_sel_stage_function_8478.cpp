#include <gf/gf_heap_manager.h>
#include <types.h>
#pragma force_active on

struct SwObjBase {
    char pad[0x8];
};

class SwObj : public SwObjBase {
public:
    virtual void f00(int flag);
    int unkC;
    int unk10;
};

struct SelStageInner {
    char pad0[0x5C];
    unsigned char unk5C;
    char pad1[0x3];
    int unk60;
    char pad2[0x80];
    void* unkE4;
};

struct SelStageFileTask {
    char pad0[0x40];
    int unk40;
    char pad1[0x24];
    SelStageInner* unk68;
    char pad2[0x324];
    int unk390;
    int unk394;
};

extern "C" {
extern void* g_GameGlobal;
extern unsigned int lbl_11_data_680;
void* fn_80153488(void*);
void fn_80153498(void*, int);
void fn_80153504(void*, void*);
SwObj* fn_80153818(void*, int);
}

extern "C" s32 fn_11_8478(SelStageFileTask* self) {
    SelStageInner* inner = self->unk68;
    void* obj;
    s32 flag;

    if (inner->unk5C == 0) {
        return self->unk40;
    }
    switch (inner->unk60) {
    case 0: {
        obj = operator new(8, (Heaps::HeapType)0x2A);
        if (obj != 0) {
            obj = fn_80153488(obj);
        }
        fn_80153504(obj, inner->unkE4);
        flag = 2;
        SwObj* sw = fn_80153818(obj, 0x2B);
        if (sw != 0) {
            unsigned int* q = (unsigned int*)(sw->unkC + 0x34);
            if (*q == lbl_11_data_680) {
                memcpy(*(void**)((char*)g_GameGlobal + 0x40), q, 0x2470);
                flag = 0;
            }
            if (sw != 0) {
                sw->f00(1);
            }
        }
        fn_80153498(obj, 1);
        gfHeapManager::free(inner->unkE4);
        break;
    }
    case 6:
        flag = 2;
        break;
    case 4:
    default:
        flag = 1;
        break;
    }
    self->unk394 = flag;
    self->unk390 = 0;
    return 5;
}
