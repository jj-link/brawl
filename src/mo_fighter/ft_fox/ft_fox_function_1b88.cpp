#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class Observer : public soEventObserver<soGimmickEventObserver> {
public:
    ~Observer() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_1B88(void* self, int flag) {
    if (self) {
        Observer* base = (Observer*)((char*)self + 4);
        base->~Observer();
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
