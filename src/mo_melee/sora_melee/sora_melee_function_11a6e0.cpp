#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_11AD84(void* p, int flags);
extern "C" char lbl_27_data_280F8[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EvMgr {
public:
    virtual void v0();
    virtual void v1(int);
};

extern "C" void* fn_27_11A6E0(void* self, int del) {
    if (self != 0) {
        if ((unsigned char*)self + 0xc != 0 && (unsigned char*)self + 0x1c != 0) {
            __destroy_arr((unsigned char*)self + 0x28, (void (*)(void*, int))fn_27_11AD84, 0xc, 4);
        }
        if (self != 0 && self != 0) {
            short id = ((short*)self)[2];
            *(void**)self = (void*)lbl_27_data_280F8;
            if (id != -1) {
                void* inst = getInstance__13soEventSystemFv();
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(inst, ((short*)self)[2]);
                mgr->v1(((short*)self)[3]);
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
