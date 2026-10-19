#pragma force_active on
extern "C" {

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_40_3DE68(void*);
void  fn_40_3E418(void*, int, int, int);

void* fn_40_3DDEC(int a, int b, int c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xc60, b);
    if (obj) {
        obj = fn_40_3DE68(obj);
    }
    fn_40_3E418(obj, a, b, c);
    return obj;
}

}
