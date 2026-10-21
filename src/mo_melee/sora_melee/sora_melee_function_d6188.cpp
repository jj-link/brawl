#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_24DB8[];
extern char lbl_27_data_24A08[];
extern char lbl_27_data_24AF8[];
extern char lbl_27_data_196C8[];
void fn_27_EF0FC(void*);
void* fn_27_84298(void*, int);
void __construct_array(void*, void*, void*, unsigned long, unsigned long);
}

struct EventManager {
    virtual short addUnit(void*);
};

class soMotionEventObserver {};

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    soEventUnitWithWorkArea(short, short);
};

template<class T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(short manager, short event) {
    char* self = (char*)this;
    *(short*)(self + 4) = manager;
    *(void**)(self + 0) = lbl_27_data_24DB8;
    *(short*)(self + 6) = event;

    if (manager != -1) {
        short result = ((EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), *(short*)(self + 4)))->addUnit(this);
        if (result > -1)
            *(short*)(self + 6) = result;
    }

    char* sub = self + 12;
    *(void**)(self + 8) = sub;
    *(void**)(self + 0) = lbl_27_data_196C8;
    sub[4] = 0;
    *(void**)(sub + 0) = lbl_27_data_24A08;
    *(void**)(sub + 8) = lbl_27_data_24A08 + 0x34;
    *(void**)(sub + 12) = lbl_27_data_24A08 + 0x40;
    *(void**)(sub + 16) = lbl_27_data_24AF8;
    *(void**)(sub + 20) = lbl_27_data_24AF8 + 0x48;
    *(unsigned int*)(sub + 24) &= 0x01ffffff;
    __construct_array(sub + 28, (void*)fn_27_EF0FC,
                      (void*)fn_27_84298, 12, 1);
    sub[40] = 0;
}

template class soEventUnitWithWorkArea<soMotionEventObserver, 1>;
