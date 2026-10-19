#pragma force_active on
typedef unsigned char u8;

struct KirifudaHolder {
    char m_pad[0xC8];
    u8 m_modelType;
};

class Stage {
public:
    u8 getKirifudaModelType(unsigned long id);

private:
    char m_pad[0x98];
    KirifudaHolder* m_kirifuda;
};

u8 Stage::getKirifudaModelType(unsigned long id) {
    if (!m_kirifuda) {
        return 0;
    }
    if (id >= 7) {
        return 0;
    }
    switch ((int)id) {
    case 6:
        return m_kirifuda->m_modelType;
    default:
        return 0;
    }
}
