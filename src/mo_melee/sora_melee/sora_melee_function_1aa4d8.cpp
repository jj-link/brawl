#pragma force_active on

typedef short s16;
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_26028[];
extern char lbl_27_data_427D8[];
extern char lbl_27_data_428C8[];
extern char lbl_27_data_3DAE8[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF12C(void*);
void fn_27_84458(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual s16 add(void*);
};

struct Work {
    void* vt;
    unsigned char active;
    void* a;
    void* b;
    void* c;
    void* d;
    u32 flags;
    char entries[0x1E0];
    unsigned char end;
};

class soAnimCmdEventObserver;

template<class T, int N>
struct soEventUnitWithWorkArea {
    void* vt;
    s16 manager;
    s16 id;
    Work* work;
    Work data;

    soEventUnitWithWorkArea(s16, s16);
};

template<>
soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>::soEventUnitWithWorkArea(
    s16 manager, s16 id)
{
    this->manager = manager;
    vt = lbl_27_data_26028;
    this->id = id;

    if (manager != -1) {
        s16 result = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->manager))->add(this);
        if (result > -1)
            this->id = result;
    }

    Work* work = &data;
    this->work = work;
    vt = lbl_27_data_3DAE8;
    work->active = 0;
    work->vt = lbl_27_data_427D8;
    work->a = lbl_27_data_427D8 + 0x34;
    work->b = lbl_27_data_427D8 + 0x40;
    work->c = lbl_27_data_428C8;
    work->d = lbl_27_data_428C8 + 0x48;
    work->flags &= 0x3FF;
    __construct_array(work->entries, fn_27_EF12C, fn_27_84458, 0xC, 0x28);
    work->end = 0;
}
