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
    Data& ref() const { return *mpData; }
    Data* ptr() const { return mpData; }
};

extern "C" void fn_80192784(Res self, void* dst) {
    if (self.IsValid()) {
        u32 size = self.ref().size;
        fn_8019DFAC(dst, self.ptr(), size);
        fn_801D7718(dst, size);
    }
}
