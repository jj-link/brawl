#pragma force_active on
extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
extern unsigned char lbl_27_data_42008[];
extern unsigned char lbl_27_data_420F8[];
extern unsigned char lbl_27_data_3D8E8[];
void fn_27_1BA420(void*);
void* fn_27_840D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, unsigned long);
}
class EventManager {
public:
    virtual short addUnit(void*);
};
class soTurnEventObserver;
template <class T> class soEventUnitWrapper {
public:
    static unsigned char __vt[];
    void* vtable;
    short manager;
    short event;
    soEventUnitWrapper(short a, short b) : manager(a) {
        vtable = __vt;
        event = b;
        if (a != -1) {
            short id = ((EventManager*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), manager))->addUnit(this);
            if (id > -1) event = id;
        }
    }
};
struct Work {
    void* vtable;
    unsigned char flag;
    unsigned char pad[3];
    void* table8;
    void* tableC;
    void* table10;
    void* table14;
    unsigned int flags;
    unsigned char elements[24];
    unsigned char last;
    void initialize() {
        flag = 0;
        vtable = lbl_27_data_42008;
        table8 = lbl_27_data_42008 + 0x34;
        tableC = lbl_27_data_42008 + 0x40;
        table10 = lbl_27_data_420F8;
        table14 = lbl_27_data_420F8 + 0x48;
        flags &= 0x003fffff;
        __construct_array(elements, fn_27_1BA420, (void (*)(void*, int))fn_27_840D8, 12, 2);
        last = 0;
    }
};
template <class T, int N> class soEventUnitWithWorkArea : public soEventUnitWrapper<T> {
public:
    Work* workPtr;
    Work work;
    soEventUnitWithWorkArea(short, short);
};
template <class T, int N>
soEventUnitWithWorkArea<T,N>::soEventUnitWithWorkArea(short a, short b)
    : soEventUnitWrapper<T>(a,b), workPtr(&work) {
    *(void**)this = lbl_27_data_3D8E8;
    workPtr->initialize();
}
template soEventUnitWithWorkArea<soTurnEventObserver,2>::soEventUnitWithWorkArea(short,short);
