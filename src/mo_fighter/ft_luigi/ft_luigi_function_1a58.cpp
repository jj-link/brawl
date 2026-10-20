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

extern "C" void* fn_99_1A58(void* object, short deleting) {
    if (object) {
        Observer* base = (Observer*)((char*)object + 4);
        base->~Observer();
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
