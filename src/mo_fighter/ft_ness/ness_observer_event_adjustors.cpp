#include <types.h>

struct soLinkEventArgs;
class soModuleAccesser;
class StageObject;
class soStatusData;
class soCollisionLog;
class soCollisionAttackModule;
class soCollisionAttackData;

extern "C" {
void fn_27_1DB0F0(void*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);
void fn_27_1DA1F4(void*, int, int, soStatusData*, soModuleAccesser*);
bool fn_101_15A68(void*, u32 flags);
void fn_27_1DA968(void*, float, soCollisionLog*, soModuleAccesser*);
void fn_27_1DB0EC(void*, float, float, soCollisionAttackModule*, soCollisionLog*,
                  u32, soModuleAccesser*, bool);
void fn_101_15B34(void*, float power, soCollisionAttackData*, u32 index, int,
                  soModuleAccesser*, soCollisionLog*);
}

extern "C" void fn_101_16354(void* object, soLinkEventArgs* event,
                              soModuleAccesser* accesser, StageObject* target, int argument) {
    fn_27_1DB0F0(reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x54),
                event, accesser, target, argument);
}

extern "C" void fn_101_1635C(void* object, int status, int previousStatus,
                              soStatusData* data, soModuleAccesser* accesser) {
    fn_27_1DA1F4(reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x64),
                status, previousStatus, data, accesser);
}

extern "C" bool fn_101_16364(void* object, u32 flags) {
    return fn_101_15A68(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x70), flags);
}

extern "C" void fn_101_1636C(void* object, float power, soCollisionLog* log,
                              soModuleAccesser* accesser) {
    fn_27_1DA968(reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x70),
                power, log, accesser);
}

// The original generated adjustor forwards the full final argument word,
// without adding a boolean-byte conversion at this boundary.
extern "C" void fn_101_16374(void* object, float posX, float collisionLr,
                              soCollisionAttackModule* attack, soCollisionLog* log,
                              u32 groupIndex, soModuleAccesser* accesser, unsigned int flags) {
    typedef void (*NessRawSecondHitEntry)(void*, float, float, soCollisionAttackModule*,
                                        soCollisionLog*, u32, soModuleAccesser*, unsigned int);
    reinterpret_cast<NessRawSecondHitEntry>(fn_27_1DB0EC)(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x7C),
        posX, collisionLr, attack, log, groupIndex, accesser, flags);
}

extern "C" void fn_101_1637C(void* object, float power, soCollisionAttackData* attack,
                              u32 index, int kind, soModuleAccesser* accesser,
                              soCollisionLog* collisionLog) {
    fn_101_15B34(reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x7C),
                power, attack, index, kind, accesser, collisionLog);
}
