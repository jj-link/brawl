#include <gf/gf_task_scheduler.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_29FF2C();
    virtual void fn_27_281B1C();
    virtual void fn_27_2839BC();
    virtual void fn_27_284EA0();
    virtual void fn_27_289454();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(u32, u32);
};

struct Modules {
    char pad[0x64];
    Object_vptr_0* module;
};
struct Access {
    char pad[0xD8];
    Modules* modules;
};
struct Context {
    char pad[0x60];
    Access* access;
};
struct Data {
    char pad[0x3C];
    u32 id;
    char pad40[4];
    u8 category;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char __RTTI__6gfTask[];
extern const char lbl_27_data_248[];
extern "C" u32 fn_27_8CB9C(void*);

extern "C" int fn_27_29806C(void*, Context* context, void*, Data* data) {
    u32 id;
    u32 category = data->category;
    if (category == 6) return 0;
    id = data->id;
    if (category != 10) {
        gfTask* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)category, id);
        if (task != 0) {
            id = fn_27_8CB9C(__dynamic_cast(task, 0x3C, lbl_27_data_248, __RTTI__6gfTask, 1));
            category = 10;
        }
    }
    Object_vptr_0* module = context->access->modules->module;
    module->slot5(id, 0x10000000);
    module->slot5(category, 0x10000001);
    return 1;
}
