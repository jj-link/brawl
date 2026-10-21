#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16muMenuControllerFv(void*);
void __dt__16muMenuControllerFv(void*);
void* memset(void*, int, unsigned long);
extern char lbl_1_data_1448[];
extern char lbl_1_data_1498[];
extern void* __vt__6muMenu[];
}

struct Param {
    int a, b, c, d;
    unsigned char e;
    int f;

    Param() : a(0), b(0), c(0), d(0), e(0), f(-1) {}
};

extern "C" void* fn_1_624C() {
    void* mem = __nw__FUlQ25Heaps8HeapType(0x384, 0x2e);
    if (mem) {
        char* p = (char*)mem;
        *(void**)p = (void*)&lbl_1_data_1448;
        *(void**)(p + 4) = (void*)&__vt__6muMenu;
        __construct_array(p + 8, &__ct__16muMenuControllerFv,
                          &__dt__16muMenuControllerFv, 0xa8, 5);
        *(void**)(p + 4) = (void*)&lbl_1_data_1498;
        *(int*)(p + 0x35c) = 0;
        *(int*)(p + 0x360) = 0;
        *(int*)(p + 0x364) = 0;
        *(int*)(p + 0x368) = 0;
        *(int*)(p + 0x36c) = 0;
        *(unsigned char*)(p + 0x370) = 0;
        *(int*)(p + 0x374) = -1;
        *(unsigned char*)(p + 0x378) = 0;
        *(int*)(p + 0x37c) = 0;
        *(int*)(p + 0x380) = 0;

        Param temp;
        memset(&temp, 0, 0x18);
        *(int*)(p + 0x360) = temp.a;
        *(int*)(p + 0x364) = temp.b;
        *(int*)(p + 0x368) = temp.c;
        *(int*)(p + 0x36c) = temp.d;
        *(unsigned char*)(p + 0x370) = temp.e;
        *(int*)(p + 0x374) = temp.f;
    }
    return mem;
}
