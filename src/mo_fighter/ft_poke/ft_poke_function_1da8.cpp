#pragma force_active on

extern "C" {

void* fn_116_1E04(void* ptr, short size);
void __dl__FPv(void*);

void* fn_116_1DA8(void* ptr, short flag)
{
    if (ptr != 0) {
        fn_116_1E04(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

}
