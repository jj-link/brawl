#pragma force_active on
void* fn_80261178(void* p);
void* fn_80261264(void* p)
{
    ((int*)p)[0] = 0;
    ((int*)p)[1] = 0;
    return fn_80261178(p);
}