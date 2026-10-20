#pragma force_active on
class soVirtualInner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

class soVirtualOuter {
public:
    char pad[0x10];
};

extern "C" {
void fn_27_1C9E44(soVirtualOuter* self) {
    ((soVirtualInner*)((char*)self + 0x10))->v8();
}
}
