#pragma force_active on
template <class T> class soEventObserver {
public:
    ~soEventObserver();
};
class soGimmickEventObserver;
extern "C" void __dl__FPv(void*);

class soGimmickObserverHolder : public soEventObserver<soGimmickEventObserver> {
public:
    ~soGimmickObserverHolder() {}
};

class soGimmickObject {
public:
    int header;
    soGimmickObserverHolder observer;
};

extern "C" soGimmickObject* fn_100_1AD0(soGimmickObject* self, short flag) {
    if (self != 0) {
        self->observer.~soGimmickObserverHolder();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
