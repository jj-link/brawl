#pragma force_active on
extern "C" {
void fn_27_84098(void*, int);
void fn_27_50588(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern char lbl_27_data_183B0[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void* __dt__23soEventManageModuleImplFv(void*, short);
void __dl__FPv(void*);
}

struct Manager {
    virtual void unused();
    virtual void remove(int);
};

extern "C" void* fn_27_C5D40(char* p, int destroy) {
    if (p) {
        if (p + 0x3C) {
            if (p + 0x48) {
                if (p + 0x58) {
                    __destroy_arr(p + 0x64, fn_27_84098, 12, 1);
                }
            }
            if (p + 0x3C) {
                if (p + 0x3C) {
                    short id = *(short*)(p + 0x40);
                    *(void**)(p + 0x3C) = lbl_27_data_183B0;
                    if (id != -1) {
                        Manager* manager = (Manager*)getManager__13soEventSystemFl(
                            getInstance__13soEventSystemFv(), id);
                        manager->remove(*(short*)(p + 0x42));
                    }
                }
            }
        }
        __dt__23soEventManageModuleImplFv(p + 0x28, -1);
        if (p) {
            if (p + 0x14) {
                __destroy_arr(p + 0x20, fn_27_50588, 8, 1);
            }
        }
        if (destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
