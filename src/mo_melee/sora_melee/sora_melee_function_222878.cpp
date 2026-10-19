#pragma force_active on
struct CollisionNode {
    CollisionNode* next;
    CollisionNode* prev;
};

struct CollisionList {
    unsigned int count;
    CollisionNode* first;
    CollisionNode* last;
};

extern "C" CollisionList g_grCollisionList;

extern "C" void* fn_27_222878(void*, unsigned int index) {
    CollisionNode* node = g_grCollisionList.first;
    for (unsigned int i = 0; i < index; ++i) {
        node = node->next;
    }
    return reinterpret_cast<char*>(node) - 0x30;
}
