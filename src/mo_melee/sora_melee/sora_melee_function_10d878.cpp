#pragma force_active on
class ftEntity;

class ftEntryManager {
public:
    ftEntity* getEntity(unsigned long idx);
};

extern "C" unsigned int fn_27_115968(ftEntity* entity, bool flag);
extern "C" void* fn_27_14D594();

class ftManager {
public:
    void setFinal(int state, bool flag);

    char pad0[0x70];
    int m_70;
    int m_74;
    void* m_78;
    char pad1[0x154 - 0x7C];
    ftEntryManager* m_154;
};

void ftManager::setFinal(int state, bool flag) {
    if (state != m_74) {
        ftEntity* entity = m_154->getEntity(state);
        if (fn_27_115968(entity, flag) == 1) {
            m_74 = state;
            m_70 = -1;
            if (flag == 1) {
                m_78 = fn_27_14D594();
            }
        }
    }
}
