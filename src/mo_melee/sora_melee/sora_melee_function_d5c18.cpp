#pragma force_active on

extern "C" {
extern char lbl_27_data_25948[];
extern char lbl_27_data_25398[];
extern char lbl_27_data_25488[];
extern char lbl_27_data_19918[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF0CC(void*);
void fn_27_84198(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual short add(void*);
};

struct Work {
    char data[0x50];

    void init() {
        data[4] = 0;
        *(void**)(data) = lbl_27_data_25398;
        *(void**)(data + 8) = lbl_27_data_25398 + 0x34;
        *(void**)(data + 12) = lbl_27_data_25398 + 0x40;
        *(void**)(data + 16) = lbl_27_data_25488;
        *(void**)(data + 20) = lbl_27_data_25488 + 0x48;
        *(unsigned int*)(data + 24) &= 0x7ffff;
        __construct_array(data + 28, fn_27_EF0CC, fn_27_84198, 12, 4);
        data[0x4c] = 0;
    }
};

class soModelEventObserver;

template<class T, int N>
struct soEventUnitWithWorkArea {
    void* vptr;
    short managerID;
    short eventID;
    Work* workPtr;
    Work work;

    soEventUnitWithWorkArea(short, short);
};

template<>
soEventUnitWithWorkArea<soModelEventObserver, 4>::soEventUnitWithWorkArea(
    short a, short b)
{
    managerID = a;
    vptr = lbl_27_data_25948;
    eventID = b;

    if (a != -1) {
        short id = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), managerID))->add(this);
        if (id > -1)
            eventID = id;
    }

    workPtr = &work;
    vptr = lbl_27_data_19918;
    ((Work*)((unsigned long)this + 12))->init();
}
