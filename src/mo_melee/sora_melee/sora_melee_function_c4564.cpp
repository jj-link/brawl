#pragma force_active on
extern "C" {
void fn_27_84098(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern char lbl_27_data_183B0[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct Manager {
    virtual void f0();
    virtual void f1(short v);
};

extern "C" void* fn_27_C4564(char* p, int destroy) {
    if (p) {
        if (p + 0xC) {
            if (p + 0x1C) {
                __destroy_arr(p + 0x28, fn_27_84098, 12, 1);
            }
        }
        if (p && p) {
            short id = *(short*)(p + 0x4);
            *(void**)p = lbl_27_data_183B0;
            if (id != -1) {
                Manager* manager = (Manager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), id);
                manager->f1(*(short*)(p + 0x6));
            }
        }
        if (destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
