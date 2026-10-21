#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1C48(void* object, short deleting);
extern "C" void* fn_114_1D08(void* object, short deleting);
extern "C" void* fn_114_1D64(void* object, short deleting);
extern "C" void* fn_114_1DC0(void* object, short deleting);
extern "C" void* fn_114_1E1C(void* object, short deleting);
extern "C" void* fn_114_1E78(void* object, short deleting);
extern "C" void* fn_114_1ED4(void* object, short deleting);
extern "C" void* fn_114_1F30(void* object, short deleting);
extern "C" void __dl__FPv(void*);
void operator delete(void*);

extern "C" void* fn_114_1B90(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_114_1C48(members + 0x84, memberDeleting);
        fn_114_1D08(members + 0x70, memberDeleting);
        fn_114_1D64(members + 0x5C, memberDeleting);
        fn_114_1DC0(members + 0x48, memberDeleting);
        fn_114_1E1C(members + 0x34, memberDeleting);
        fn_114_1E78(members + 0x20, memberDeleting);
        fn_114_1ED4(members + 0x8, memberDeleting);
        fn_114_1F30(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
