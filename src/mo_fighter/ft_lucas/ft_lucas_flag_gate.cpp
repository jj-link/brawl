#include <so/work/so_general_work_simple.h>

class LucasFlagGateView : public soGeneralWorkSimple {
public:
    virtual void offFlag(u32 mask, u32 index);
    virtual bool isFlag(u32 mask, u32 index) const;
};

extern "C" u32 fn_114_CD2C(soGeneralWorkSimple* work, u32 mask, u32 index) {
    u32 result;
    if ((result = reinterpret_cast<LucasFlagGateView*>(work)->isFlag(mask, index)) == 1) {
        reinterpret_cast<LucasFlagGateView*>(work)->offFlag(mask, index);
    }
    return result;
}
