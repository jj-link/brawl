#pragma force_active on
extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_260C8[];
}

struct Manager {
    virtual void unused();
    virtual void remove(int);
};

extern "C" void* fn_27_DB0EC(char* p, int destroy) {
    if (p) {
        *(void**)p = lbl_27_data_260C8;
        if (*(short*)(p + 0x4) != -1) {
            void* inst = getInstance__13soEventSystemFv();
            Manager* manager = (Manager*)getManager__13soEventSystemFl(inst, *(short*)(p + 0x4));
            manager->remove(*(short*)(p + 0x6));
        }
        if (destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
