#pragma force_active on
#include <nw4r/g3d/g3d_resfile.h>
#include <sr/sr_common.h>
#include <gf/gf_3d_scene.h>

extern "C" {
extern unsigned char lbl_40_data_1FC0[];
extern const float lbl_40_rodata_14C;
void fn_27_2381FC(void*);
void fn_27_238318(void*, void*);
void fn_8018E308(nw4r::g3d::ResFile*);
int fn_8018E588(nw4r::g3d::ResFile*);
void fn_801971D0(void*, void*);
void fn_40_FC34();
void fn_40_FC38();
void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);
}

struct Object {
    void* field0;
    void* vtable;
    int field8;
    void* scene;
    int field10;
    void* array14;
    void* array18;
    void* array1C;
    void* array20;
    unsigned char field24;
    char pad25[3];
    float field28;
    unsigned char field2C;
    char pad2D[3];
    int field30;
    int count34;
    int count38;
    int count3C;
    int count40;
};

extern "C" Object* fn_40_FAC4(Object* self, void* data, int arg2, signed char arg3) {
    self->field0 = 0;
    self->field8 = 0;
    self->vtable = lbl_40_data_1FC0;
    self->scene = 0;
    self->field10 = arg2;
    self->field28 = lbl_40_rodata_14C;
    self->field2C = 0;
    fn_27_2381FC(&self->field30);
    nw4r::g3d::ResFile file(data);
    fn_8018E308(&file);
    if (file.IsValid() && fn_8018E588(&file) != 0) {
        void* scene = file.GetResAnmScn(0).ptr();
        self->scene = scene;
        void* temp = scene;
        fn_801971D0(&self->scene, &temp);
    }
    fn_27_238318(&self->field30, &self->scene);
    self->array14 = operator new[](self->count34 * 0x14, Heaps::StageInstance);
    int count = self->count38;
    self->array18 = __construct_new_array(
        operator new[](count * 0x2C + 0x10, Heaps::StageInstance),
        fn_40_FC34, 0, 0x2C, count);
    count = self->count3C;
    self->array1C = __construct_new_array(
        operator new[](count * 0x20 + 0x10, Heaps::StageInstance),
        fn_40_FC38, 0, 0x20, count);
    self->array20 = operator new[](self->count40 * 0x2C, Heaps::StageInstance);
    void* scene = *(void**)((char*)g_gfSceneRoot + 0x40);
    *(int*)((char*)scene + 0xD4) = 0;
    self->field24 = arg3;
    return self;
}
