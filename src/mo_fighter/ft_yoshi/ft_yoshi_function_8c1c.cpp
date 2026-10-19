#pragma force_active on
extern "C" void fn_27_199DDC(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_95_8C1C(void* link, void* articleAccesser)
{
    fn_27_199DDC(link, 6, 0);
    fn_27_6A244(static_cast<char*>(link) + 0x144, articleAccesser, link);
    return link;
}
