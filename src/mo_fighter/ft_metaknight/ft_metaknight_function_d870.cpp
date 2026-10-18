#include <types.h>
#pragma force_active on

struct MetaKnightVirtualObject {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 query(s32 index);
};

extern "C" s32 fn_111_D870(u8* self) {
    s32 index = 0x20000003;
    while (index < 0x2000000A) {
        MetaKnightVirtualObject* object = *(MetaKnightVirtualObject**)(*(u8**)(self + 0xD8) + 0x64);
        if (object->query(index) == -1) {
            return index;
        }
        index++;
    }
    return -1;
}
