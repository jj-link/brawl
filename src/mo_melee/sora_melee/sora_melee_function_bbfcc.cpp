#include <types.h>
#pragma force_active on

class itValueAccesser {
public:
    enum ParamInt { kParamInt = 0 };
};

class BaseItem {
public:
    int getParam(itValueAccesser::ParamInt);
};

extern "C" {
void fn_27_28F6D4(void*, int, int, float, float);

void fn_27_BBFCC(void* a, BaseItem* item, float value) {
    int r = item->getParam((itValueAccesser::ParamInt)0x5bcc);
    fn_27_28F6D4(item, r, 1, value, value);
}
}
