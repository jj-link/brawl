#pragma force_active on

typedef unsigned char u8;

extern "C" {
extern char lbl_80423928[];
void OSResumeThread(void*);
void free__13gfHeapManagerFPv(void*);
void __dt__8gfThreadFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_8003D054(void* self, int flag) {
    u8* p = (u8*)self;
    if (self) {
        *(char**)(p + 0x0) = lbl_80423928;
        if (p[0x360] == 0) {
            OSResumeThread((u8*)self + 8);
        }
        if (p[0x370]) {
            void* h = *(void**)(p + 0x368);
            if (h) {
                free__13gfHeapManagerFPv(h);
                *(void**)(p + 0x368) = 0;
            }
        }
        __dt__8gfThreadFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
