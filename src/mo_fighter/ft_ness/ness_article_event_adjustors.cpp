#include <types.h>

class acAnimCmd;
class soModuleAccesser;
class soCollisionAttackData;
class soCollisionLog;

extern "C" {
void* fn_101_14C68(void*, short);
void* fn_101_4DBC(void*, short);
bool fn_27_1DAF80(void*, u32 flags);
void fn_27_1DB0E8(void*, float power, soCollisionAttackData*, u32 index, int,
                  soModuleAccesser*, soCollisionLog*);
bool fn_27_1DA24C(void*, acAnimCmd*, soModuleAccesser*, s32);
}

// Generated deleting adjustors preserve the complete incoming EABI word.
// Its signed low halfword is interpreted only by the deleting entry itself.
typedef void* (*NessRawDeletingEntry)(void*, unsigned int);

extern "C" void* fn_101_16314(void* object, unsigned int deleting) {
    return reinterpret_cast<NessRawDeletingEntry>(fn_101_14C68)(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x40), deleting);
}

extern "C" bool fn_101_1631C(void* object, u32 flags) {
    return fn_27_1DAF80(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x70), flags);
}

extern "C" void fn_101_16324(void* object, float power, soCollisionAttackData* attack,
                              u32 index, int kind, soModuleAccesser* accesser,
                              soCollisionLog* collisionLog) {
    fn_27_1DB0E8(reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x7C),
                power, attack, index, kind, accesser, collisionLog);
}

extern "C" void* fn_101_1632C(void* object, unsigned int deleting) {
    return reinterpret_cast<NessRawDeletingEntry>(fn_101_14C68)(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x90), deleting);
}

extern "C" void* fn_101_16334(void* object, unsigned int deleting) {
    return reinterpret_cast<NessRawDeletingEntry>(fn_101_14C68)(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x88), deleting);
}

extern "C" void* fn_101_1633C(void* object, unsigned int deleting) {
    return reinterpret_cast<NessRawDeletingEntry>(fn_101_4DBC)(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x40), deleting);
}

extern "C" bool fn_101_16344(void* object, acAnimCmd* command,
                              soModuleAccesser* accesser, s32 argument) {
    return fn_27_1DA24C(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x48),
        command, accesser, argument);
}
