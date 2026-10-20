#pragma force_active on
template <class T> class soEventObserver {
    int data;
public:
    ~soEventObserver();
};

class soGimmickEventObserver : public soEventObserver<soGimmickEventObserver> {
public:
    ~soGimmickEventObserver() {}
};

struct Object {
    int padding;
    soGimmickEventObserver observer;
};

extern "C" void __dl__FPv(void*);

extern "C" Object* fn_96_20C0(Object* self, short flag)
{
    if (self) {
        self->observer.~soGimmickEventObserver();
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
