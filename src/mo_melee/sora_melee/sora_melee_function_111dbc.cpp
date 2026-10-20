#pragma force_active on
typedef unsigned char u8;

struct ftOwnerData {
    u8 pad[0x1c];
    u8 m_hi : 4;
    u8 m_rabbitCap : 1;
    u8 m_lo : 3;
};

class ftOwner {
public:
    ftOwnerData* m_data;
    void setRabbitCap(bool flag);
};

void ftOwner::setRabbitCap(bool flag) {
    m_data->m_rabbitCap = flag;
}
