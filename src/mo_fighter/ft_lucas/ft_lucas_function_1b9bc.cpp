#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3AA0(void* object, short deleting);
extern "C" void* fn_27_1DBB60(void* object, short deleting);
extern "C" void* fn_114_1BA44(void* object, short deleting);
extern "C" void* fn_27_1D81C8(void* object, short flag);
extern "C" void __dl__FPv(void*);
void operator delete(void*);

extern "C" void* fn_114_1B9BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_114_3AA0(members + 0x1F08, static_cast<short>(-1));
        fn_27_1DBB60(members + 0x1ED0, static_cast<short>(-1));
        fn_114_1BA44(members + 0xCC, static_cast<short>(-1));
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
