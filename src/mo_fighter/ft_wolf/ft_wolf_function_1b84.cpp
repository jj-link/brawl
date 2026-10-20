#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class ObserverPart : public soEventObserver<soGimmickEventObserver> {
public:
    ~ObserverPart() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_1B84(void* self, short flag) {
    if (self) {
        ObserverPart* observer = (ObserverPart*)((char*)self + 4);
        observer->~ObserverPart();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
