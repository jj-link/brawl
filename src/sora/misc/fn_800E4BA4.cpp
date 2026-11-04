#include <mu/mu_object.h>

#pragma force_active on

extern "C" int fn_800B5854(void*, int, int, int, int);
extern "C" int fn_800B5328(MuObject*);
extern const double lbl_805A23B8;

extern "C" void fn_800E4BA4(char* self, int flag) {
    char* entry;
    int i;
    int a;
    int b;

    if (flag) {
        a = 1;
        b = 1;
    } else {
        a = 0;
        b = 0;
    }

    entry = self;
    for (i = 0; i < 3; ++i, entry += 0xC) {
        int type = *(int*)(entry + 0x26C);
        if (type == 0)
            break;

        if (type == 1) {
            MuObject* object = *(MuObject**)(entry + 0x270);
            fn_800B5854(object, a, 0x11, b, 0);

            if (!flag) {
                int frame = fn_800B5328(object);
                object->setFrameNode((float)frame);
                object->setFrameMatCol((float)frame);
            }
        }
    }

    *(char*)(self + 0x28C) = (char)flag;
}
