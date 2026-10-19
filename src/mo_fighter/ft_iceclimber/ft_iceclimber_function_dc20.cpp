#include <types.h>
#pragma force_active on

class WorkImpl {
public:
    void* field_0;
    void* field_4;
};

#define DUMMY(n) virtual void dummy##n() {}

class Work : public WorkImpl {
public:
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4) DUMMY(5)
    DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9) DUMMY(10) DUMMY(11)
    DUMMY(12) DUMMY(13) DUMMY(14) DUMMY(15) DUMMY(16) DUMMY(17)
    DUMMY(18) DUMMY(19)
    virtual void offFlag(u32 flag, u32 index);
    virtual void dummy20();
    virtual u32 isFlag(u32 flag, u32 index);
};

extern "C" u32 fn_105_DC20(Work* work, u32 flag, u32 index) {
    u32 result = work->isFlag(flag, index);
    if (result == 1) {
        work->offFlag(flag, index);
    }
    return result;
}
