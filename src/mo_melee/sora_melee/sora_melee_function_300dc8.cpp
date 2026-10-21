#include <stddef.h>
#pragma force_active on
extern "C" {
void __dt__16acCmdInterpreterFv(void*, short);
void __dl__FPv(void*);

void* fn_27_300DC8(void* arg0, int arg1) {
    if (arg0 != NULL) {
        void* p = (void*)((char*)arg0 + 0x2D0);
        if (p != NULL) {
            if (p != NULL) {
                __dt__16acCmdInterpreterFv(p, 0);
            }
        }
        if ((char*)arg0 + 0x21C) {
            void* p2 = (void*)((char*)arg0 + 0x280);
            if (p2 != NULL) {
                __dt__16acCmdInterpreterFv(p2, 0);
            }
        }
        if ((char*)arg0 + 0x168) {
            void* p3 = (void*)((char*)arg0 + 0x1CC);
            if (p3 != NULL) {
                __dt__16acCmdInterpreterFv(p3, 0);
            }
        }
        if ((char*)arg0 + 0xB4) {
            void* p4 = (void*)((char*)arg0 + 0x118);
            if (p4 != NULL) {
                __dt__16acCmdInterpreterFv(p4, 0);
            }
        }
        if (arg0 != NULL) {
            void* p5 = (void*)((char*)arg0 + 0x64);
            if (p5 != NULL) {
                __dt__16acCmdInterpreterFv(p5, 0);
            }
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
