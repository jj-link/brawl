#pragma force_active on
extern "C" bool fn_27_2639B8(void* p);

class grYakumono {
public:
    bool setTeamYakumonoOwnerId(unsigned long id);
    char pad[0x14c];
    void* m_ownerPtr;
};

bool grYakumono::setTeamYakumonoOwnerId(unsigned long id) {
    if (m_ownerPtr == 0) {
        return false;
    }
    fn_27_2639B8(m_ownerPtr);
    return true;
}
