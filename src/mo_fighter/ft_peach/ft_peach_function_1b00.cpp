#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class soGimmickEventObserver
    : public soEventObserver<soGimmickEventObserver> {};

extern "C" void* fn_103_1B00(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        soGimmickEventObserver* member =
            reinterpret_cast<soGimmickEventObserver*>(
                static_cast<char*>(object) + 4);
        member->~soGimmickEventObserver();

        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
