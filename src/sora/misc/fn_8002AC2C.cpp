#pragma force_active on
struct GamePadQueue {
    unsigned short head;
    unsigned short tail;
};

class gfPadSystem {
public:
    unsigned short getGamePadQueueCount();
    char pad_000[0x240];
    GamePadQueue* queue;
};

unsigned short gfPadSystem::getGamePadQueueCount() {
    int n = (int)queue->tail - (int)queue->head;
    if (n < 0) {
        n += 4;
    }
    return (unsigned short)n;
}
