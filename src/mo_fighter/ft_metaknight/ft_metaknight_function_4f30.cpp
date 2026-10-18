#include <types.h>
#pragma force_active on

extern "C" void* fn_27_150488(void* object, s16 destroy);
extern "C" void fn_111_4FB0(void* object, s16 destroy);
extern "C" void* fn_27_199A54(void* object, s16 destroy);
void operator delete(void* object);

extern "C" void* fn_111_4F30(void* object, s16 destroy) {
    s16 flag = -1;
    if (object != 0) {
        fn_27_150488(static_cast<u8*>(object) + 0x5B8, flag);
        fn_111_4FB0(static_cast<u8*>(object) + 0x584, flag);
        if (object != 0) {
            fn_27_199A54(object, flag);
        }
        if (destroy > 0) {
            operator delete(object);
        }
    }
    return object;
}
