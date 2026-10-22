#pragma force_active on

extern "C" {
void fn_800307B4(void);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_80460D64[];
}

extern "C" void* fn_8014C1EC(void* self, int flag) {
    if (self != 0) {
        *(void**)((char*)self + 0x3C) = lbl_80460D64;
        void* h = *(void**)((char*)self + 0x40);
        if (h != 0) {
            fn_800307B4();
            *(void**)((char*)self + 0x40) = 0;
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
