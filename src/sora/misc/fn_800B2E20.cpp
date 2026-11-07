#pragma force_active on
#include <types.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_obj.h>

typedef unsigned char u8;

extern "C" {
extern char lbl_80455D70[];
void __dl__FPv(void*);
}

class Member {
public:
    virtual void f0(int);
};

struct Sub {
    void* unk0;
    u8 unk4;
    u8 pad5[3];
    nw4r::g3d::G3dObj* unk8;
    nw4r::g3d::G3dObj* unkC;
    nw4r::g3d::G3dObj* unk10;
    nw4r::g3d::G3dObj* unk14;
    nw4r::g3d::G3dObj* unk18;
    nw4r::g3d::G3dObj* unk1C;
};

extern "C" void* fn_800B2E20(u8* self, int deleting) {
    if (self) {
        Sub* sub = *reinterpret_cast<Sub**>(self + 0x14);
        *reinterpret_cast<char**>(self + 0x5c) = lbl_80455D70;
        if (sub) {
            if (sub->unkC) {
                sub->unkC->Destroy();
            }
            if (sub->unk8) {
                sub->unk8->Destroy();
            }
            if (sub->unk10) {
                sub->unk10->Destroy();
            }
            if (sub->unk14) {
                sub->unk14->Destroy();
            }
            if (sub->unk18) {
                sub->unk18->Destroy();
            }
            if (sub->unk1C) {
                sub->unk1C->Destroy();
            }
            if (sub->unk0 && sub->unk4 != 0) {
                gfHeapManager::free(sub->unk0);
                sub->unk0 = 0;
            }
            sub->unkC = 0;
            sub->unk8 = 0;
            sub->unk10 = 0;
            sub->unk14 = 0;
            sub->unk18 = 0;
            sub->unk1C = 0;
            gfHeapManager::free(*reinterpret_cast<void**>(self + 0x14));
            *reinterpret_cast<Sub**>(self + 0x14) = 0;
        }
        nw4r::g3d::G3dObj* obj10 = *reinterpret_cast<nw4r::g3d::G3dObj**>(self + 0x10);
        if (obj10) {
            obj10->Destroy();
            *reinterpret_cast<nw4r::g3d::G3dObj**>(self + 0x10) = 0;
        }
        if (self + 0x58) {
            Member* m = *reinterpret_cast<Member**>(self + 0x58);
            if (m) {
                m->f0(1);
            }
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
