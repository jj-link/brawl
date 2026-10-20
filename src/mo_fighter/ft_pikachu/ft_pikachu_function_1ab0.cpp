#include <new>
#pragma force_active on

template <class T> class soEventObserver {
public:
    ~soEventObserver();
};

class soGimmickEventObserver : public soEventObserver<soGimmickEventObserver> {
public:
    ~soGimmickEventObserver() {}
};

extern "C" void* fn_98_1AB0(char* object, int deleting) {
    if (object) {
        reinterpret_cast<soGimmickEventObserver*>(object + 4)->~soGimmickEventObserver();
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
