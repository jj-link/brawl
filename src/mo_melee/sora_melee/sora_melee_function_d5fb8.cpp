#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF0E4(void*);
void fn_27_84518(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
extern char lbl_27_data_26078[];
extern char lbl_27_data_24DE0[];
extern char lbl_27_data_24ED0[];
extern char lbl_27_data_197A8[];
}

struct Manager {
    virtual short attach(void*);
};

struct Work {
    void* vt;
    unsigned char active;
    void* vt1;
    void* vt2;
    void* vt3;
    void* vt4;
    unsigned int flags;
    char entries[48];
    unsigned char end;

    void init() {
        active = 0;
        vt = lbl_27_data_24DE0;
        vt1 = lbl_27_data_24DE0 + 0x34;
        vt2 = lbl_27_data_24DE0 + 0x40;
        vt3 = lbl_27_data_24ED0;
        vt4 = lbl_27_data_24ED0 + 0x48;
        flags &= 0x7ffff;
        __construct_array(entries, fn_27_EF0E4, fn_27_84518, 12, 4);
        end = 0;
    }
};

struct EventObserver {
    void* vt;
    short id0, id1;

    EventObserver(short a, short b) {
        id0 = a;
        vt = lbl_27_data_26078;
        id1 = b;
        if (a != -1) {
            Manager* mgr = (Manager*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), id0);
            short result = mgr->attach(this);
            if (result > -1)
                id1 = result;
        }
    }
};

struct EventUnit : EventObserver {
    Work* work;

    EventUnit(Work* w, short a, short b) : EventObserver(a, b) {
        work = w;
        vt = lbl_27_data_197A8;
    }
};

class soDamageEventObserver;

template<class T, int N>
struct soEventUnitWithWorkArea : EventUnit {
    Work area;
    soEventUnitWithWorkArea(short a, short b);
};

template<class T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(short a, short b)
    : EventUnit(&area, a, b) {
    work->init();
}

template class soEventUnitWithWorkArea<soDamageEventObserver, 4>;
