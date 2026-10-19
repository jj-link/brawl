#include <types.h>
#pragma force_active on

void operator delete(void*);

struct soGimmickEventObserver {};
template <class T> struct soEventObserver {
    ~soEventObserver();
};
struct DerivedClass : soEventObserver<soGimmickEventObserver> {};

extern "C" void* fn_114_1CA4(void* object, short deleting) {
    if (object != 0) {
        char* ptr = static_cast<char*>(object) + 4;
        reinterpret_cast<DerivedClass*>(ptr)->~DerivedClass();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
