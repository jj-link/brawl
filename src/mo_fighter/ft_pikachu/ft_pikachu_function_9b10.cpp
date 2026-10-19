#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);

extern "C" void* fn_98_9B10(void* accesser, short deleting) {
    if (accesser) {
        __dt__21ftExtendParamAccesserFv(accesser, short(0));
        if (deleting > 0) operator delete(accesser);
    }
    return accesser;
}
