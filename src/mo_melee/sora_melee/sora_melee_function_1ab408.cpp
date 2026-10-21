#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF1BC(void*);
void fn_27_845D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
extern char lbl_27_data_25F88[];
extern char lbl_27_data_3F7B0[];
extern char lbl_27_data_44238[];
extern char lbl_27_data_44330[];
}

struct Manager {
    virtual s16 add(void*);
};

struct Inner {
    void* table;
    u8 flag;
    u8 pad[3];
    void* table8;
    void* tableC;
    void* table10;
    void* table14;
    u32 flags;
    u8 entries[0x30];
    u8 done;
};

class soCollisionAttackEventObserver;

template <class T, int N>
struct soEventUnitWithWorkArea {
    void* table;
    s16 manager;
    s16 slot;
    Inner* inner;
    Inner storage;

    soEventUnitWithWorkArea(s16 manager, s16 slot);
};

template <>
soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::soEventUnitWithWorkArea(
    s16 manager, s16 slot) {
    this->manager = manager;
    this->table = lbl_27_data_25F88;
    this->slot = slot;

    if (manager != -1) {
        Manager* mgr = (Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->manager);
        s16 result = mgr->add(this);
        if (result > -1) {
            this->slot = result;
        }
    }

    Inner* inner = &this->storage;
    this->inner = inner;
    this->table = lbl_27_data_3F7B0;
    inner->flag = 0;
    inner->table = lbl_27_data_44238;
    inner->table8 = lbl_27_data_44238 + 0x34;
    inner->tableC = lbl_27_data_44238 + 0x40;
    inner->table10 = lbl_27_data_44330;
    inner->table14 = lbl_27_data_44330 + 0x48;
    inner->flags &= 0x7FFFF;
    __construct_array(inner->entries, fn_27_EF1BC, fn_27_845D8, 0xC, 4);
    inner->done = 0;
}
