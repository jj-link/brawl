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

extern "C" void* fn_104_1B48(void* object, int flag) {
    if (object) {
        ((ObserverHolder*)((char*)object + 4))->~ObserverHolder();
        if ((short)flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
