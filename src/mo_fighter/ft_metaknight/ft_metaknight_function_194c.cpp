#include <types.h>
#pragma force_active on

extern "C" void* fn_111_1A04(void* object, s16 deleting);
extern "C" void* fn_111_1AC4(void* object, s16 deleting);
extern "C" void* fn_111_1B20(void* object, s16 deleting);
extern "C" void* fn_111_1B7C(void* object, s16 deleting);
extern "C" void* fn_111_1BD8(void* object, s16 deleting);
extern "C" void* fn_111_1C34(void* object, s16 deleting);
extern "C" void* fn_111_1C90(void* object, s16 deleting);
extern "C" void* fn_111_1CEC(void* object, s16 deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_194C(void* object, s16 deleting) {
    if (object != 0) {
        u8* members = static_cast<u8*>(object);
        s16 memberDeleting = -1;
        fn_111_1A04(members + 0x84, memberDeleting);
        fn_111_1AC4(members + 0x70, memberDeleting);
        fn_111_1B20(members + 0x5C, memberDeleting);
        fn_111_1B7C(members + 0x48, memberDeleting);
        fn_111_1BD8(members + 0x34, memberDeleting);
        fn_111_1C34(members + 0x20, memberDeleting);
        fn_111_1C90(members + 8, memberDeleting);
        fn_111_1CEC(object, static_cast<s16>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
