#include <types.h>
#pragma force_active on

class ResourceInterface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void* slot10() = 0;
    virtual void slot14() = 0;
    virtual void* slot18() = 0;
    virtual void* slot1C() = 0;
    virtual void slot20() = 0;
    virtual s16 getId() = 0;
};

extern "C" {
void fn_27_1DC5E8(void*, int, void*, void*, void*, void*, unsigned char, int,
                  void*, int, int, void*, int, int, int, int);
void fn_27_D22D0(void*, int);
void fn_27_D31AC(void*, int, int);
void fn_27_D32EC(void*, int, int);
void fn_41_2608(void*, s16, void*, int, int, float, s8*);
void fn_41_2D890(void*, s16, s8);
void fn_41_2D950(void*, s16, s8);
void fn_41_2D9B4(void*);
void fn_41_2D9C0(void*);
void fn_41_2D9D8(void*, const char*, int, void*, void*);
void fn_41_30618(void*);
extern char g_soParamAccesserNull[];
extern char lbl_41_data_40CC[];
extern char lbl_41_data_40D8[];
extern char lbl_41_data_5370[];
extern char lbl_41_data_5A58[];
extern float lbl_41_rodata_E28;
extern float lbl_41_rodata_E2C;
}

extern "C" void* fn_41_30254(void* self, int arg1, void* arg5,
                              void* arg3, void* arg4) {
    char* selfPtr = (char*)self;

    *(void**)(selfPtr + 8) = lbl_41_data_5A58;

    ResourceInterface* resource =
        *(ResourceInterface**)((char*)arg3 + 4);
    void* resourceData;
    void* resourcePtr;
    resourcePtr = resource->slot1C();
    resourceData = resource->slot18();
    void* resourceAccess = resource->slot10();

    u32 buffer[0x10];
    fn_27_1DC5E8(buffer, 0x1A, (char*)arg4 + 8, resourceAccess,
                 resourceData, resourcePtr, 0xA, -1,
                 g_soParamAccesserNull, 0, 0, lbl_41_data_40CC,
                 0, 0, 0, 0);

    fn_41_2D9D8(selfPtr + 0xC, lbl_41_data_40D8, arg1, arg3, buffer);

    void* ptr = *(void**)(selfPtr + 0x6C);
    ptr = *(void**)((char*)ptr + 0xD8);
    ptr = *(void**)((char*)ptr + 0x80);
    s16 val = ((ResourceInterface*)((char*)ptr + 8))->getId();
    fn_41_2D890(selfPtr + 0x216C, val, -1);

    ptr = *(void**)(selfPtr + 0x6C);
    ptr = *(void**)((char*)ptr + 0xD8);
    ptr = *(void**)((char*)ptr + 0x80);
    val = ((ResourceInterface*)((char*)ptr + 8))->getId();
    fn_41_2D950(selfPtr + 0x2178, val, -1);

    *(void**)(selfPtr + 8) = lbl_41_data_5370;
    *(void**)(selfPtr + 0x48) = lbl_41_data_5370 + 0x10;
    *(void**)(selfPtr + 0x4C) = lbl_41_data_5370 + 0x74;
    *(void**)(selfPtr + 0x54) = lbl_41_data_5370 + 0x80;
    *(void**)(selfPtr + 0x60) = lbl_41_data_5370 + 0x94;
    *(void**)(selfPtr + 0x70) = lbl_41_data_5370 + 0xEC;
    *(void**)(selfPtr + 0x7C) = lbl_41_data_5370 + 0xFC;
    *(void**)(selfPtr + 0x88) = lbl_41_data_5370 + 0x110;
    *(void**)(selfPtr + 0x94) = lbl_41_data_5370 + 0x128;
    *(void**)(selfPtr + 0x9C) = lbl_41_data_5370 + 0x134;
    *(void**)(selfPtr + 0x216C) = lbl_41_data_5370 + 0x27C;
    *(void**)(selfPtr + 0x2178) = lbl_41_data_5370 + 0x290;

    fn_41_2D9B4(selfPtr + 0x2184);

    *(u8*)(selfPtr + 0x21B4) = 0;
    *(u8*)(selfPtr + 0x21B5) = 1;
    *(u8*)(selfPtr + 0x21B6) = 0;
    *(u8*)(selfPtr + 0x21B7) = 0;
    *(u8*)(selfPtr + 0x21B8) = 0;
    *(u8*)(selfPtr + 0x21B9) = 0;
    *(u8*)(selfPtr + 0x21BA) = 0;
    *(u8*)(selfPtr + 0x21BB) = 0;
    *(u32*)(selfPtr + 0x21BC) = 0;
    *(u32*)(selfPtr + 0x21C0) = 0;
    *(u32*)(selfPtr + 0x21C4) = 0;
    *(u32*)(selfPtr + 0x21C8) = 0;
    *(u32*)(selfPtr + 0x21CC) = 0;
    *(u32*)(selfPtr + 0x21D0) = 0;

    float fval = lbl_41_rodata_E28;
    *(float*)(selfPtr + 0x21D4) = fval;
    *(float*)(selfPtr + 0x21D8) = fval;
    *(u32*)(selfPtr + 0x21DC) = 0;
    *(float*)(selfPtr + 0x21E0) = fval;
    *(float*)(selfPtr + 0x21E4) = fval;
    *(u32*)(selfPtr + 0x21E8) = 0xFFFFFFFF;
    *(u32*)(selfPtr + 0x21EC) = 0;
    *(float*)(selfPtr + 0x21F0) = fval;
    *(float*)(selfPtr + 0x21F4) = fval;
    *(float*)(selfPtr + 0x21F8) = fval;
    *(float*)(selfPtr + 0x21FC) = fval;
    *(float*)(selfPtr + 0x2200) = fval;
    *(float*)(selfPtr + 0x2204) = fval;
    *(u32*)(selfPtr + 0x2208) = 0;
    *(u32*)(selfPtr + 0x220C) = 0;
    *(u32*)(selfPtr + 0x2210) = 0xFFFFFFFF;
    *(u8*)(selfPtr + 0x2214) = 0;
    *(u8*)(selfPtr + 0x2215) = 0;
    *(u8*)(selfPtr + 0x2216) = 0;
    *(u8*)(selfPtr + 0x2217) = 0;
    *(u8*)(selfPtr + 0x2218) = 0;
    *(u8*)(selfPtr + 0x2219) = 0;
    *(u8*)(selfPtr + 0x221A) = 0;
    *(u8*)(selfPtr + 0x221B) = 0;

    char* loopPtr = selfPtr + 0x221C;
    do {
        fn_41_2D9C0(loopPtr);
        loopPtr += 0xC;
    } while (loopPtr < selfPtr + 0x2234);

    fn_27_D32EC(selfPtr + 0x2238, 2, 0);
    fn_27_D31AC(selfPtr + 0x224C, 5, 0);

    s8 localByte = 0;
    ptr = *(void**)(selfPtr + 0x6C);
    ptr = *(void**)((char*)ptr + 0xD8);
    ptr = *(void**)((char*)ptr + 0x80);
    val = ((ResourceInterface*)((char*)ptr + 8))->getId();
    fn_41_2608(selfPtr + 0x226C, val, selfPtr + 0x22BC,
               6, 1, lbl_41_rodata_E2C, &localByte);

    fn_27_D22D0(selfPtr + 0x22BC, 0);
    fn_41_30618(self);
    return self;
}
