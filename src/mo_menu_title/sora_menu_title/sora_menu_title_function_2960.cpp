#pragma force_active on
extern "C" {

void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern char lbl_24_data_7A8[];
extern char lbl_24_data_834[];

struct S {
    char padding[0x3c];
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    char padding2[8];
    int f60;
    int f64;
};

void* fn_24_2960() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x68, 0x2a);
    if (p != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_24_data_7A8, 8, 0xf, 8, true);
        S* obj = (S*)p;
        obj->f3c = (int)lbl_24_data_834;
        obj->f40 = 0;
        obj->f44 = 0;
        obj->f48 = 0;
        obj->f4c = 0;
        obj->f50 = 0;
        obj->f54 = 0;
        obj->f60 = 0;
        obj->f64 = 0;
    }
    return p;
}

}
