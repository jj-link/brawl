#include <mu/mu_object.h>
#pragma force_active on

extern "C" void fn_6_6E80(void* self, int value) {
    float frame = (float)value;
    (*(MuObject**)((char*)*(void**)((char*)self + 0x1AC) + 0x110))->setFrameNode(frame);
    (*(MuObject**)((char*)*(void**)((char*)self + 0x1AC) + 0x114))->setFrameNode(frame);
}
