#pragma force_active on
extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_26028[];
}

struct soEventManager {
    virtual void unused0();
    virtual void remove(int);
};

extern "C" void* fn_27_DAEAC(void* p, int destroy) {
    if (p) {
        short id = *(short*)((char*)p + 0x4);
        *(void**)((char*)p + 0x0) = (void*)lbl_27_data_26028;
        if (id != -1) {
            soEventManager* manager = (soEventManager*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), *(short*)((char*)p + 0x4));
            manager->remove(*(short*)((char*)p + 0x6));
        }
        if (destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
