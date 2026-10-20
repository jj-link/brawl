#include <gf/gf_task.h>
#include <types.h>
#pragma force_active on

class stTriggerMng {
public:
    char pad[0x3C];
    const char* name;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;
    bool unk60;
};

extern "C" {
extern const char lbl_27_data_4BEF8[];
extern gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, gfTask::Category, int, int, bool);
extern stTriggerMng* g_stTriggerMng;
}

extern "C" stTriggerMng* fn_27_231E28(stTriggerMng* self, const char* taskName) {
    gfTask* task = reinterpret_cast<gfTask*>(self);
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        task, taskName, gfTask::Category_Ground, 1, 0xD, true);
    u32 zero = 0;
    self->name = lbl_27_data_4BEF8;
    self->unk4C = zero;
    self->unk50 = zero;
    self->unk54 = zero;
    self->unk58 = zero;
    self->unk5C = zero;
    self->unk60 = true;
    g_stTriggerMng = self;
    self->unk44 = zero;
    self->unk40 = zero;
    self->unk48 = zero;
    return self;
}
