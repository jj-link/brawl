#pragma force_active on
class WorkModule {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int getInt(int);
};

struct ModuleAccesser {
    unsigned char reserved[0x64];
    WorkModule* work;
};

struct Fighter {
    unsigned char reserved[0xD8];
    ModuleAccesser* modules;
};

struct CaptainFinalHit {
    unsigned int taskId;
    unsigned char reserved[0x24];
};

extern "C" {
extern CaptainFinalHit* lbl_100_bss_268;

void fn_100_109D4(Fighter* fighter, unsigned int taskId) {
    WorkModule* work = fighter->modules->work;
    int count = work->getInt(0x20000000);
    int i;
    CaptainFinalHit* hit = lbl_100_bss_268;

    for (i = 0; i < count; ++i, ++hit) {
        if (hit->taskId == taskId) {
            hit->taskId = 0xFFFFFFFF;
        }
    }
}
}
