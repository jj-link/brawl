#include <cstdlib>
#pragma force_active on

extern "C" void* fn_122_89B0(void*, short);
extern "C" void* fn_122_8D58(void*, short);

extern "C" void* fn_122_8944(void* object, short deleting) {
    if (object != 0) {
        fn_122_89B0(static_cast<unsigned char*>(object) + 0x16d8, -1);
        fn_122_8D58(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
