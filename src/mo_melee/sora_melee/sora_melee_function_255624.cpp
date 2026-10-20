#include <types.h>
#pragma force_active on

class ipSwitch {
public:
    static ipSwitch* getInstance();
};

extern "C" {
void fn_8004ACA4(void);
void fn_8004AD24(void);

void fn_27_255624() {
    ipSwitch::getInstance();
    fn_8004ACA4();
    ipSwitch::getInstance();
    fn_8004AD24();
}
}
