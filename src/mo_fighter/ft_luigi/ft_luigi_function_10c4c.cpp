#include <types.h>

class acAnimCmd;
class soModuleAccesser;

extern "C" bool fn_27_1DA24C(void*, acAnimCmd*, soModuleAccesser*, s32);

// The secondary interface lies 0x48 bytes into the complete article object.
extern "C" bool fn_99_10C4C(void* object, acAnimCmd* command,
                           soModuleAccesser* accesser, s32 argument) {
    return fn_27_1DA24C(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x48),
        command, accesser, argument);
}
