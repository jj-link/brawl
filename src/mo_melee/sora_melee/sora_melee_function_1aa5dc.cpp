#pragma force_active on

extern "C" void fn_27_84458(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_26028[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class soAnimCmdEventObserver;

class soEventManagerBase {
public:
    virtual void vf0();
    virtual void vf1(long v);
};

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    void* vt;
    short m4;
    short m6;
    unsigned char pad[0x28 - 8];
    ~soEventUnitWithWorkArea();
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    if ((unsigned char*)this + 0xc != 0 &&
        (unsigned char*)this + 0x1c != 0) {
        __destroy_arr((unsigned char*)this + 0x28, fn_27_84458, 0xc, N);
    }
    if (this != 0 && this != 0) {
        short id = this->m4;
        this->vt = lbl_27_data_26028;
        if (id != -1) {
            soEventManagerBase* mgr =
                (soEventManagerBase*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), this->m4);
            mgr->vf1(this->m6);
        }
    }
}

template class soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>;
