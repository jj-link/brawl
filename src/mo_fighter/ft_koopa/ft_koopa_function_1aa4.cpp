#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

struct Wrapper : soEventObserver<soGimmickEventObserver> {
    ~Wrapper() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_1AA4(void* self, short flag) {
    if (self) {
        ((Wrapper*)((char*)self + 4))->~Wrapper();
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
