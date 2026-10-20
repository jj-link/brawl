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

extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1BE0(void* self, short flag)
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
