#pragma force_active on

extern "C" void* fn_123_1E0C(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" {

void* fn_123_1DB0(char* ptr, short deleting)
{
    if (ptr != 0)
    {
        fn_123_1E0C(ptr, 0);
        if (deleting > 0)
        {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

}
