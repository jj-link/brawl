#pragma force_active on

extern "C" {
void fn_8014E520(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_80462130[];
}

extern "C" void* fn_801582A4(void* self, int flag) {
    if (self) {
        *(void**)((char*)self + 0x3C) = lbl_80462130;
        *(void**)((char*)self + 0x40) = lbl_80462130 + 0x64;
        void* h = *(void**)((char*)self + 0x48);
        if (h) {
            fn_8014E520(h, 1);
            *(void**)((char*)self + 0x48) = 0;
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
