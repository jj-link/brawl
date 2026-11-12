#include <types.h>
#pragma force_active on

struct ThreadUnit {
    char data[0xE0];
};

struct Energy {
    s32 w00;
    f32 f04;
    f32 f08;
    f32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    u8 b2c;
    s32 w30;
    s32 w34;
    f32 f38;
    f32 f3c;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void* obj, int idx, short* p, short flag);
    char _0x04[0x28];
    ThreadUnit threads[8];
    char _0x72c[0x14];
    char _0x740[0x30];
    Energy energy[14];
};

extern "C" {
void fn_27_87084(void* self, void* owner, void* value);
void fn_27_894D4(void* self, unsigned int idx);
void fn_27_89544(void* self, int idx);
void fn_27_B7148(void* self);
void fn_27_B7B54(void* self);
void fn_27_C7A1C(void* self, int v);
void fn_41_15950(void* self, int v);
void __construct_array(void* p, void* ctor, void* dtor, unsigned long size, unsigned long count);
void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, unsigned long id, unsigned long index);
void fn_41_1AD14();
void fn_41_1ADA0();
extern char lbl_41_data_2760[];
extern char lbl_41_data_27E8[];
extern float lbl_41_rodata_C38;
}

extern "C" void* fn_41_1536C(char* self, void* arg1, int arg2) {
    Object_vptr_0* obj = (Object_vptr_0*)self;
    fn_27_87084(self, arg1, self + 0xaf0);

    char* p = lbl_41_data_2760;
    *(char**)(self + 0x0) = p;
    *(char**)(self + 0x8) = p + 0x6c;
    *(void**)(self + 0x20) = arg1;
    *(int*)(self + 0x24) = 0;
    *(int*)(self + 0x28) = 0;

    __construct_array(self + 0x2c, (void*)fn_41_1AD14, (void*)fn_41_1ADA0, 0xe0, 8);
    fn_27_B7B54(self + 0x72c);
    fn_27_B7148(self + 0x740);
    self[0xaf4] = 0;

    char* q = lbl_41_data_27E8;
    *(char**)(self + 0xaf0) = q;
    *(char**)(self + 0xaf8) = q + 0x34;
    *(char**)(self + 0xafc) = q + 0x40;
    fn_27_C7A1C(self + 0xb00, 0);
    *(float*)(self + 0xbd0) = lbl_41_rodata_C38;

    for (int i = 0; i < 8; i++) {
        short sv = 1;
        obj->slot3(&obj->threads[i], i, &sv, -1);
        fn_27_89544(self, i);
    }

    fn_41_15950(self, arg2);

    void* acc = *(void**)(self + 0x20);
    void** table = (void**)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0x10000 - 0x5807, 0);
    if (table != 0) {
        Energy* e;
        for (int j = 0; j < 0xe; j++) {
            e = (Energy*)table[j];
            if (e != 0) {
                obj->energy[j] = *e;
            }
        }
    }

    short sa = 4;
    obj->slot3(self + 0x72c, 8, &sa, -1);
    fn_27_894D4(self, 8);
    short sb = 8;
    obj->slot3(self + 0x740, 9, &sb, -1);
    fn_27_894D4(self, 9);
    return self;
}