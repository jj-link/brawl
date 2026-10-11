#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/so_photo_call_back.h>
#include <gf/gf_task.h>
#include <math.h>

struct FinalStopEnergy {
    soKineticEnergy base;
    Vec2f speed, acceleration, reserved, brake, limit;
};
struct FinalProcess { void* vtable; };
struct FinalTypeInfo { const char* name; const void* bases; const void* end; };
struct FinalBaseInfo { const void* type; int adjustment; const void* end; };
struct FinalRegistration { void* next; void* object; void* destructor; };
typedef void (*FinalMethod)();
struct FinalVtable { const FinalTypeInfo* type; unsigned long reserved; FinalMethod methods[14]; };
extern "C" {
extern const char lbl_106_data_534C[], lbl_106_data_EB4[], lbl_106_data_654[], lbl_106_data_17F0[];
extern const char lbl_106_data_28[], lbl_106_data_18F0[], lbl_106_data_54E0[];
extern const float lbl_106_rodata_40, lbl_106_rodata_44;
extern FinalVtable lbl_106_data_5678;
extern FinalTypeInfo lbl_106_data_56E4;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __register_global_object(void*, void*, void*);
Vec3f* fn_106_77F4(Vec3f*, float, float, float);
void fn_106_954C(Vec2f*, const Vec2f*);
void fn_27_89DAC(int, soModuleAccesser*);
unsigned long fn_106_DB60(void*);
void fn_106_DAB0(Vec3f*, void*, int);
void fn_106_DA98(void*, const Vec3f*, int);
void fn_106_DA2C(void*, int);
void fn_106_D0C8(FinalProcess*, soModuleAccesser*);
FinalProcess* fn_106_D400(FinalProcess*);
}
long randi(long);

extern "C" void fn_106_C99C(FinalProcess*, soModuleAccesser* accesser) {
    fn_27_89DAC(3, accesser);
    fn_27_89DAC(1, accesser);
    fn_27_89DAC(2, accesser);
    fn_27_89DAC(4, accesser);
    fn_27_89DAC(0, accesser);
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x116:
        for (int i = 0; i < 6; ++i) {
            accesser->getWorkManageModule().setInt(soValueAccesser::getConstantInt(accesser, 0x5dc7, 0), 0x2000000a + i);
            accesser->getWorkManageModule().setInt(soValueAccesser::getConstantInt(accesser, 0x5dc6, 0), 0x20000010 + i);
            accesser->getWorkManageModule().setFloat(randi(360), 0x21000004 + i);
        }
        break;
    case 0x11e: {
        FinalStopEnergy* stop = static_cast<FinalStopEnergy*>(__dynamic_cast(accesser->getKineticModule().getEnergy(3), 0, lbl_106_data_534C, lbl_106_data_EB4, 1));
        float speed = accesser->getPostureModule().getLr();
        float multiplier = soValueAccesser::getConstantFloat(accesser, 0xfbd, 0);
        speed = multiplier * speed;
        if (accesser->getSituationModule().getKind() == 2) {
            Vec2f velocity(speed, lbl_106_rodata_40);
            Vec3f rotation;
            stop->base.resetEnergy(6, &velocity, fn_106_77F4(&rotation, lbl_106_rodata_40, lbl_106_rodata_40, lbl_106_rodata_40), accesser);
        } else {
            Vec2f velocity(speed, lbl_106_rodata_40);
            Vec3f rotation;
            stop->base.resetEnergy(0, &velocity, fn_106_77F4(&rotation, lbl_106_rodata_40, lbl_106_rodata_40, lbl_106_rodata_40), accesser);
        }
        Vec2f brake(lbl_106_rodata_40, lbl_106_rodata_40);
        fn_106_954C(&stop->brake, &brake);
        Vec2f limit(lbl_106_rodata_44, lbl_106_rodata_40);
        fn_106_954C(&stop->limit, &limit);
        reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
        accesser->getWorkManageModule().setInt(accesser->getSituationModule().getKind(), 0x20000003);
        break;
    }
    case 0x120: {
        char* fighter = static_cast<char*>(__dynamic_cast(&accesser->getStageObject(), 0x3c, lbl_106_data_654, lbl_106_data_17F0, 0));
        if (fighter) reinterpret_cast<soPhotoCallBack*>(fighter + 0x8554)->addCallback();
        break;
    }
    }
}
#pragma dont_inline on
extern "C" void fn_106_CD00(Vec2f* vector, float x, float y) { vector->m_x = x; vector->m_y = y; }
#pragma dont_inline reset
extern "C" void fn_106_CD0C(FinalProcess* process, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x11e: {
        FinalStopEnergy* stop = static_cast<FinalStopEnergy*>(__dynamic_cast(accesser->getKineticModule().getEnergy(3), 0, lbl_106_data_534C, lbl_106_data_EB4, 1));
        float speed = accesser->getPostureModule().getLr();
        float multiplier = soValueAccesser::getConstantFloat(accesser, 0xfbd, 0);
        speed = multiplier * speed;
        if (accesser->getSituationModule().getKind() != accesser->getWorkManageModule().getInt(0x20000003)) {
            if (accesser->getSituationModule().getKind() == 2) {
                Vec2f velocity(speed, lbl_106_rodata_40); Vec3f rotation;
                stop->base.resetEnergy(6, &velocity, fn_106_77F4(&rotation, lbl_106_rodata_40, lbl_106_rodata_40, lbl_106_rodata_40), accesser);
            } else {
                Vec2f velocity(speed, lbl_106_rodata_40); Vec3f rotation;
                stop->base.resetEnergy(0, &velocity, fn_106_77F4(&rotation, lbl_106_rodata_40, lbl_106_rodata_40, lbl_106_rodata_40), accesser);
            }
            Vec2f brake(lbl_106_rodata_40, lbl_106_rodata_40); fn_106_954C(&stop->brake, &brake);
            Vec2f limit(lbl_106_rodata_44, lbl_106_rodata_40); fn_106_954C(&stop->limit, &limit);
        } else {
            Vec2f velocity(speed, lbl_106_rodata_40); fn_106_954C(&stop->speed, &velocity);
        }
        break;
    }
    case 0x11f: break;
    case 0x120: fn_106_D0C8(process, accesser); break;
    }
}
extern "C" void fn_106_CF58(FinalProcess* process, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x120: fn_106_D0C8(process, accesser); break;
    }
}
extern "C" void fn_106_CFBC(FinalProcess*, soModuleAccesser*) {}
extern "C" void fn_106_CFC0(FinalProcess*, soModuleAccesser* accesser, int next) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x120: {
        char* fighter = static_cast<char*>(__dynamic_cast(&accesser->getStageObject(), 0x3c, lbl_106_data_654, lbl_106_data_17F0, 0));
        if (!fighter) return;
        reinterpret_cast<soPhotoCallBack*>(fighter + 0x8554)->removeCallBack();
        break;
    }
    }
    switch (next) {
    case 0x11e: case 0x11f: case 0x120: return;
    }
    int count = accesser->getWorkManageModule().getInt(0x20000016);
    for (int i = 0; i < count; ++i) gfTask::getTask(accesser->getWorkManageModule().getInt(0x20000004 + i))->exit();
}
extern "C" void fn_106_D0C8(FinalProcess*, soModuleAccesser* accesser) {
    int count = accesser->getWorkManageModule().getInt(0x20000016);
    if (count <= 0) return;
    for (int i = 0; i < count; ++i) {
        if (accesser->getWorkManageModule().getInt(0x20000010 + i) > 0) {
            Vec3f position;
            float sine;
            accesser->getWorkManageModule().subInt(1, 0x20000010 + i);
            double angle = accesser->getWorkManageModule().getFloat(0x21000004 + i);
            float magnitude = soValueAccesser::getConstantFloat(accesser, 0xfbe, 0);
            sine = sin(angle);
            float cosine = cos(angle);
            Vec2f velocity; fn_106_CD00(&velocity, magnitude * cosine, magnitude * sine);
            void* task = __dynamic_cast(gfTask::getTask(accesser->getWorkManageModule().getInt(0x20000004 + i)), 0x3c, lbl_106_data_28, lbl_106_data_18F0, 0);
            if (task && fn_106_DB60(task) == 1) {
                fn_106_DAB0(&position, task, 0);
                position.m_x += velocity.m_x;
                position.m_y += velocity.m_y;
                fn_106_DA98(task, &position, 0);
            }
        }
        if (accesser->getWorkManageModule().getInt(0x2000000a + i) > 0) {
            accesser->getWorkManageModule().subInt(1, 0x2000000a + i);
            if (accesser->getWorkManageModule().getInt(0x2000000a + i) == 0) {
                void* task = __dynamic_cast(gfTask::getTask(accesser->getWorkManageModule().getInt(0x20000004 + i)), 0x3c, lbl_106_data_28, lbl_106_data_18F0, 0);
                if (task) fn_106_DA2C(task, 0);
            }
        }
    }
}
extern "C" FinalProcess* fn_106_D378(FinalProcess* process, short deleting) {
    if (process && deleting > 0) operator delete(process);
    return process;
}
extern "C" {
FinalRegistration lbl_106_bss_1C8;
FinalProcess lbl_106_bss_1D4;
}
extern "C" void fn_106_D3B8() {
    fn_106_D400(&lbl_106_bss_1D4);
    __register_global_object(&lbl_106_bss_1D4, reinterpret_cast<void*>(fn_106_D378), &lbl_106_bss_1C8);
}
#pragma dont_inline on
extern "C" FinalProcess* fn_106_D400(FinalProcess* process) { process->vtable = &lbl_106_data_5678; return process; }
#pragma dont_inline reset
extern "C" {
void fn_106_B53C(); void fn_106_B538(); void fn_106_B534(); void fn_106_B52C();
void fn_106_B528(); void fn_106_B520(); void fn_106_B51C(); void fn_106_B514();
FinalVtable lbl_106_data_5678 = { &lbl_106_data_56E4, 0, {
    reinterpret_cast<FinalMethod>(fn_106_D378), reinterpret_cast<FinalMethod>(fn_106_C99C),
    reinterpret_cast<FinalMethod>(fn_106_CFC0), reinterpret_cast<FinalMethod>(fn_106_CD0C),
    reinterpret_cast<FinalMethod>(fn_106_CF58), fn_106_B53C, fn_106_B538,
    reinterpret_cast<FinalMethod>(fn_106_CFBC), fn_106_B534, fn_106_B52C, fn_106_B528,
    fn_106_B520, fn_106_B51C, fn_106_B514 }};
char lbl_106_data_56B8[] = "ftMarthStatusUniqProcessFinal";
FinalBaseInfo lbl_106_data_56D8 = { lbl_106_data_54E0, 0, 0 };
FinalTypeInfo lbl_106_data_56E4 = { lbl_106_data_56B8, &lbl_106_data_56D8, 0 };
}
__declspec(section ".ctors") extern void (*const finalInitializer)() = fn_106_D3B8;
