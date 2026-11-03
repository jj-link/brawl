#include <gf/gf_task.h>
#pragma force_active on

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0();
    virtual void fn_27_100CC();
    virtual void fn_27_10094();
    virtual unsigned int fn_27_100C8(unsigned int);
};
struct A { char pad[0x64]; Class_CF8* module; };
struct B { char pad[0xd8]; A* a; };
struct C { char pad[0x60]; B* b; };
struct D { char pad[0xc]; unsigned int id; };

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char __RTTI__6gfTask[];
extern char lbl_27_data_248[];
extern "C" int fn_27_8CB54(void*);

extern "C" int fn_27_29B4C8(void*, C* context, D* data) {
    unsigned int id = context->b->a->module->fn_27_100C8(0x10000000);
    if (data->id == id) return 0;
    if (id != 0xffffffff) {
        gfTask* task = gfTask::getTask(id);
        void* object = task ? __dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0) : 0;
        if (object) {
            int team = fn_27_8CB54(object);
            if (team != -1 && data->id != 0xffffffff) {
                gfTask* other = gfTask::getTask(data->id);
                void* object2 = task ? __dynamic_cast(other, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0) : 0;
                if (object2) {
                    int team2 = fn_27_8CB54(object2);
                    if (team2 != -1 && team2 == team) return 0;
                }
            }
        }
    }
    return 1;
}