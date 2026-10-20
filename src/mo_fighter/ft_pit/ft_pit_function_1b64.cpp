#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
    int data;

public:
    ~soEventObserver();
};

struct PitObserver : soEventObserver<soGimmickEventObserver> {
    ~PitObserver() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_1B64(void* p, int flag) {
    if (p) {
        ((PitObserver*)((char*)p + 4))->~PitObserver();
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
