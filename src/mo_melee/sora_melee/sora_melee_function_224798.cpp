#pragma force_active on
struct cmAIController {
    unsigned char pad[0x94];
    unsigned char flags;
};

extern cmAIController* g_cmAIController;

class Stage {
public:
    void enableDevil();
    unsigned char pad[0xEB];
    unsigned char devil;
};

void Stage::enableDevil() {
    devil = 1;
    g_cmAIController->flags |= 0x80;
}
