#include <new>

extern "C" {
void* fn_98_3CF8(void*, short);
void* fn_98_3F10(void*, short);
void* fn_98_17640(char*, short);
void* fn_98_176AC(char*, short);

void* fn_98_175D4(char* element, short deleting) {
    if (element) {
        short memberDeleting = -1;
        fn_98_3CF8(element + 0x4318, memberDeleting);
        fn_98_17640(element + 4, memberDeleting);
        if (deleting > 0) operator delete(element);
    }
    return element;
}
void* fn_98_17640(char* element, short deleting) {
    if (element) {
        short memberDeleting = -1;
        fn_98_3CF8(element + 0x2190, memberDeleting);
        fn_98_176AC(element + 4, memberDeleting);
        if (deleting > 0) operator delete(element);
    }
    return element;
}
void* fn_98_176AC(char* element, short deleting) {
    if (element) {
        fn_98_3CF8(element + 8, short(-1));
        if (deleting > 0) operator delete(element);
    }
    return element;
}
void* fn_98_1770C(char* element, short deleting) {
    if (element) {
        fn_98_3F10(element + 0x50, short(-1));
        if (deleting > 0) operator delete(element);
    }
    return element;
}
}
