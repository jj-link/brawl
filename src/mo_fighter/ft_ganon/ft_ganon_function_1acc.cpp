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

extern "C" void* fn_109_1ACC(void* ptr, short flag) {
    if (ptr) {
        Observer* observer = (Observer*)((char*)ptr + 4);
        observer->~Observer();
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
