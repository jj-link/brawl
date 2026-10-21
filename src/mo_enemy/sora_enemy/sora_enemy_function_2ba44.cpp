#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct fnItemList {
    void** items;
    s32 count;
};

class fnSearchBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void procItem(void* item, soModuleAccesser* acc, u32 p3);
    u8 pad[0x64];
    fnItemList* unk68;
};

extern "C" void fn_41_2BA44(fnSearchBase* self, soModuleAccesser* acc) {
    fnItemList* list = self->unk68;
    if (list != nullptr) {
        void** items = list->items;
        if (items != nullptr) {
            s32 count = list->count;
            if (count >= 0) {
                for (s32 i = 0; i < count; i++) {
                    self->procItem(items[i], acc, 0);
                }
            }
        }
    }
}
