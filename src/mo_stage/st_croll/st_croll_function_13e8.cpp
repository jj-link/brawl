#pragma force_active on
#include <ef/ef_screen.h>
#include <gr/gr_madein.h>

struct Block { int data[8]; };
struct Triple { int data[3]; };

extern "C" const float lbl_90_rodata_0;

extern "C" void fn_90_13E8(void* self) {
    int indices[10];
    int i;
    void* first;
    void* second;
    char* base;
    int* index;
    unsigned int packedColor;
    unsigned char colorBytes[4];
    
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(float*)((char*)self + 0x1c) = lbl_90_rodata_0;
    *(int*)((char*)self + 0x18) = 0;
    
    for (int j = 0; j < 10; ++j) {
        indices[j] = 11;
    }
    
    for (base = (char*)self, index = indices, i = 0; i < 10; ++i, base += 4, ++index) {
        first = *(void**)(base + 0x234);
        second = *(void**)(base + 0x25c);
        if (first && second) {
            *(Block*)((char*)first + 4) = *(Block*)((char*)self + (*index << 5) + 0x24);
            *(Triple*)((char*)second + 4) = *(Triple*)((char*)self + *index * 12 + 0x1a4);
        }
    }
    
    for (int j = 0; j < 16; ++j) {
        ((int*)((char*)self + 0x284))[j] = 0;
    }
    
    int state = *(int*)((char*)self + 4);
    *(int*)((char*)self + 0x6ac4) = 0;
    if (state & 1) {
        grMadein* entity = *(grMadein**)self;
        *(int*)((char*)self + 4) = state & ~1;
        if (entity) {
            entity->endEntity();
        }
    }
    
    state = *(int*)((char*)self + 4);
    if (!(state & 2)) {
        *(int*)((char*)self + 4) = state | 2;
        colorBytes[2] = 0;
        colorBytes[1] = 0;
        colorBytes[0] = 0;
        colorBytes[3] = 255;
        packedColor = *(unsigned int*)colorBytes;
        *(unsigned char*)((char*)self + 0x6af4) = (unsigned int)g_efScreen->requestFill(lbl_90_rodata_0, 8, 240, (GXColor*)&packedColor) >> 24;
    }
}