#pragma force_active on
typedef int s32;
typedef short s16;
typedef unsigned char u8;
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_84458(void*, int);
extern "C" char lbl_27_data_26028[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EvMgr {
public:
    virtual void f0();
    virtual void f1(short);
};

extern "C" void* fn_27_290CA0(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84458, 0xc, 0x1e);
        }
        if (self != 0 && self != 0) {
            *(void**)self = (void*)lbl_27_data_26028;
            if (*(s16*)((u8*)self + 0x4) != -1) {
                void* inst = getInstance__13soEventSystemFv();
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(inst, *(s16*)((u8*)self + 0x4));
                mgr->f1(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
