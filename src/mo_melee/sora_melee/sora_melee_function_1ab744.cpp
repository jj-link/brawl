#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_25F38[];
extern char lbl_27_data_437E0[];
extern char lbl_27_data_438D8[];
extern char lbl_27_data_3F4C8[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF204(void*);
void fn_27_842D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual s16 attach(void*);
};

struct Inner {
    void* vtable;
    u8 enabled;
    u8 pad[3];
    void* v14;
    void* v18;
    void* v1c;
    void* v20;
    u32 flags;
    u8 array[48];
    u8 tail;
};

class soCollisionAbsorberEventObserver;

template<class T, int N>
struct soEventUnitWithWorkArea {
    void* vtable;
    s16 id;
    s16 index;
    Inner* ptr;
    Inner inner;

    soEventUnitWithWorkArea(s16, s16);
};

template<>
soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>::soEventUnitWithWorkArea(
    s16 id, s16 index) {
    this->id = id;
    this->vtable = lbl_27_data_25F38;
    this->index = index;

    if (id != -1) {
        Manager* manager = (Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->id);
        s16 result = manager->attach(this);
        if (result > -1) {
            this->index = result;
        }
    }

    Inner* inner = &this->inner;
    this->ptr = inner;
    this->vtable = lbl_27_data_3F4C8;
    inner->enabled = 0;
    inner->vtable = lbl_27_data_437E0;
    inner->v14 = lbl_27_data_437E0 + 0x34;
    inner->v18 = lbl_27_data_437E0 + 0x40;
    inner->v1c = lbl_27_data_438D8;
    inner->v20 = lbl_27_data_438D8 + 0x48;
    inner->flags &= 0x0007FFFF;
    __construct_array(inner->array, fn_27_EF204, fn_27_842D8, 12, 4);
    inner->tail = 0;
}
