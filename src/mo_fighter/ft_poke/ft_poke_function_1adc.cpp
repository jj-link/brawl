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

extern "C" void* fn_116_1ADC(void* object, int flag) {
    if (object) {
        ((Observer*)((char*)object + 4))->~Observer();
        if ((short)flag > 0)
            __dl__FPv(object);
    }
    return object;
}
