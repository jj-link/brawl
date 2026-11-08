#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
int exchangeGmCharacterKind2MuStockchkind__6muMenuFi(int);
int exchangeGmCharacterKind2Something__6muMenuFi(int);
int fn_800AF6F0(int);
int readRequestNoSync__14gfFileIOHandleFPCcPvii(void*, const char*, void*, int, int);
void setFrameTex__8MuObjectFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
int sprintf(char*, const char*, ...);
extern const char lbl_8045A35C[];
extern const double lbl_805A23B8;
extern const float lbl_805A23B0;
extern const float lbl_805A23C0;
}
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(float, float);
};
struct Inner { char pad[0x10]; Object_vptr_0* object; };
struct MuObjectHolder { char pad[0x14]; Inner* inner; };
extern "C" void fn_800E1ED8(char* self, int mode, int kind) {
    MuObjectHolder* holder;
    int frame;
    int request;
    int result;
    int offset;
    char path[64];
    request = 0;
    if (mode == 1) {
        frame = 0x259;
        result = 0x13;
    } else {
        int stockKind = exchangeGmCharacterKind2MuStockchkind__6muMenuFi(kind);
        result = exchangeGmCharacterKind2Something__6muMenuFi(stockKind);
        frame = (int)(float)(result * 10 + 1);
        if (mode == 2) {
            result = 0x13;
        } else {
            result = exchangeGmCharacterKind2MuStockchkind__6muMenuFi(kind);
            result = fn_800AF6F0(result);
        }
    }
    if (mode == 1)
        offset = 0;
    else
        offset = *(int*)(self + 0x2a8);
    holder = *(MuObjectHolder**)(self + 0xb4);
    frame += offset;
    Object_vptr_0* object = holder->inner->object;
    float converted = (float)result;
    float animationFrame = lbl_805A23C0 + converted;
    object->slot8(lbl_805A23B0, converted);
    setFrameTex__8MuObjectFf((void*)holder, animationFrame);
    setFrameTex__8MuObjectFf(*(void**)(self + 0xb8), (float)frame);
    int state = *(int*)(self + 0x2a0);
    switch (state) {
    case 0: request = 1; break;
    case 1:
        if (*(int*)(self + 0x298) != frame) {
            setFrameVisible__8MuObjectFf(*(void**)(self + 0xb8), lbl_805A23C0);
            request = 1;
        }
        break;
    case 2:
        *(int*)(self + 0x29c) = frame;
        *(int*)(self + 0x2a0) = 3;
        break;
    case 3:
        *(int*)(self + 0x29c) = frame;
        break;
    }
    if (request) {
        sprintf(path, lbl_8045A35C, frame);
        readRequestNoSync__14gfFileIOHandleFPCcPvii(
            self + 0x290, path, *(void**)(self + 0x2a4), 0, 0);
        *(int*)(self + 0x298) = frame;
        *(int*)(self + 0x2a0) = 2;
    }
    *(int*)(self + 0x568) = mode;
    *(int*)(self + 0x56c) = kind;
}