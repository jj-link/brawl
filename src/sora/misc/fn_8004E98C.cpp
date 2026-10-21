#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

u32 GameGlobal::getSlowRate() const {
    const u8* app = reinterpret_cast<const u8 *>(m_appData);
    return app[0x8];
}
