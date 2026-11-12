#pragma force_active on
struct S;

extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_2AA4(S*);
extern "C" void fn_27_2AE0(void*, int);
extern "C" void* __construct_new_array(void*, void*, void*, int, int);
extern "C" void fn_8015BFB4(S*, void*);

extern "C" S* fn_27_37D0(S* self, short count)
{
    int n = count;
    S* result;
    result = (S*)__construct_new_array(
        __nwa__FUlQ25Heaps8HeapType((n << 6) + 0x10, 2),
        fn_27_2AA4, fn_27_2AE0, 0x40, n);

    char* node = (char*)result;
    int i = 0;
    while (i < n) {
        fn_8015BFB4(self, node);
        node += 0x40;
        i++;
    }
    return result;
}