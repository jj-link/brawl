#include <gf/gf_task.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const char lbl_27_data_73A8[];
extern const char lbl_27_data_73B0[];

gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    gfTask*, const char*, gfTask::Category, int, int, bool);
void fn_8015BF9C(void*, int);
}

struct TaskOwner {
    char pad[0x3C];
    const char* name;
    char data[0x20];
};

extern "C" TaskOwner* fn_27_64A90(TaskOwner* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        reinterpret_cast<gfTask*>(self), lbl_27_data_73A8,
        static_cast<gfTask::Category>(0x27), 0x0E, 0x0D, true);
    self->name = lbl_27_data_73B0;
    fn_8015BF9C(reinterpret_cast<char*>(self) + 0x40, 8);
    return self;
}
