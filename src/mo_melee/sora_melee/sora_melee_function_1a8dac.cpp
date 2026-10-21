#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
struct EventManager;
EventManager* getManager__13soEventSystemFl(void*, long);
void fn_27_1BA420(void*);
void* fn_27_840D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
extern unsigned char lbl_27_data_33530[];
extern unsigned char lbl_27_data_41808[];
extern unsigned char lbl_27_data_418F8[];
}

struct EventManager {
    virtual short addUnit(void*);
};

class soTurnEventObserver;

template<class T> struct soEventUnitWrapper {
    static unsigned char __vt[];
};

struct Work {
    void* vtable;
    unsigned char flag;
    unsigned char pad[3];
    void* p8;
    void* pc;
    void* p10;
    void* p14;
    unsigned int flags;
    unsigned char array[0x60];
    unsigned char tail;
};

struct Object {
    void* vtable;
    short managerId;
    short eventId;
    Work* work;
    Work inner;
};

extern "C" Object* fn_27_1A8DAC(Object* self, short a, short b) {
    self->managerId = a;
    self->vtable = soEventUnitWrapper<soTurnEventObserver>::__vt;
    self->eventId = b;
    if (a != -1) {
        short id = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->managerId)->addUnit(self);
        if (id > -1)
            self->eventId = id;
    }

    Work* w = &self->inner;
    self->work = w;
    self->vtable = lbl_27_data_33530;
    w->flag = 0;
    w->vtable = lbl_27_data_41808;
    w->p8 = lbl_27_data_41808 + 0x34;
    w->pc = lbl_27_data_41808 + 0x40;
    w->p10 = lbl_27_data_418F8;
    w->p14 = lbl_27_data_418F8 + 0x48;
    w->flags &= 0xFFFF;
    __construct_array(w->array, fn_27_1BA420,
                      (void (*)(void*, int))fn_27_840D8, 0xC, 8);
    w->tail = 0;
    return self;
}
