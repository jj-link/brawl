#include <types.h>
#include <stdio.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>

#pragma force_active on

extern "C" {
s32 fn_800FEE4C(void*, void*, s32);
extern char lbl_8059E530[8];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

extern "C" void fn_800FED80(void* self, s32 idx, s32 frame) {
    char buf[8];
    nw4r::g3d::ScnMdl* scn = *(nw4r::g3d::ScnMdl**)((char*)self + 0xfc);
    void* node = *(void**)((char*)self + (idx + 4) * 4 + 0xf0);
    s32 n = idx * 8 - idx;
    fn_800FEE4C(self, node, n + 0x1f);
    ((MuObject*)*(void**)((char*)self + (idx + 0x1b) * 4 + 4))->setFrameMatCol((float)frame);
    scn->RemoveAnmObj((nw4r::g3d::ScnMdlSimple::AnmObjType)(u32)node);
    sprintf(buf, lbl_8059E530, idx);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scn, node, buf);
}
