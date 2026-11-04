#include <it/item.h>
#pragma force_active on

extern const float lbl_27_rodata_46DC;

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual int fn_27_14B80();
};

class Class_14370 {
public:
    virtual void fn_27_93100();
    virtual void fn_27_9329C();
    virtual void fn_27_932A0();
    virtual void fn_27_93778();
    virtual Vec3f fn_27_95264();
    virtual void fn_27_93860();
    virtual void fn_27_94198();
    virtual void fn_27_942B4();
    virtual void fn_27_943C4();
    virtual void fn_27_944D4();
    virtual void fn_27_94748();
    virtual void fn_27_9483C();
    virtual void fn_27_94930();
    virtual void fn_27_94E00();
    virtual void fn_27_94C38();
    virtual void fn_27_93B80();
    virtual void fn_27_93F8C();
};

extern "C" int fn_27_29BEF4(void*, BaseItem* item, void*, unsigned char* arg) {
    unsigned char* p = (unsigned char*)item;
    Class_1250* status = *(Class_1250**)(*(unsigned char**)(p + 0x1a4) + 0x70);
    if (status->fn_27_14B80() != 6 && ((arg[0x45] >> 2) & 1)) {
        Class_14370* obj = *(Class_14370**)(*(unsigned char**)(*(unsigned char**)(p + 0x60) + 0xd8) + 0xc);
        Vec3f pos = obj->fn_27_95264();
        item->sendTouchMessage(*(int*)(arg + 0x40), &pos, lbl_27_rodata_46DC);
    }
    return 1;
}