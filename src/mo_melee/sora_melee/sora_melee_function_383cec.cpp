#pragma force_active on

#include <gf/gf_task.h>
#include <gf/gf_task_scheduler.h>
#include <ft/ft_manager.h>
#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/model/so_model_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <mt/mt_vector.h>
#include <types.h>

struct Bits { int x, y, z; };

#define P10(b) virtual void b##0(); virtual void b##1(); virtual void b##2(); virtual void b##3(); virtual void b##4(); virtual void b##5(); virtual void b##6(); virtual void b##7(); virtual void b##8(); virtual void b##9();

struct Self_base {
    char pad[0x3c];
};

class Self : public Self_base {
public:
    P10(a) P10(b) P10(c) P10(d) P10(e) P10(f) P10(g) P10(h) P10(i) P10(j) P10(k)
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual u32 getZonePos();
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_94D38[];
extern char lbl_27_data_93F28[];
extern char lbl_27_data_248[];
extern char __RTTI__6gfTask[];
extern const float lbl_27_rodata_7C0C;
extern const float lbl_27_rodata_7C14;
void fn_27_388A44(Vec3f* out, void* self, soModuleAccesser* acc);
void fn_27_394E64(Vec3f* out, void* obj, int flag);
float fn_27_111D98(void* owner);
void fn_27_38D5E8(Self* self, Vec3f* a, Vec3f* b, Vec3f* c, Vec3f* d, int flag, u32 id, float f);
}

extern "C" int fn_27_383CEC(Self* arg0, soModuleAccesser* arg1) {
    void* r28;
    Vec3f f8;
    Vec3f ec;
    Vec3f e;
    Vec3f d4;
    if (arg1->m_enumerationStart->m_statusModule->getStatusKind() == 0x116) {
        if (gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)0xC, arg0->getZonePos()) != nullptr) {
            r28 = (void*)arg1->m_enumerationStart->m_workManageModule->getInt(0x10000043);
            gfTask* t2 = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)0xC, (u32)r28);
            if (t2 != nullptr) {
                r28 = __dynamic_cast(t2, 0x3C, lbl_27_data_94D38, __RTTI__6gfTask, 1);
                if (arg1->m_enumerationStart->m_workManageModule->isFlag(0x1200003F) == 1) {
                    Vec3f c8;
                    fn_27_388A44(&c8, (char*)__dynamic_cast(arg1->m_stageObject, 0x3C, lbl_27_data_93F28, lbl_27_data_248, 1) + 0x7FAC, arg1);
                    f8 = c8;
                    ec = c8;
                } else {
                    Vec3f first = arg1->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0x28, false);
                    f8 = first;
                    Vec3f second = arg1->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0x18, false);
                    ec = second;
                }
                soWorkManageModule* work = arg1->m_enumerationStart->m_workManageModule;
                Vec3f pa4;
                Vec3f p98;
                Vec3f p8c;
                Vec3f p80;
                Vec3f p74;
                Vec3f p68;
                *(Bits*)&p68 = *(Bits*)&ec;
                fn_27_394E64(&p74, r28, 1);
                *(Bits*)&p80 = *(Bits*)&p74;
                *(Bits*)&p8c = *(Bits*)&f8;
                fn_27_394E64(&p98, r28, 0);
                *(Bits*)&pa4 = *(Bits*)&p98;
                u32 flag = work->isFlag(0x1200003D);
                fn_27_38D5E8(arg0, &pa4, &p8c, &p80, &p68, 1, flag, lbl_27_rodata_7C0C);
            }
        }
    } else {
        float f31 = arg1->m_enumerationStart->m_workManageModule->getFloat(0x11000014);
        float e0 = arg1->m_enumerationStart->m_workManageModule->getFloat(0x11000013);
        e.m_x = e0;
        e.m_y = f31;
        e.m_z = lbl_27_rodata_7C14;
        if (arg1->m_enumerationStart->m_workManageModule->isFlag(0x1200003F) == 1) {
            Vec3f c8;
            fn_27_388A44(&c8, (char*)__dynamic_cast(arg1->m_stageObject, 0x3C, lbl_27_data_93F28, lbl_27_data_248, 1) + 0x7FAC, arg1);
            d4 = c8;
        } else {
            Vec3f position = arg1->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0x28, false);
            d4 = position;
        }
        void* owner = g_ftManager->getOwner(arg1->m_enumerationStart->m_workManageModule->getInt(0x10000000));
        r28 = arg1->m_enumerationStart->m_workManageModule;
        Vec3f c44;
        Vec3f c38;
        Vec3f c2c;
        Vec3f s20;
        Vec3f c14;
        Vec3f s8;
        s8.m_x = lbl_27_rodata_7C14;
        s8.m_y = lbl_27_rodata_7C14;
        s8.m_z = lbl_27_rodata_7C14;
        s20.m_x = lbl_27_rodata_7C14;
        s20.m_y = lbl_27_rodata_7C14;
        s20.m_z = lbl_27_rodata_7C14;
        *(Bits*)&c14 = *(Bits*)&s8;
        *(Bits*)&c2c = *(Bits*)&s20;
        *(Bits*)&c38 = *(Bits*)&d4;
        *(Bits*)&c44 = *(Bits*)&e;
        float f = fn_27_111D98(owner);
        u32 flag = ((soWorkManageModule*)r28)->isFlag(0x1200003D);
        fn_27_38D5E8(arg0, &c44, &c38, &c2c, &c14, 0, flag, f);
    }
    return 1;
}
