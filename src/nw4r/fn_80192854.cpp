#pragma force_active on
#include <types.h>

extern "C" void fn_8019DFAC(void*, const void*, u32);
extern "C" void fn_801D7718(void*, u32);

struct Data {
    u32 size;
};

struct Res {
    Data* mpData;
    bool IsValid() const { return mpData != 0; }
    Data* ptr() const { return mpData; }
    Data& ref() const { return *mpData; }
};

extern "C" void fn_80192854(Res res, void* dst) {
    if (res.IsValid()) {
        u32 size = res.ref().size;
        fn_8019DFAC(dst, res.ptr(), size);
        fn_801D7718(dst, size);
    }
}
