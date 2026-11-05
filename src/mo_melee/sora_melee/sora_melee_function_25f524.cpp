#include <gf/gf_archive.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <revolution/OS/OSError.h>

#pragma force_active on

using nw4r::g3d::ResFile;

extern "C" int fn_8018E5D4(ResFile*, const ResFile*);
extern char lbl_27_data_547E8[];
extern char lbl_27_data_54808[];

struct Owner {
    const char* name;
    u8 padding04[0x58];
    s16 modelIndex;
    u8 padding5E[0xE];
    u8 flags;
};

extern "C" void fn_27_25F524(Owner* self, gfArchive* archive) {
    if (self->modelIndex != -1) {
        ResFile model(archive->getData(Data_Type_Model, self->modelIndex, 0xFFFE));
        ResFile texture(archive->getData(Data_Type_Tex, 0, 0xFFFE));
        if (!model.IsValid()) {
            OSReport(lbl_27_data_547E8, self->name, self->modelIndex);
            return;
        }
        ResFile::Init(&model);
        nw4r::g3d::ResFileData* textureCopy;
        ResFile copy(model);
        int result = fn_8018E5D4(&model, &copy);
        if (result == 0 && texture.IsValid()) {
            if (!((self->flags >> 2U) & 1)) {
                ResFile::Init(&texture);
                self->flags |= 4;
            }
            textureCopy = texture.ptr();
            result = fn_8018E5D4(&model, reinterpret_cast<const ResFile*>(&textureCopy));
        }
        if (result == 0) {
            OSReport(lbl_27_data_54808, self->name);
        }
    }
}
