#pragma force_active on
class Ground;

class Stage {
public:
    void addGround(Ground* ground);
    char pad[0x88];
    Ground* m_head;
};

class Ground {
public:
    char pad[0x50];
    Ground* next;
};

void Stage::addGround(Ground* ground) {
    Ground* cur = m_head;
    if (cur == 0) {
        m_head = ground;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = ground;
}
