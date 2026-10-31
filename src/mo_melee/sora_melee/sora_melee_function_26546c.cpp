#include <types.h>
#include <so/collision/so_collision_log.h>
#include <yk/yakumono.h>
#pragma force_active on

class grYakumono {
protected:
    char m_pad[0x14c];
    Yakumono* m_yakumono;

public:
    void setOffsetAttack(Vec3f* offsetPos, int index);
};

extern "C" {
    void fn_27_263818(Yakumono* p, Vec3f* offsetPos, int index);
}

void grYakumono::setOffsetAttack(Vec3f* offsetPos, int index) {
    if (m_yakumono != 0)
        fn_27_263818(m_yakumono, offsetPos, index);
}
