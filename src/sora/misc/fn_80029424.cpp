#pragma force_active on
class gfPadStatusQueue {
public:
    void clear();
};

class gfPadSystem {
public:
    void clearPadQueue();

private:
    char pad[0x240];
    gfPadStatusQueue* m_padQueue;
};

void gfPadSystem::clearPadQueue() {
    if (m_padQueue) {
        m_padQueue->clear();
    }
}
