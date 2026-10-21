#pragma force_active on

extern "C" {
void fn_27_11AD84(void*, int);
void fn_27_50588(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_13F45C(void*, int);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_280F8[];
}

struct Object {
    char pad[0x1e8];
    void* vtable;
    short id;
    short index;
};

struct EventManager {
    virtual void fn0();
    virtual void fn1(short);
};

extern "C" void* fn_27_118F50(void* obj, int flag) {
    if (obj) {
        if ((unsigned long)obj + 0x1e8) {
            if ((char*)obj + 0x1f4) {
                if ((char*)obj + 0x204) {
                    __destroy_arr((char*)obj + 0x210, fn_27_11AD84, 0xc, 4);
                }
            }
            if ((char*)obj + 0x1e8) {
                if ((char*)obj + 0x1e8) {
                    short id = ((Object*)obj)->id;
                    ((Object*)obj)->vtable = lbl_27_data_280F8;
                    if (id != -1) {
                        ((EventManager*)getManager__13soEventSystemFl(
                            getInstance__13soEventSystemFv(),
                            ((Object*)obj)->id))->fn1(((Object*)obj)->index);
                    }
                }
            }
        }
        __dt__23soEventManageModuleImplFv((char*)obj + 0x1d4, -1);
        if ((char*)obj + 0x1ac) {
            if ((char*)obj + 0x1c0) {
                __destroy_arr((char*)obj + 0x1cc, fn_27_50588, 8, 1);
            }
        }
        fn_27_13F45C((char*)obj + 0x78, -1);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
