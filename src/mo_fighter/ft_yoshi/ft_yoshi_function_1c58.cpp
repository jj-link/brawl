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

extern "C" void* fn_95_1C58(void* self, int flag)
{
    if (self) {
        ObserverBase* observer = (ObserverBase*)((char*)self + 4);
        observer->~ObserverBase();

        if ((short)flag > 0)
            __dl__FPv(self);
    }

    return self;
}
