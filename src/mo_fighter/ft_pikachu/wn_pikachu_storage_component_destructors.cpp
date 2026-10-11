#include <new>

extern "C" {
void* fn_27_93100(void*, short);
void* fn_27_19F32C(void*, short);
void* fn_27_1A54AC(void*, short);
void* fn_98_4D60(void*, short);
void* fn_98_3CF8(void*, short);
void* fn_98_175D4(void*, short);
void* fn_98_173D8(char*, short);
void* fn_98_17434(char*, short);
void* fn_98_174A4(char*, short);
void* fn_98_17568(char*, short);
}

extern "C" void* fn_98_17350(char* component, short deleting) {
    if (component) {
        short memberDeleting = -1;
        fn_27_93100(component + 0x869c, memberDeleting);
        fn_98_173D8(component + 0x68, memberDeleting);
        fn_27_19F32C(component + 0x1c, memberDeleting);
        fn_27_1A54AC(component, memberDeleting);
        if (deleting > 0) operator delete(component);
    }
    return component;
}
extern "C" void* fn_98_173D8(char* component, short deleting) {
    if (component) {
        fn_98_17434(component, short(-1));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
extern "C" void* fn_98_17434(char* component, short deleting) {
    if (component) {
        fn_98_174A4(component + 8, short(-1));
        fn_98_4D60(component, short(0));
        if (deleting > 0) operator delete(component);
    }
    return component;
}

static inline void destroyStorageBase(char* component) {
    if (component) fn_98_17568(component + 4, short(-1));
}
extern "C" void* fn_98_174A4(char* component, short deleting) {
    if (component) {
        destroyStorageBase(component);
        if (deleting > 0) operator delete(component);
    }
    return component;
}
extern "C" void* fn_98_17508(char* component, short deleting) {
    if (component) {
        fn_98_17568(component + 4, short(-1));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
extern "C" void* fn_98_17568(char* component, short deleting) {
    if (component) {
        short memberDeleting = -1;
        fn_98_3CF8(component + 0x64a0, memberDeleting);
        fn_98_175D4(component + 4, memberDeleting);
        if (deleting > 0) operator delete(component);
    }
    return component;
}
