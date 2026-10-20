#pragma force_active on
template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class soGimmickEventObserver
    : public soEventObserver<soGimmickEventObserver> {
public:
    ~soGimmickEventObserver() {}
};

struct Object {
    unsigned int padding;
    soGimmickEventObserver observer;
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_1BB4(Object* self, short flag) {
    if (self) {
        self->observer.~soGimmickEventObserver();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
