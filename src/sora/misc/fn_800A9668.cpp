#pragma force_active on
class utListNode;

extern "C" void removeExist__6utListFP10utListNode(void* list, void* node);

class cmPhotoController {
public:
    void removeCallBack(utListNode* node);

private:
    char m_pad[0xAC];
    void* m_callBacks;
};

void cmPhotoController::removeCallBack(utListNode* node) {
    if (node == 0) {
        return;
    }
    removeExist__6utListFP10utListNode(&m_callBacks, node);
}
