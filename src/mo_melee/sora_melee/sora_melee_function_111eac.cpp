#pragma force_active on
typedef unsigned char u8;

struct ftOwnerData {
    u8 pad[0x1C];
    u8 a : 3;
    u8 flower : 1;
    u8 b : 4;
};

class ftOwner {
public:
    ftOwnerData* m_data;
    void setFlower(bool flag);
};

void ftOwner::setFlower(bool flag) {
    m_data->flower = flag;
}
