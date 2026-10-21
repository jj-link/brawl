#include <types.h>
#pragma force_active on

class Work {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18(u32) = 0;
    virtual void v19(u32) = 0;
};

class Status {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21(int, void*) = 0;
};

class Module {
public:
    u32 pad0;
    u32 pad1;
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
};

extern "C" void fn_27_1903AC(void* unused, u8* p) {
    u8* modules = *(u8**)(p + 0xd8);
    Work* work = *(Work**)(modules + 0x64);
    Status* status = *(Status**)(modules + 0x7c);

    work->v18(0x12000001);
    work->v19(0x12000019);
    work->v19(0x1200001a);

    status->v21(0xc, p);
    status->v9();
    status->v12();

    Module* a = *(Module**)(*(u8**)(p + 0xd8) + 0x9c);
    a->v6();

    Module* b = *(Module**)(*(u8**)(p + 0xd8) + 0xb8);
    b->v12();
}
