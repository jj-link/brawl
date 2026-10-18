#pragma force_active on
struct StageNode {
    char pad[0x50];
    StageNode* next;
};

class Stage {
public:
    int getGroundNum();
    char pad[0x88];
    StageNode* m_88;
};

int Stage::getGroundNum() {
    StageNode* n = m_88;
    int count = 0;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
