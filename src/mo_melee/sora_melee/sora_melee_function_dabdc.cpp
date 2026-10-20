#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_25F60[];
}

struct Base {
    virtual void f0();
};
struct Manager : Base {
    virtual void f1(short arg);
};

extern "C" void* fn_27_DABDC(void* p, int destroy) {
    if (p) {
        short id = *(short*)((char*)p + 4);
        *(void**)p = lbl_27_data_25F60;
        if (id != -1)
            ((Manager*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(short*)((char*)p + 4)))->f1(*(short*)((char*)p + 6));
        if (destroy > 0)
            __dl__FPv(p);
    }
    return p;
}
