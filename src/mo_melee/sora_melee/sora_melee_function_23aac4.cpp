#include <gf/gf_task.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const char lbl_27_data_4CFD0[];

gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    gfTask*, const char*, gfTask::Category, int, int, bool);

struct SoraGameGlobal {
    char pad[0x8];
    void* unk8;
};
extern SoraGameGlobal* g_GameGlobal;
}

struct SoraTaskOwner {
    char pad[0x2C];
    u8 unk2C;
    char pad2[0xF];
    const char* name;
    u32 unk40;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
};

extern "C" SoraTaskOwner* fn_27_23AAC4(SoraTaskOwner* self, const char* name) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        reinterpret_cast<gfTask*>(self), name,
        static_cast<gfTask::Category>(0), 0xD, 6, true);
    self->name = lbl_27_data_4CFD0;
    self->unk40 = 0;
    self->unk44 = 0;
    self->unk45 = 0;
    self->unk46 = 0;
    self->unk47 = 0;
    *reinterpret_cast<void**>(&self->unk40) = g_GameGlobal->unk8;
    self->unk2C &= ~0x02;
    return self;
}
