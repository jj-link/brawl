#include <types.h>
#pragma force_active on

extern "C" u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void* resFile);

class Ground {
public:
    u32 getModelCount();

private:
    u8 m_pad[0x40];
    void* m_resFile;
};

u32 Ground::getModelCount() {
    if (m_resFile != 0) {
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&m_resFile);
    }
    return 0;
}
