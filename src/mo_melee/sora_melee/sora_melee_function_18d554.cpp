#pragma force_active on

extern "C" void fn_27_845D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void* lbl_27_data_25F88[];

class soCollisionAttackEventObserver;

class EventManager {
public:
    virtual void dummy();
    virtual void remove(long);
};

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    unsigned char data[0x28 + 0xc * N];
    ~soEventUnitWithWorkArea();
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    if (data + 0xc != 0 && data + 0x1c != 0) {
        __destroy_arr(data + 0x28, fn_27_845D8, 0xc, N);
    }
    if (this != 0) {
        if (this != 0) {
            short id = *(short*)(data + 4);
            *(void**)this = lbl_27_data_25F88;
            if (id != -1) {
                EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(short*)(data + 4));
                mgr->remove(*(short*)(data + 6));
            }
        }
    }
}

template soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
