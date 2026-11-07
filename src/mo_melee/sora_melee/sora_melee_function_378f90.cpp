#include <stddef.h>
#pragma force_active on
extern "C" {
void __dt__16acCmdInterpreterFv(void* p, short flag);
void __dl__FPv(void* p);

void* fn_27_378F90(void* p, int flag) {
    if (p != NULL) {
        if ((char*)p + 0x1510) {
            void* o1 = (void*)((char*)p + 0x15EC);
            if (o1 != NULL) {
                __dt__16acCmdInterpreterFv(o1, 0);
            }
        }
        {
            void* o2 = (void*)((char*)p + 0x13EC);
            if (o2 != NULL && o2 != NULL) {
                __dt__16acCmdInterpreterFv(o2, 0);
            }
        }
        if ((char*)p + 0x12C0) {
            void* o3 = (void*)((char*)p + 0x139C);
            if (o3 != NULL) {
                __dt__16acCmdInterpreterFv(o3, 0);
            }
        }
        if ((char*)p + 0x1194) {
            void* o4 = (void*)((char*)p + 0x1270);
            if (o4 != NULL) {
                __dt__16acCmdInterpreterFv(o4, 0);
            }
        }
        if ((char*)p + 0x1068) {
            void* o5 = (void*)((char*)p + 0x1144);
            if (o5 != NULL) {
                __dt__16acCmdInterpreterFv(o5, 0);
            }
        }
        if ((char*)p + 0xF3C) {
            void* o6 = (void*)((char*)p + 0x1018);
            if (o6 != NULL) {
                __dt__16acCmdInterpreterFv(o6, 0);
            }
        }
        if ((char*)p + 0xE10) {
            void* o7 = (void*)((char*)p + 0xEEC);
            if (o7 != NULL) {
                __dt__16acCmdInterpreterFv(o7, 0);
            }
        }
        if ((char*)p + 0xCE4) {
            void* o8 = (void*)((char*)p + 0xDC0);
            if (o8 != NULL) {
                __dt__16acCmdInterpreterFv(o8, 0);
            }
        }
        if ((char*)p + 0xBB8) {
            void* o9 = (void*)((char*)p + 0xC94);
            if (o9 != NULL) {
                __dt__16acCmdInterpreterFv(o9, 0);
            }
        }
        if ((char*)p + 0xA8C) {
            void* o10 = (void*)((char*)p + 0xB68);
            if (o10 != NULL) {
                __dt__16acCmdInterpreterFv(o10, 0);
            }
        }
        if (p != NULL) {
            void* o11 = (void*)((char*)p + 0xA3C);
            if (o11 != NULL) {
                __dt__16acCmdInterpreterFv(o11, 0);
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
