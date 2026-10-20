#pragma force_active on
typedef unsigned char u8;

struct ftOwnerData {
    u8 pad[0x1f];
    u8 f7 : 1;
    u8 f6 : 1;
    u8 rest : 6;
};

class ftOwner {
public:
    ftOwnerData *m_data;
    void setFinal(bool a, bool b);
};

void ftOwner::setFinal(bool a, bool b) {
    m_data->f7 = a;
    m_data->f6 = b;
}
