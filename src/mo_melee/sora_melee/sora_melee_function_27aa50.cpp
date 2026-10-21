#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

extern "C" void fn_27_27AA50(u8* self) {
    u8* p = self + 0xd0;
    if (p) {
        u8* model = *(u8**)(*(u8**)(self + 0x44));
        if (model) {
            if (*(u32*)(model + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                *(u8**)(model + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(u16*)(model + 0x122) = (u16)*(u32*)(self + 0xc4);
            }
            u8* q = *(u8**)(p + 4);
            *(float*)(q + 0x20) = *(float*)(self + 0x150);
            *(float*)(q + 0x24) = *(float*)(self + 0x154);
            *(float*)(q + 0x28) = *(float*)(self + 0x158);
        }
    }
}
