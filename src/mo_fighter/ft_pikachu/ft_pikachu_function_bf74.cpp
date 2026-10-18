#include <new>
#pragma force_active on

extern "C" {
void* fn_98_BF14(void*, short);

void* fn_98_BF74(void* object, short deleting) {
    if (object) {
        fn_98_BF14(static_cast<char*>(object) + 4, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
