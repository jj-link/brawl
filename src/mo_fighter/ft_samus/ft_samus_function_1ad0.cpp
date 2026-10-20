#pragma force_active on
template <class T> class soEventObserver {
    unsigned int unknown;

public:
    ~soEventObserver();
};

class soGimmickEventObserver : public soEventObserver<soGimmickEventObserver> {
public:
    ~soGimmickEventObserver() {}
};

struct SamusObserver {
    unsigned int unknown;
    soGimmickEventObserver observer;
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1AD0(SamusObserver* self, int flag) {
    if (self) {
        self->observer.~soGimmickEventObserver();
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
