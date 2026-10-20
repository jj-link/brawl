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

extern "C" void* fn_120_1B3C(void* p, short flag) {
    if (p) {
        ObserverBase* observer = (ObserverBase*)((char*)p + 4);
        observer->~ObserverBase();
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
