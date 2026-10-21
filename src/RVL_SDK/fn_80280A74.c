#pragma force_active on
void fn_80280840(void *p);

void *fn_80280A74(void *arg0)
{
    fn_80280840(*(void **)((char *)arg0 + 0x8));
    return arg0;
}
