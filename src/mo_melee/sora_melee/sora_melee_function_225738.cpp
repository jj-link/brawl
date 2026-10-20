#pragma force_active on
class Stage {
public:
    char pad[0x188];
    unsigned long m188;
    float m18c;
    void getBgmChangeID(unsigned long* p1, float* p2);
};

void Stage::getBgmChangeID(unsigned long* p1, float* p2) {
    *p1 = m188;
    *p2 = m18c;
}
