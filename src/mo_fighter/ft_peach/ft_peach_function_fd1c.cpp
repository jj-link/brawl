#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

struct FtObjGet {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25();
    virtual void* get28();
};

struct FtObjSet {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25();
    virtual void* set28(void* value);
};

extern "C" {
void* fn_103_FD1C(void* self, void* unused, void* value) {
    void* src = static_cast<FtObjGet*>(self)->get28();
    void* dst = static_cast<FtObjSet*>(self)->set28(value);
    *static_cast<f32*>(dst) = *static_cast<f32*>(src);
    return dst;
}
}
