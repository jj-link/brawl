#pragma force_active on
class utListNode;

class utList {
public:
    int isExistNode(utListNode* node) const;
    void remove(utListNode* node);
};

extern "C" void fn_27_6F3CC(utList* list, utListNode* node) {
    if (list->isExistNode(node) != -1) {
        list->remove(node);
    }
}
