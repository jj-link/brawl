#pragma force_active on
class Yakumono {
public:
    int getTeam();
};

class grYakumono {
public:
    char pad[0x14c];
    Yakumono* m_yakumono;
    bool getTeamYakumono(int* pi);
};

bool grYakumono::getTeamYakumono(int* pi) {
    if (m_yakumono == 0) {
        return false;
    }
    *pi = m_yakumono->getTeam();
    return true;
}
