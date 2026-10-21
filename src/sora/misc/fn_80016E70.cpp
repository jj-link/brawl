#include <types.h>
#pragma force_active on

extern "C" void fn_801E9A30(s32);
extern "C" void fn_801E98B0(void);
extern "C" void fn_801FF1AC(void);
extern "C" void VIWaitForRetrace(void);

class gfApplication {
public:
    void reset();
};

void gfApplication::reset()
{
    fn_801E9A30(1);
    fn_801E98B0();
    fn_801FF1AC();
    VIWaitForRetrace();
    VIWaitForRetrace();
}
