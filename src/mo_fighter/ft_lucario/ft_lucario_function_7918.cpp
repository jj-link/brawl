#pragma force_active on
extern "C" void fn_27_199DDC(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_118_7918(void* link, void* accesser) {
    fn_27_199DDC(link, 6, 0);
    fn_27_6A244(static_cast<unsigned char*>(link) + 0x144, accesser, link);
    return link;
}
