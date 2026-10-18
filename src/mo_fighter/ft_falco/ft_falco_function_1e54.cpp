#pragma force_active on
extern "C" {

extern void __dl__FPv(void*);

void* fn_108_1E54(void* ptr, short flag)
{
    if (ptr != 0)
    {
        if (flag > 0)
        {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

}
