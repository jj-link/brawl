#include <types.h>
#pragma force_active on

class soModuleAccesser;

extern "C" void fn_27_15FA20(int, void*, soModuleAccesser*);
extern "C" void fn_27_BEB00(void*);

extern "C" void fn_27_3855D4(u8* object, int fighterKind, soModuleAccesser* moduleAccessor) {
    fn_27_15FA20(fighterKind, object + 4, moduleAccessor);
    fn_27_BEB00(object + 0x214);
    fn_27_BEB00(object + 0x1D8);
    fn_27_BEB00(object + 0x18C);
    fn_27_BEB00(object + 0x144);
    fn_27_BEB00(object + 0xFC);
    fn_27_BEB00(object + 0xA4);
    fn_27_BEB00(object + 0x70);
    fn_27_BEB00(object + 0x14);
}
