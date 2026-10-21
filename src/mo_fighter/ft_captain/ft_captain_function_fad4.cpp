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
    unsigned char flags[0x20];
    unsigned char active;
    unsigned char reserved2[3];
};

extern "C" {
extern CaptainFinalHit* lbl_100_bss_268;

bool fn_100_FAD4(unsigned int taskId, Fighter* fighter) {
    WorkModule* work = fighter->modules->work;
    int count = work->getInt(0x20000000);
    int i;
    CaptainFinalHit* hit = lbl_100_bss_268;

    for (i = 0; i < count; ++i, ++hit) {
        if (hit->taskId == taskId && ((unsigned char)hit->active >> 7) & 1) {
            return true;
        }
    }
    return false;
}
}
