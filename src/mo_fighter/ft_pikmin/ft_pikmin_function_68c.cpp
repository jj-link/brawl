#pragma force_active on
template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class soGimmickEventObserver : public soEventObserver<soGimmickEventObserver> {
public:
    ~soGimmickEventObserver() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_68C(void* self, short flag) {
    if (self) {
        ((soGimmickEventObserver*)((char*)self + 4))->~soGimmickEventObserver();
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
