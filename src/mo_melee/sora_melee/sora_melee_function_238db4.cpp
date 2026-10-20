#pragma force_active on
class stMelee {
public:
    void setPlayerPositionIndexSerial();
private:
    char m_pad[0x1b4];
    int m_playerPositionIndexSerial[4];
};

void stMelee::setPlayerPositionIndexSerial() {
    m_playerPositionIndexSerial[0] = 0;
    m_playerPositionIndexSerial[1] = 1;
    m_playerPositionIndexSerial[2] = 2;
    m_playerPositionIndexSerial[3] = 3;
}
