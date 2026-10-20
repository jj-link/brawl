#pragma force_active on
extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_26050[];
}

struct EventManager {
    virtual void v0();
    virtual void v1(int);
};

extern "C" void* fn_27_DAF3C(void* p, int destroy) {
    if (p) {
        char* cp = (char*)p;
        *(void**)p = lbl_27_data_26050;
        if (*(short*)(cp + 4) != -1) {
            EventManager* m = (EventManager*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), *(short*)((char*)p + 4));
            m->v1(*(short*)((char*)p + 6));
        }
        if (destroy > 0)
            __dl__FPv(p);
    }
    return p;
}
