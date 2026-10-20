#include <types.h>
#pragma force_active on

class soArchiveDb {
public:
    static void* getManager(u32 id);
};

extern "C" int fn_80045DC0(void* mgr, u32 id, u32 flag);

struct SoArchiveDbUser {
    u8 m_pad[0xc];
    u32 m_id;
};

extern "C" {
bool fn_27_2B2AF4(SoArchiveDbUser* self) {
    u32 id = self->m_id;
    if (id == 0xffff) {
        return true;
    }
    return fn_80045DC0(soArchiveDb::getManager(2), id, 0) == 2;
}
}
