#include <new>
#pragma force_active on

extern "C" void* fn_98_1AB0(void*, short);

extern "C" void* fn_98_1A54(void* obj, int deleting) {
    if (obj) {
        fn_98_1AB0(obj, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(obj);
    }
    return obj;
}
