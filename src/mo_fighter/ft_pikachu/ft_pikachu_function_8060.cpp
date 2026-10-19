#pragma force_active on
extern "C" void fn_27_199DDC(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_98_8060(void* link, void* modules) {
    fn_27_199DDC(link, 6, 0);
    fn_27_6A244(static_cast<char*>(link) + 0x144, modules, link);
    return link;
}
