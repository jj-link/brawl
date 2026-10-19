#include <types.h>
#pragma force_active on

extern "C" {

class WorkTarget {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void setWork(float value) = 0;
};

struct WorkContainer {
    char _pad[8];
    WorkTarget* m_a;
    WorkTarget* m_b;
};

class FzeroStage {
    char _pad[0x48];
public:
    WorkContainer** m_works;
};

void fn_61_5C54(FzeroStage* this_stage, float value, u32 index) {
    WorkContainer* c = this_stage->m_works[index];
    if (c != 0) {
        c->m_b->setWork(value);
        c->m_a->setWork(value);
    }
}

}
