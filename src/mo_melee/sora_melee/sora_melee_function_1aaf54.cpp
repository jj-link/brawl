#pragma force_active on

extern "C" {
extern char lbl_27_data_31C10[];
extern char lbl_27_data_43200[];
extern char lbl_27_data_432F0[];
extern char lbl_27_data_3F350[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_1BA408(void*);
void fn_27_841D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct EventManager {
    virtual short addUnit(void*);
};

class soItemManageEventObserver;

template<class T, int N>
class soEventUnitWithWorkArea {
    char data[0x38];

public:
    soEventUnitWithWorkArea(short, short);
};

template<class T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(short manager, short event) {
    char* self = (char*)this;
    *(void**)self = lbl_27_data_31C10;
    *(short*)(self + 4) = manager;
    *(short*)(self + 6) = event;

    if (manager != -1) {
        short id = ((EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), *(short*)(self + 4)))->addUnit(this);
        if (id > -1)
            *(short*)(self + 6) = id;
    }

    char* work = self + 0xC;
    *(void**)(self + 8) = work;
    *(void**)self = lbl_27_data_3F350;
    work[4] = 0;
    *(void**)(work + 0) = lbl_27_data_43200;
    *(void**)(work + 8) = lbl_27_data_43200 + 0x34;
    *(void**)(work + 0xC) = lbl_27_data_43200 + 0x40;
    *(void**)(work + 0x10) = lbl_27_data_432F0;
    *(void**)(work + 0x14) = lbl_27_data_432F0 + 0x48;
    *(unsigned int*)(work + 0x18) &= 0x01FFFFFF;
    __construct_array(work + 0x1C, fn_27_1BA408, fn_27_841D8, 0xC, 1);
    work[0x28] = 0;
}

template class soEventUnitWithWorkArea<soItemManageEventObserver, 1>;
