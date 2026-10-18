#include <new>
#pragma force_active on

extern "C" {
void* fn_98_B8C4(void*, short);

void* fn_98_B920(void* object, short deleting) {
    if (object) {
        fn_98_B8C4(static_cast<char*>(object) + 4, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
