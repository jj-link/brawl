#include <types.h>
#pragma force_active on

extern "C" void fn_80116F98(void*, void*);
extern "C" char g_grCollisionList[];

extern "C" bool fn_8011728C(void* self, u16 id, void* param2) {
    *(u16*)((char*)self + 0x10) = id;
    if (param2) {
        if ((*(const u8*)((char*)param2 + 0x2C) >> 7) & 1) {
            if (*(const u8*)((char*)param2 + 0x2C) & 1) {
                fn_80116F98(self, param2);
            }
        }
    } else {
        if ((*(const u8*)((char*)self + 0x13) >> 7) & 1) {
            void* it = *(void**)(g_grCollisionList + 4);
            void* end = g_grCollisionList + 4;
            while (it != end) {
                void* c = (char*)it - 0x30;
                if (c != *(void**)((char*)self + 0x14)) {
                    u8 f = *(const u8*)((char*)c + 0x2C);
                    if ((f >> 2 & 1) && (f >> 7 & 1) && (f & 1)) {
                        fn_80116F98(self, c);
                    }
                }
                it = *(void**)it;
            }
        } else {
            void* it = *(void**)(g_grCollisionList + 4);
            void* end = g_grCollisionList + 4;
            while (it != end) {
                void* c = (char*)it - 0x30;
                if (c != *(void**)((char*)self + 0x14)) {
                    u8 f = *(const u8*)((char*)c + 0x2C);
                    if ((f >> 2 & 1) && !(f >> 1 & 1) && (f >> 7 & 1) && (f & 1)) {
                        fn_80116F98(self, c);
                    }
                }
                it = *(void**)it;
            }
        }
    }
    return *(u16*)((char*)self + 0x1A) != 0;
}
