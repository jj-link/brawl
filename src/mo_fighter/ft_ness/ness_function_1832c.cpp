#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_101_3B4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_101_183BC(void*, short);
void* fn_27_1D81C8(void*, short);
}

struct ArticleAggregate {
    void fn_101_1832C(void* object, short deleting);
};

extern "C" void* fn_101_1832C(void* object, short deleting) {
    if (object != 0) {
        char* base = static_cast<char*>(object);
        char* members = base + 0xDD8C;
        short memberDeleting = -1;
        fn_101_3B4C(members, memberDeleting);
        fn_27_1DBB60(base + 0xDD54, memberDeleting);
        fn_101_183BC(base + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
