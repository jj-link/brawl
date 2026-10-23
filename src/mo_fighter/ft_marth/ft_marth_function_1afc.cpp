#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

struct ObserverBase : soEventObserver<soGimmickEventObserver> {
    ~ObserverBase() {}
};

struct GimmickObject {
    int header;
    ObserverBase observer;
};

extern "C" GimmickObject* fn_106_1AFC(GimmickObject* self, s16 flag) {
    if (self != 0) {
        self->observer.~ObserverBase();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
