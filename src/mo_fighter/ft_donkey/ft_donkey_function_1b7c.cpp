#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    int data;
    ~soEventObserver();
};

struct Observer : soEventObserver<soGimmickEventObserver> {
    ~Observer() {}
};

struct Object {
    int pad;
    Observer observer;
};

extern "C" void __dl__FPv(void*);

extern "C" Object* fn_92_1B7C(Object* self, int flag) {
    if (self) {
        self->observer.~Observer();
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
