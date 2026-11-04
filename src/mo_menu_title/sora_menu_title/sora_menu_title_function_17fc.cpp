#include <gm/gm_global.h>
#pragma force_active on
struct Object { char pad[0x10]; void* scene; };
struct Context { char pad[0x50]; Object* object; void* manager; };
extern "C" {
extern const char lbl_24_rodata_30[];
extern const char lbl_24_data_594[];
void fn_8007F2B4(void*, void*, int);
void* fn_800B6AC0(void*, const char*);
void fn_80192ECC(void*, float, float, float);
void fn_24_17FC(Context* self) {
    const float* c = (const float*)lbl_24_rodata_30;
    fn_8007F2B4(self->manager, self->object->scene, 0);
    float x = c[0];
    float y = c[1];
    if (!((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1)) {
        void* node = fn_800B6AC0(self->object, lbl_24_data_594);
        fn_80192ECC(&node, c[2] * x, c[2] * y, x);
    } else {
        void* node = fn_800B6AC0(self->object, lbl_24_data_594);
        fn_80192ECC(&node, x, y, x);
    }
}
}