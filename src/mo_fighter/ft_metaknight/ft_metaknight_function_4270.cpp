#include <types.h>
#pragma force_active on

extern "C" void* fn_111_3B68(void* object, s16 deleting);
extern "C" void* fn_111_3BEC(void* object, s16 deleting);
extern "C" void* fn_111_430C(void* object, s16 deleting);
extern "C" void* fn_111_4368(void* object, s16 deleting);
extern "C" void* fn_111_4D80(void* object, s16 deleting);
extern "C" void* fn_27_C74E8(void* object, s16 deleting);

extern "C" void* fn_111_4270(void* object, s16 deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_111_3B68(members + 0xe00, memberDeleting);
        fn_111_3BEC(members + 0xdec, memberDeleting);
        fn_111_430C(members + 0x958, memberDeleting);
        fn_111_4368(members + 0xe4, memberDeleting);
        fn_111_4D80(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
