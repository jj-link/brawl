#pragma force_active on
class Ground;

class Ground {
public:
    char pad[0x50];
    Ground* m_next;
};

class Stage {
public:
    void removeGround(Ground* ground);
    char pad[0x88];
    Ground* m_ground;
};

void Stage::removeGround(Ground* ground) {
    Ground* cur = m_ground;
    Ground* prev = 0;
    while (cur != 0) {
        if (cur == ground) {
            break;
        }
        prev = cur;
        cur = cur->m_next;
    }
    if (cur == 0) {
        return;
    }
    Ground* next = cur->m_next;
    if (prev == 0) {
        m_ground = next;
    } else {
        prev->m_next = next;
    }
}
