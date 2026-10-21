#include <types.h>
#pragma force_active on

struct MarioLinkSender {
    unsigned char reserved[0x3c];
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void n5();
    virtual void n6();
    virtual void n7();
    virtual void n8();
    virtual void n9();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual void n26();
    virtual void n27();
    virtual void n28();
    virtual void n29();
    virtual void n30();
    virtual void n31();
    virtual void n32();
    virtual void n33();
    virtual void n34();
    virtual void n35();
    virtual void n36();
    virtual void n37();
    virtual void n38();
    virtual int getCategory();
    virtual int getKind();
};

extern "C" {
void fn_27_12D904(void*, bool, bool, bool);
void fn_27_1324D4(void*, void*, void*, void*, int);
}

extern "C" void fn_91_9A4C(void* self, s32* event, void* accesser,
                            MarioLinkSender* sender, int argument) {
    switch (*event) {
    case 0x3C:
        if (sender->getCategory() == 2) {
            switch (sender->getKind()) {
            case 0x4C:
                fn_27_12D904(self, false, true, false);
                break;
            }
        }
        break;
    }
    fn_27_1324D4(self, event, accesser, sender, argument);
}
