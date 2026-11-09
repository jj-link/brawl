#include <types.h>
#pragma force_active on
struct Inner { char pad[0x28]; unsigned int target; };
class ArrayEntry { public: char pad[4]; Inner* value; };
class Array {
public:
    virtual void v0();
    virtual ArrayEntry* at(int);
    virtual void v2();
    virtual int size();
};
class soNullable {
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
virtual void fn_27_B8B44();
virtual void fn_27_BC19C();
virtual void fn_27_B91FC();
virtual void fn_27_B86D4();
virtual void fn_27_BE4F0();
virtual void fn_27_B83F4();
virtual void fn_27_B8434();
virtual void fn_27_B8468();
virtual void fn_27_B849C();
virtual void fn_27_B84D0();
virtual void fn_27_B8548();
virtual void fn_27_B8594();
virtual void fn_27_B85E0();
virtual void fn_27_BE4E8();
virtual void fn_27_BE4E0();
virtual void fn_27_BE4D8();
virtual void fn_27_B8648();
virtual void fn_27_B8780();
virtual void fn_27_BC0A4();
virtual void fn_27_BC0BC();
virtual void fn_27_B9918();
virtual void fn_27_B9D20();
virtual void fn_27_BA1C8();
virtual void fn_27_BA600();
virtual void fn_27_BA514();
virtual void fn_27_BA594();
virtual void fn_27_BA714();
virtual void fn_27_BA9B8();
virtual void fn_27_BAA38();
virtual void fn_27_BAAAC();
virtual void fn_27_BAB24();
virtual void fn_27_BAC38();
virtual void fn_27_BACD4();
virtual void fn_27_BB040();
virtual void fn_27_BB0C0();
virtual void fn_27_BB14C();
virtual void fn_27_B9108();
virtual void fn_27_B9878();
virtual void fn_27_B97FC();
virtual void fn_27_B9810();
virtual void fn_27_BB658();
virtual void fn_27_BE4D0();
virtual void fn_27_BB398(unsigned int, int, int);
virtual void fn_27_BB7B4(unsigned int, int, int);
char pad[0x34];
Array* list38;
char pad2[4];
Array* list40;
};
extern "C" void fn_27_BB24C(soNullable* self, unsigned int target) {
    int count = self->list38->size();
    for (int i = 0; i < count; ++i) {
        if (self->list38->at(i)->value != 0) {
            if (target == self->list38->at(i)->value->target)
                self->fn_27_BB398(i, 0, 1);
        }
    }
    int i = self->list40->size() - 1;
    for (; i >= 0; --i) {
        if (target == self->list40->at(i)->value->target)
            self->fn_27_BB7B4(i, 0, 1);
    }
}
