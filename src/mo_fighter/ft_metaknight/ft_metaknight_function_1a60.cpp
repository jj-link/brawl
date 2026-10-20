#include <types.h>
#pragma force_active on

class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class ObserverWrapper : public soEventObserver<soGimmickEventObserver> {
public:
    ~ObserverWrapper() {}
};

extern "C" void* fn_111_1A60(void* object, s16 deleting) {
    if (object != 0) {
        ObserverWrapper* observer =
            reinterpret_cast<ObserverWrapper*>(static_cast<u8*>(object) + 4);
        observer->~ObserverWrapper();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
