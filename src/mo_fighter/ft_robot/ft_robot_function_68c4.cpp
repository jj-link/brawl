#pragma force_active on
extern "C" void fn_27_199DDC(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_120_68C4(void* link, void* arg)
{
    fn_27_199DDC(link, 6, 0);
    fn_27_6A244((char*)link + 0x144, arg, link);
    return link;
}
