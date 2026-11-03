#include <mu/mu_msg.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {
void fn_18_11C4(void*, u32, u32, void*);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
extern char lbl_18_data_18C8[];
extern float lbl_18_rodata_298;
extern float lbl_18_rodata_29C;
void FUN_800b9448__5MuMsgFUlb(MuMsg*, u32, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(MuMsg*, u32, u8, u8, u8, float);
}

extern "C" void* fn_18_7AD0(void* self, u32 a, u32 b, void* data) {
    u8* s = reinterpret_cast<u8*>(self);
    fn_18_11C4(self, a, b, data);
    *reinterpret_cast<void**>(s + 0x668) = lbl_18_data_18C8;
    MuMsg* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    *reinterpret_cast<MuMsg**>(s + 0x66c) = msg;
    msg->allocMsgBuf(0x100, 1);
    (*reinterpret_cast<MuMsg**>(s + 0x66c))->setMsgData(data);
    u8* p = *reinterpret_cast<u8**>(s + 0x64c);
    u8* q = *reinterpret_cast<u8**>(p + 0x150);
    nw4r::g3d::ScnMdlSimple* model = *reinterpret_cast<nw4r::g3d::ScnMdlSimple**>(q + 0x10);
    (*reinterpret_cast<MuMsg**>(s + 0x66c))->attachScnMdlSimple(0, model, 0, lbl_18_rodata_298);
    (*reinterpret_cast<MuMsg**>(s + 0x66c))->setFontWidthModeAuto(0);
    (*reinterpret_cast<MuMsg**>(s + 0x66c))->setAlignMode(0, MuMsg::Align_Left);
    (*reinterpret_cast<MuMsg**>(s + 0x66c))->setFontColor(0, 0xff, 0xff, 0xff, 0xff);
    FUN_800b9448__5MuMsgFUlb(*reinterpret_cast<MuMsg**>(s + 0x66c), 0, true);
    FUN_800b9460__5MuMsgFUlUcUcUcf(*reinterpret_cast<MuMsg**>(s + 0x66c), 0, 0x45, 0x45, 0x25, lbl_18_rodata_29C);
    s[0x761] = 1;
    if (g_muWifiInterfaceTask != 0) {
        s[0x760] = 0;
    } else {
        s[0x760] = 1;
    }
    s[0x762] = 0;
    return self;
}