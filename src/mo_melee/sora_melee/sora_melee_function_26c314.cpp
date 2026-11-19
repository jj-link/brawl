#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern "C" {
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void* fn_801AFFDC(void*, bool);
void fn_80191B9C(void*, unsigned long, GXColor*);
void fn_80191AA4(void*, unsigned long, GXColor*);
void DCStore__Q34nw4r3g3d6ResMatFb(void*, bool);
}

struct Self {
    char pad[0x44];
    nw4r::g3d::ScnMdl** holder;
};

struct Access {
    nw4r::g3d::ScnMdl::CopiedMatAccess value;
    char pad[4];
    Access(nw4r::g3d::ScnMdl* obj, unsigned long id) : value(obj, id) {}
};

extern "C" void fn_27_26C314(Self* self, const char* name, unsigned char alpha) {
    void* resource = 0;
    void* mat = 0;
    void* channels = 0;
    unsigned long colorBits = 0xFFFFFFFF;
    nw4r::g3d::ScnMdl* model = *self->holder;

    if (model != 0) {
        resource = *(void**)((char*)model + 0xE8);
        if (resource != 0) {
            mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(&resource, name);
            if (mat != 0) {
                unsigned long id = *(unsigned long*)((char*)mat + 0xC);
                Access access(model, id);
                channels = fn_801AFFDC(&access.value, false);
                if (channels != 0) {
                    unsigned long copyBits;
                    fn_80191B9C(&channels, 2, (GXColor*)&colorBits);
                    ((unsigned char*)&colorBits)[3] = alpha;
                    copyBits = colorBits;
                    fn_80191AA4(&channels, 2, (GXColor*)&copyBits);
                    DCStore__Q34nw4r3g3d6ResMatFb(&mat, false);
                }
            }
        }
    }
}