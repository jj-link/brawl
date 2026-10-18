#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_D360(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_D3BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_95_D360(members + 4, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
