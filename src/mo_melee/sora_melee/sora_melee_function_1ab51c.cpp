#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
extern char lbl_27_data_25F60[];
extern char lbl_27_data_3F430[];
extern char lbl_27_data_435C8[];
extern char lbl_27_data_436C0[];
void fn_27_EF1D4(void*);
void* fn_27_84218(void*, int);
void __construct_array(void*, void (*)(void*), void* (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual short add(void*);
};

extern "C" Manager* getManager__13soEventSystemFl(void*, long);

struct Work {
    void* vtable;
    char flag;
    char pad[3];
    void* vtable2;
    void* vtable3;
    void* vtable4;
    void* vtable5;
    unsigned flags;
    char array[48];
    char end;
};

class soCollisionSearchEventObserver;

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    void* vtable;
    short manager;
    short event;
    Work* work;
    Work inner;

    soEventUnitWithWorkArea(short, short);
};

template<class T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(short manager, short event) {
    this->manager = manager;
    this->vtable = lbl_27_data_25F60;
    this->event = event;

    if (manager != -1) {
        short id = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->manager)->add(this);
        if (id > -1)
            this->event = id;
    }

    Work* work = &this->inner;
    this->work = work;
    this->vtable = lbl_27_data_3F430;
    work->flag = 0;
    work->vtable = lbl_27_data_435C8;
    work->vtable2 = lbl_27_data_435C8 + 0x34;
    work->vtable3 = lbl_27_data_435C8 + 0x40;
    work->vtable4 = lbl_27_data_436C0;
    work->vtable5 = lbl_27_data_436C0 + 0x48;
    work->flags &= 0x7FFFF;
    __construct_array(work->array, fn_27_EF1D4, fn_27_84218, 12, 4);
    work->end = 0;
}

template class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>;
