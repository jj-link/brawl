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

extern "C" void* fn_119_1B44(void* self, int flag)
{
    if (self) {
        Observer* observer = (Observer*)((char*)self + 4);
        observer->~Observer();

        if ((short)flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
