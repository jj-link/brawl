#include <gf/gf_task_scheduler.h>
#include <so/so_module_accesser.h>

#pragma force_active on

class Article {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
    virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
    virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23();
    virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27();
    virtual void a28(); virtual void a29(); virtual void a30(); virtual void a31();
    virtual void remove(int, int);
};

extern "C" {
extern char lbl_103_data_28[], lbl_103_data_23A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_103_10EF0(void*, unsigned int);

void fn_103_981C(char* self) {
    soModuleAccesser* access = *(soModuleAccesser**)(self + 0x60);
    int id = access->m_enumerationStart->m_workManageModule->getInt(0x10000041);
    if (id) {
        void* obj = __dynamic_cast(
            gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)0x12, id),
            0x3c, lbl_103_data_28, lbl_103_data_23A0, 0);
        if (obj) {
            fn_103_10EF0(obj, 0);
        }
    }

    int id2 = (*(soModuleAccesser**)(self + 0x60))
                  ->m_enumerationStart->m_workManageModule->getInt(0x10000042);
    if (id2) {
        ((Article*)(*(soModuleAccesser**)(self + 0x60))
             ->m_enumerationStart->m_effectModule)->remove(id2, 0);
    }
}
}
