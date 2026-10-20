#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

struct Observer : soEventObserver<soGimmickEventObserver> {
    ~Observer() {}
};

struct Object {
    int unused;
    Observer observer;
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1AD0(Object* self, int flag) {
    if (self) {
        self->observer.~Observer();
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
