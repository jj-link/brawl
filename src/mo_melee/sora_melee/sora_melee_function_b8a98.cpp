#include <it/item.h>
#pragma force_active on
class TestObject {
public:
    virtual void isNull();
    virtual void fn_27_B81C4();
    virtual void fn_27_B8360();
    virtual void fn_27_B83E4();
    virtual void fn_27_B8674();
    virtual void fn_27_B86B0();
    virtual void fn_27_B87B8();
    virtual void fn_27_B88AC();
    virtual void fn_27_B8A98();
    virtual void fn_27_B8B44(int, BaseItem*, int, int, int);
    char padding[0x38];
    int* values;
};
extern "C" void fn_27_B8A98(TestObject* self, BaseItem* item, int a, int b, int c) {
    int value;
    if (item->getParam((itValueAccesser::ParamInt)0x5b69) == 0) {
        if (item->getParam((itValueAccesser::ParamInt)0x5bce) & 2)
            value = self->values[1];
        else
            value = self->values[0];
    } else {
        value = self->values[2];
    }
    self->fn_27_B8B44(value, item, a, b, c);
}