#include <gr/gr_madein.h>
#pragma force_active on

void grMadein::deleteHitPoint()
{
    if (m_hasHitPoint)
        disableHit(0, 0);
}
