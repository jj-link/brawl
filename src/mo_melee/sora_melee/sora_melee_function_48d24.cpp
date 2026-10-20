#include <types.h>
#pragma force_active on

extern "C" void fn_27_46B60(u8* p);
extern "C" void fn_27_35E54(void* p);

class Arr {
public:
    virtual void v0() = 0;
    virtual u8* at(int i) = 0;
    virtual void v2() = 0;
    virtual int size() = 0;
};

struct Obj {
    int pad1[9];
    int m_24;
    void* m_28;
    int pad2[7];
    Arr* m_arr;
};

extern "C" void fn_27_48D24(void* obj) {
    Obj* this_ = (Obj*)obj;
    int i = 0;
    while (i < this_->m_arr->size()) {
        fn_27_46B60(this_->m_arr->at(i));
        i++;
    }
    this_->m_24 = 0;
    fn_27_35E54((char*)this_ + 0x28);
}
