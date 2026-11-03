#include <new>
class soCollisionAttackModule;
#include <so/collision/so_collision_hit_part.h>
#include <so/collision/so_collision_hit_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" void fn_27_19AEEC(void*, int, const soCollisionHitPart*, int);
extern "C" void fn_27_CB6E0(void*, int, int);
extern "C" void fn_27_CC8F4(void*, int, int);

extern "C" void* fn_125_8818(void* object, soModuleAccesser* accesser, int taskId,
                              unsigned char taskCategory,
                              soEventObserverRegistrationDesc* desc) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    {
        soCollisionHitPart hitPart(static_cast<soCollision::Category>(0), 0x3FF);
        fn_27_19AEEC(storage, 12, &hitPart, 0);
    }
    fn_27_CB6E0(storage + 0x4EC, 1, 0);
    fn_27_CC8F4(storage + 0x570, 1, 0);
    new (storage + 0x5B4) soCollisionHitModuleImpl(
        accesser, taskId, static_cast<gfTask::Category>(taskCategory),
        reinterpret_cast<soArray<soCollisionHitPart>*>(storage),
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x4EC),
        reinterpret_cast<soArray<soCollisionHitGroup>*>(storage + 0x570),
        desc, true);
    return object;
}