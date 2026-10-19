#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_35F0(void*, short);
void* fn_98_4EA4(void*, short);

void* fn_98_3580(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        char* bytes = static_cast<char*>(object);
        fn_98_35F0(bytes + 0xA60C, memberDeleting);
        fn_98_4EA4(bytes + 4, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
