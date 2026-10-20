#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

struct ObserverBase : soEventObserver<soGimmickEventObserver> {
    ~ObserverBase() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1B08(void* self, short flag)
{
    if (self) {
        ObserverBase* observer = (ObserverBase*)((char*)self + 4);
        observer->~ObserverBase();

        if (flag > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
