#include <types.h>
#pragma force_active on

namespace nw4r {
namespace g3d {
class ResMdl {
public:
    u32 GetResNodeNumEntries();
};

u32 ResMdl::GetResNodeNumEntries() {
    char* p = *(char**)this;
    s32 off = *(s32*)(p + 0x14);
    if (off != 0) {
        p = p + off;
    } else {
        p = 0;
    }
    if (p != 0) {
        return *(u32*)(p + 4);
    }
    return 0;
}
} // namespace g3d
} // namespace nw4r
