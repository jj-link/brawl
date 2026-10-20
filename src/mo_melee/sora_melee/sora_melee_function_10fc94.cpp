#include <gf/gf_task.h>
#include <snd/snd_system.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const char lbl_27_data_26D90[];
extern const char lbl_27_data_26DA0[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);
}

struct SoraTaskOwner {
    char pad[0x3C];
    const void* name;
    void* unk40;
    u32 unk44;
    char pad2[0x30];
    u32 unk78;
    u8 unk7C;
};

extern "C" void* fn_27_10FC94(void* self) {
    SoraTaskOwner* s = reinterpret_cast<SoraTaskOwner*>(self);
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_27_data_26D90, 0, 0, 0xD, true);
    s->unk44 = 0;
    s->name = lbl_27_data_26DA0;
    s->unk40 = (char*)lbl_27_data_26DA0 + 0x64;
    char* base = (char*)g_sndSystem;
    u32 v = (*(u32*)(base + 0x6E8) + 1) & 0xFFFF;
    *(u32*)(base + 0x6E8) = v;
    s->unk78 = v;
    s->unk7C = 0;
    return self;
}
