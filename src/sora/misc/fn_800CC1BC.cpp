#pragma force_active on

typedef unsigned char u8;

extern "C" int fn_800CC2C0(void*);
extern "C" void flushLogToSDCard__Fv();
extern "C" void netReport__FPCce(const char*, ...);
extern "C" int fn_800C84FC();
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8014C180(void*);
extern "C" void fn_8014C26C(void*, int, int);

extern char lbl_80457C84[];
extern char lbl_80457CA0[];
extern int lbl_805A0448;

struct State {
    u8 padding[0xFCB];
    u8 initialized : 1;
    u8 otherFlags : 7;
};

extern "C" int fn_800CC1BC(void* self) {
    int result = fn_800CC2C0(self);
    if (result == 0)
        return result;

    u8* p = (u8*)self;
    if (!((State*)self)->initialized) {
        flushLogToSDCard__Fv();

        if (result != 1) {
            netReport__FPCce(lbl_80457C84, result);
            return result;
        }

        p[0xFCB] |= 0x80;

        if (fn_800C84FC() && lbl_805A0448 == 0) {
            void* obj = __nw__FUlQ25Heaps8HeapType(0x48, 6);
            if (obj)
                obj = fn_8014C180(obj);
            if (obj)
                fn_8014C26C(obj, 6, 1);
        }
    }

    if (lbl_805A0448 != 0) {
        netReport__FPCce(lbl_80457CA0);
        return 0;
    }

    netReport__FPCce(lbl_80457C84, result);
    return result;
}
