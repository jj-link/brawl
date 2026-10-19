#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Block {
    u32 values[12];
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);

extern "C" void fn_61_8AF8(void* arg) {
    char* self = (char*)arg;
    char* callback = self + 0xD0;
    if (callback) {
        char* model = *(char**)*(char**)(self + 0x44);
        if (model) {
            if (!*(u32**)(model + 0x11C)) {
                *(u32*)(callback + 0x0C) = 0;
                *(u32*)*(char**)(callback + 4) = *(u32*)(self + 0xC4);
                *(char**)(model + 0x11C) = callback;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(u16*)(model + 0x122) = (u16)**(u32**)(callback + 4);
            }
            if (*(u32*)(self + 0x170)) {
                Block* dest = (Block*)((char*)*(char**)(callback + 4) + 0x50);
                Block* source = (Block*)*(char**)(self + 0x170);
                *dest = *source;
            }
        }
    }
}
