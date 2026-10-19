#pragma force_active on
typedef void (*DtorFunc)(void*, int);
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_55_238(void* object, int shouldDelete)
{
    if (object != 0) {
        __dt__Q28StSeUtil5SeSeqFv(object, 0);
        if (shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}
