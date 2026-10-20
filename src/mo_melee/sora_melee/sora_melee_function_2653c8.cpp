#include <types.h>
#pragma force_active on

class Yakumono {
public:
    void setTeam(int team);
};

extern "C" bool fn_27_2639B8(Yakumono* p, u32 arg);

class grYakumono {
public:
    bool setTeamYakumono(u32 a, u32 b);

private:
    u8 m_pad[0x14c];
    Yakumono* m_yakumono;
};

bool grYakumono::setTeamYakumono(u32 a, u32 b) {
    Yakumono* y = m_yakumono;
    if (y == 0) {
        return false;
    }
    y->setTeam(a);
    fn_27_2639B8(y, b);
    return true;
}
