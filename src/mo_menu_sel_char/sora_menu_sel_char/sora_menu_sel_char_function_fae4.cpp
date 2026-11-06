#include <nw4r/g3d/g3d_scngroup.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on
struct Entry { unsigned char pad[16]; unsigned char active; unsigned char tail[3]; };
struct Model { char pad[0x10]; nw4r::g3d::ScnObj* object; };
struct Self { char pad[0x3d8]; void* object; Model* models[5]; char pad2[0x114]; nw4r::g3d::ScnGroup* group; };
extern "C" Entry lbl_10_data_610[5][2];
extern "C" char lbl_10_data_6E8[];
extern "C" void fn_800B330C(void*, void*, int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern "C" void fn_10_FAE4(Self* self, int count, int flag) {
    char buf[8];
    int i;
    nw4r::g3d::ScnGroup* group = self->group;
    lbl_10_data_610[count - 1][!flag].active = 3;
    fn_800B330C(self->object, &lbl_10_data_610[count - 1][!flag], 0);
    for (i = 0; i < 5; i++) {
        group->Remove(self->models[i]->object);
    }
    for (i = 0; i < count; i++) {
        sprintf(buf, lbl_10_data_6E8, i + 2);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(group, self->models[i]->object, buf);
    }
}