#pragma force_active on

extern "C" {
extern void free__13gfHeapManagerFPv(void*);
extern void fn_27_247E58(void*, int);
extern void __dl__FPv(void*);
extern char lbl_27_data_4F7D0[];
}

extern "C" void* fn_27_24FD6C(void* self, int flag) {
    if (self != 0) {
        void* p0xF8 = *(void**)((char*)self + 0xF8);
        *(char**)((char*)self + 0x3C) = lbl_27_data_4F7D0;
        if (p0xF8 != 0) {
            free__13gfHeapManagerFPv(p0xF8);
            *(void**)((char*)self + 0xF8) = 0;
        }
        void* p0xFC = *(void**)((char*)self + 0xFC);
        if (p0xFC != 0) {
            free__13gfHeapManagerFPv(p0xFC);
            *(void**)((char*)self + 0xFC) = 0;
        }
        void* p0x100 = *(void**)((char*)self + 0x100);
        if (p0x100 != 0) {
            free__13gfHeapManagerFPv(p0x100);
            *(void**)((char*)self + 0x100) = 0;
        }
        void* p0x104 = *(void**)((char*)self + 0x104);
        if (p0x104 != 0) {
            free__13gfHeapManagerFPv(p0x104);
            *(void**)((char*)self + 0x104) = 0;
        }
        fn_27_247E58(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
