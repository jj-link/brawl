#include <types.h>
#pragma force_active on

namespace nw4r {
    namespace g3d {
        class ResFile {
        public:
            void* m_dataPtr;
            u32 GetResMdlNumEntries() const;
            inline bool IsValid() const { return m_dataPtr != NULL; }
        };
    }
}

struct IceObj {
    char pad[0x40];
    nw4r::g3d::ResFile m_resFile;
};

extern "C" int fn_62_3114(IceObj* self) {
    if (self->m_resFile.IsValid())
        return self->m_resFile.GetResMdlNumEntries();
    return 0;
}
