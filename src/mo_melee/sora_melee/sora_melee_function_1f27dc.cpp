#include <mt/mt_vector.h>
#pragma force_active on

struct DangerZone {
    float minX, minY, maxX, maxY;
    int id;
};

extern "C" int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
    void* self, Vec2f* p1, Vec2f* p2, int index, int special, int flag
) {
    u8* base = reinterpret_cast<u8*>(self);

    if (special || !(*reinterpret_cast<u16*>(base + 0xa2) & 0x100)) {
        int start, end;

        switch (special) {
        case 1:
            start = 8;
            end = 24;
            break;
        default:
            if (*reinterpret_cast<int*>(base + 0x370) == 31)
                return -1;
            start = 0;
            end = 8;
            break;
        }

        if (index < start || index >= end) {
            if (index >= 0)
                return -1;

            for (index = start; index < end; index++) {
                if (base[0x32c + index] == 0)
                    break;
            }

            if ((unsigned int)index >= 24)
                return -1;
        }

        DangerZone* zone = reinterpret_cast<DangerZone*>(base + 0x14c) + index;
        float x2, x1;
        x1 = p1->m_x;
        x2 = p2->m_x;

        if (x1 > x2) {
            zone->maxX = x1;
            zone->minX = x2;
        } else {
            zone->minX = x1;
            zone->maxX = x2;
        }

        float y2, y1;
        y1 = p1->m_y;
        y2 = p2->m_y;

        if (y1 > y2) {
            zone->maxY = y1;
            zone->minY = y2;
        } else {
            zone->minY = y1;
            zone->maxY = y2;
        }

        if ((base + index)[0x32c] == 0) {
            base[0x149]++;
            base[0x32c + index] = flag | 1;
            zone->id = -1;
        }

        return index;
    }

    return -1;
}
