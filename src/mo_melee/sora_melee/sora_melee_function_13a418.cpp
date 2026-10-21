#include <types.h>
#pragma force_active on

namespace {
struct ItemHeader {
    char pad[0x3C];
};

class BaseItem : public ItemHeader {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual int getKind();
};
}

extern "C" int getParam__8BaseItemFQ215itValueAccesser8ParamInt(BaseItem*, int);

extern "C" int fn_27_13A418(void*, BaseItem* item, int* result) {
    if (*result == 2) {
        int v = getParam__8BaseItemFQ215itValueAccesser8ParamInt(item, 0x5bce);
        if ((v & 0x20) == 0)
            *result = 0;
    }
    switch (item->getKind()) {
    case 0x45:
        *result = 1;
        break;
    }
    return 1;
}
