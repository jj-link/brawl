#pragma force_active on
namespace {
class PikminCleanupTarget {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
};

struct PikminState {
    unsigned int unused0;
    PikminCleanupTarget* target;
    unsigned int unused8;
    unsigned int unusedC;
};
}

extern "C" void fn_113_23014(PikminState* self) {
    if (self->target != 0) {
        self->target->slot20();
    }
    self->unused8 = 0;
    self->unusedC = 0;
}
