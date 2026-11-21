#pragma force_active on
#include <types.h>
#include <revolution/OS/OSMessage.h>
#include <revolution/OS/OSMutex.h>

struct Obj {
    u8 pad[0x318];
    u8 field318[8];
    u8 queue[0x20];
    u8 messages[0x10];
    int field350;
    u8 mutex[0x18];
    int field36C;
    int field370;
    int field374;
    int field378;
    void* field37C;
    void* field380;
    int field384;
    void* field388;
    void* field38C;
    int field390;
    u8 field394;
};

extern "C" {
extern Obj lbl_804D8CC0;
extern signed char lbl_805A0600;
extern u8 lbl_804D8CB0[0x10];
void fn_801E0704(void*);
void fn_801CC3A8(void*);
void __register_global_object(void*, void (*)(void*), void*);
}

extern "C" void* fn_801CC2E4(void) {
    if (lbl_805A0600 == 0) {
        Obj* obj = &lbl_804D8CC0;
        void* p388 = &obj->field388;
        void* p37C = &obj->field37C;
        for (int i = 0; i < 2; ++i) {
            ((void**)&obj->field37C)[i] = 0;
        }
        for (int i = 0; i < 2; ++i) {
            ((void**)&obj->field388)[i] = 0;
        }
        obj->field350 = 0;
        obj->field36C = 0;
        obj->field370 = 0;
        obj->field378 = 0;
        obj->field37C = p37C;
        obj->field380 = p37C;
        obj->field384 = 0;
        obj->field388 = p388;
        obj->field38C = p388;
        obj->field394 = 0;

        OSInitMessageQueue((OSMessageQueue*)obj->queue, (OSMessage*)obj->messages, 4);
        fn_801E0704(obj->field318);
        OSInitMutex((OSMutex*)obj->mutex);
        __register_global_object(obj, fn_801CC3A8, lbl_804D8CB0);
        lbl_805A0600 = 1;
    }
    return &lbl_804D8CC0;
}
