#pragma force_active on
extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_25F10[];
}

struct Manager {
    virtual void unused0();
    virtual void method3(short);
};

extern "C" void* fn_27_DAABC(void* p, int destroy) {
    if (p) {
        short id = *(short*)((char*)p + 4);
        *(void**)p = (void*)lbl_27_data_25F10;
        if (id != -1) {
            Manager* manager = (Manager*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), *(short*)((char*)p + 4));
            manager->method3(*(short*)((char*)p + 6));
        }
        if (destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
