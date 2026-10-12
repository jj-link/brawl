#include <types.h>

class soCollisionAttackModule;
class soCollisionLog;
class soModuleAccesser;

extern "C" void fn_27_1DB0EC(void*, float, float, soCollisionAttackModule*,
                             soCollisionLog*, u32, soModuleAccesser*, bool);

// Generated adjustors forward the complete final argument word, not a narrowed bool.
extern "C" void fn_99_10C7C(void* object, float posX, float collisionLr,
                           soCollisionAttackModule* attack, soCollisionLog* log,
                           u32 groupIndex, soModuleAccesser* accesser, unsigned int flags) {
    typedef void (*RawSecondHitEntry)(void*, float, float, soCollisionAttackModule*,
                                     soCollisionLog*, u32, soModuleAccesser*, unsigned int);
    reinterpret_cast<RawSecondHitEntry>(fn_27_1DB0EC)(
        static_cast<unsigned char*>(object) - 0x7C,
        posX, collisionLr, attack, log, groupIndex, accesser, flags);
}
