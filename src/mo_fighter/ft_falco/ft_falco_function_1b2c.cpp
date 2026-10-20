#pragma force_active on
class soGimmickEventObserver;

template<class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class Observer : public soEventObserver<soGimmickEventObserver> {
public:
    ~Observer() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_1B2C(void* self, short flag)
{
    if (self) {
        Observer* observer = (Observer*)((char*)self + 4);
        observer->~Observer();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
