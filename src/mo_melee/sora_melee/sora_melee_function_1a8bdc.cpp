#pragma force_active on

typedef signed short s16;
typedef unsigned int u32;

struct EventManager {
    virtual s16 addUnit(void*);
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" EventManager* getManager__13soEventSystemFl(void*, long);
extern "C" void fn_27_1BA420(void*);
extern "C" void* fn_27_840D8(void*, int);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, unsigned long);
extern "C" unsigned char lbl_27_data_335C0[];
extern "C" unsigned char lbl_27_data_41A08[];
extern "C" unsigned char lbl_27_data_41AF8[];

class soTurnEventObserver;

template <class T> struct soEventUnitWrapper {
    static unsigned char __vt[];
};

struct Work {
    void* vtable;
    unsigned char flag;
    unsigned char pad[3];
    void* table14;
    void* table18;
    void* table1c;
    void* table20;
    u32 flags;
    unsigned char array[0x54];
    unsigned char end;
};

struct Object {
    void* vtable;
    s16 manager;
    s16 event;
    Work* workPtr;
    Work work;
};

extern "C" Object* fn_27_1A8BDC(Object* self, s16 manager, s16 event) {
    self->manager = manager;
    self->vtable = soEventUnitWrapper<soTurnEventObserver>::__vt;
    self->event = event;

    if (manager != -1) {
        s16 id = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager)->addUnit(self);
        if (id > -1) {
            self->event = id;
        }
    }

    Work* work = &self->work;
    self->workPtr = work;
    self->vtable = lbl_27_data_335C0;
    work->flag = 0;
    work->vtable = lbl_27_data_41A08;
    work->table14 = lbl_27_data_41A08 + 0x34;
    work->table18 = lbl_27_data_41A08 + 0x40;
    work->table1c = lbl_27_data_41AF8;
    work->table20 = lbl_27_data_41AF8 + 0x48;
    work->flags &= 0x7FFFF;

    __construct_array(work->array, fn_27_1BA420,
                      (void (*)(void*, int))fn_27_840D8, 0xC, 7);

    work->end = 0;
    return self;
}
