#include <gf/gf_file_io_handle.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <mu/mu_object.h>
#include <gm/gm_global.h>
#pragma force_active on
extern "C" {
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
void* fn_800B6AC0(void*, const char*);
void fn_80192ECC(void*, float, float, float);
void fn_8007F2B4(void*, void*, int);
extern void* g_gfSceneRoot;
extern char lbl_24_data_814[];
extern char lbl_24_data_82C[];
extern float lbl_24_rodata_68[];
}
extern "C" void fn_24_2D18(void* self) {
    float* c = lbl_24_rodata_68;
    char* p = (char*)self;
    void* sp10;
    void* spC;
    void* sp8;
    *(void**)(p + 0x48) = ((gfFileIOHandle*)(p + 0x40))->getBuffer();
    *(void**)(p + 0x4C) = ((gfFileIOHandle*)(p + 0x44))->getBuffer();
    nw4r::g3d::ResFile::Init(p + 0x48);
    nw4r::g3d::ResFile::Init(p + 0x4C);
    sp10 = 0;
    sp10 = ((nw4r::g3d::ResFile*)(p + 0x48))->GetResAnmScn(0).ptr();
    sp8 = sp10;
    fn_801971D0(&sp10, &sp8);
    fn_8000D6DC(g_gfSceneRoot, &sp10);
    *(MuObject**)(p + 0x50) = MuObject::create((nw4r::g3d::ResFile*)(p + 0x4C), lbl_24_data_814, 1, 0, (HeapType)0x2A);
    spC = fn_800B6AC0(*(void**)(p + 0x50), lbl_24_data_82C);
    if (!((((unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1)) {
        fn_80192ECC(&spC, c[0], c[1], c[2]);
    } else {
        fn_80192ECC(&spC, c[0], c[2], c[2]);
    }
    fn_8007F2B4(*(void**)(p + 0x54), *(void**)(*(char**)(p + 0x50) + 0x10), 0);
}