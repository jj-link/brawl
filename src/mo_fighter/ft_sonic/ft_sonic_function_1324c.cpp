#pragma force_active on
extern "C" void fn_123_132E0(void* out, short a, int b);
extern "C" void fn_27_AA42C(void* out, void* src, void* owner, int flag);

class soGimmickEventObserver;

template <class T> class soEventObserver {
public:
    int getObserverId() const;
};

struct Pair {
    int a;
    int b;
};

struct Dispatch {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual short get();
};

extern "C" void fn_123_1324C(char* self) {
    int observer;
    char* a = *(char**)(self + 0x60);
    char* b = *(char**)(a + 0xd8);
    char* r30 = *(char**)(b + 0x80);

    observer = (short)((soEventObserver<soGimmickEventObserver>*)(self + 0x2158))->getObserverId();

    short other = ((Dispatch*)(r30 + 8))->get();

    int out[2];
    fn_123_132E0(out, other, observer);

    void* owner = *(void**)(self + 0x60);
    Pair pr;
    pr.a = 0x34;
    pr.b = 0;
    fn_27_AA42C(out, &pr, owner, -1);
}
