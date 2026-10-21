#pragma force_active on

typedef unsigned char u8;

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

void OSInitMessageQueue(void*, void*, int);
void fn_801E0704(void*);
void OSInitMutex(void*);
void fn_801CC3A8(void*);
void __register_global_object(void*, void (*)(void*), void*);
void fn_801DE298(void*, int, int);
void OSJoinThread(void*, void*);
}

extern "C" void fn_801CC550(Obj* self) {
    if (self->field394 != 0) {
        if (lbl_805A0600 == 0) {
            Obj* obj = &lbl_804D8CC0;

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
            obj->field37C = &obj->field37C;
            obj->field380 = &obj->field37C;
            obj->field384 = 0;
            obj->field388 = &obj->field388;
            obj->field38C = &obj->field388;
            obj->field394 = 0;

            OSInitMessageQueue(obj->queue, obj->messages, 4);
            fn_801E0704(obj->field318);
            OSInitMutex(obj->mutex);
            __register_global_object(obj, fn_801CC3A8, lbl_804D8CB0);
            lbl_805A0600 = 1;
        }

        fn_801DE298(lbl_804D8CC0.queue, 2, 1);
        OSJoinThread(self, 0);
        self->field394 = 0;
    }
}
