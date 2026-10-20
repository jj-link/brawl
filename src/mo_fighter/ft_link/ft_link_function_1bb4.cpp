#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

struct ObserverHolder : soEventObserver<soGimmickEventObserver> {
    ~ObserverHolder() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_1BB4(void* self, int flag)
{
    if (self) {
        ObserverHolder* observer = (ObserverHolder*)((char*)self + 4);
        observer->~ObserverHolder();
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
