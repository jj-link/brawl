#pragma force_active on
extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

extern "C" void* lbl_27_data_25F88[];

struct Manager {
    virtual void unused0();
    virtual void remove(short);
};

extern "C" void* fn_27_DAC6C(char* p, int destroy) {
    if (p) {
        *(void**)p = lbl_27_data_25F88;
        if (*(short*)(p + 4) != -1) {
            void* result = getInstance__13soEventSystemFv();
            Manager* mgr = (Manager*)getManager__13soEventSystemFl(result, *(short*)(p + 4));
            mgr->remove(*(short*)(p + 6));
        }
        if (destroy > 0)
            __dl__FPv(p);
    }
    return p;
}