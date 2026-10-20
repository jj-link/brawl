#include <gf/gf_task.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const char lbl_27_data_4A818[];
extern const char lbl_27_data_4A828[];

gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    gfTask*, const char*, gfTask::Category, int, int, bool);
}

struct SoraTaskOwner {
    char pad[0x3C];
    const char* name;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    char pad2[0x4];
    u32 unk50;
};

extern "C" SoraTaskOwner* fn_27_22A914(SoraTaskOwner* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        reinterpret_cast<gfTask*>(self), lbl_27_data_4A818,
        static_cast<gfTask::Category>(0), 1, 0x0D, true);
    self->unk40 = 0;
    self->name = lbl_27_data_4A828;
    self->unk44 = 0;
    self->unk48 = 0;
    self->unk50 = 0;
    return self;
}
