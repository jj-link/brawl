#pragma force_active on
#include <gf/gf_archive.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <revolution/OS/OSError.h>
typedef unsigned char u8;
extern "C" {
extern char lbl_27_data_56728[];
int fn_8018E5D4(void*, void*);
char* fn_8018D20C(const void*, int);
void* fn_8018F340(void*, u32);
u32 fn_8018F394(const void*);
}
struct grGimmick {
    void* name;
    u8 pad4[0x58];
    s16 resourceId;
    u8 pad5E[0xE];
    u8 flags;
    void bindData(gfArchive* archive);
};
void grGimmick::bindData(gfArchive* archive)
{
    char* base = lbl_27_data_56728;
    s16 id = resourceId;
    int sp24;
    int sp20;
    int sp1C;
    void* sp18;
    void* sp14;
    void* sp10;
    void* spC;
    int sp8;
    u32 result;
    if (id != -1) {
        sp24 = (int)archive->getData(Data_Type_Model, id, 0xFFFE);
        if (sp24 == 0) {
            OSReport(base + 0x70, name, (int)resourceId);
            return;
        }
        nw4r::g3d::ResFile::Init(&sp24);
        sp8 = sp24;
        result = fn_8018E5D4(&sp24, &sp8);
        if (result == 0) {
            u32 i = 0;
            do {
                sp20 = (int)archive->getData(Data_Type_Tex, (int)i, 0xFFFE);
                if (sp20 != 0) {
                    if (((flags >> 2) & 1) == 0) {
                        nw4r::g3d::ResFile::Init(&sp20);
                        flags |= 4;
                    }
                    sp1C = sp20;
                    result = fn_8018E5D4(&sp24, &sp1C);
                }
                if (result == 1)
                    break;
            } while (++i < 0x100);
        }
        if (result == 0) {
            OSReport(base + 0x90);
            OSReport(base + 0xD4);
            OSReport(base + 0xD8);
            OSReport(base + 0xD4);
            OSReport(base + 0x90);
            OSReport(base + 0x118, name);
            u32 i = 0;
            while (i < ((nw4r::g3d::ResFile*)&sp24)->GetResMdlNumEntries()) {
                char* model = fn_8018D20C(&sp24, (int)i);
                int offset = *(int*)(model + 0x3C);
                void* data = offset ? (void*)(model + offset) : 0;
                OSReport(base + 0x128, data);
                u32 j = 0;
                while (j < fn_8018F394(
                               &(spC = fn_8018D20C(&sp24, (int)i)))) {
                    sp18 = fn_8018D20C(&sp24, (int)i);
                    void* material = fn_8018F340(&sp18, j);
                    int materialOffset = *(int*)((char*)material + 0x8);
                    data = materialOffset ? (void*)((char*)material + materialOffset) : 0;
                    OSReport(base + 0x150, data);
                    u32 offsetInList;
                    u32 k = 0;
                    offsetInList = 0;
                    while (k < *(u32*)((char*)fn_8018F340(
                                           &(sp10 = fn_8018D20C(&sp24, (int)i)), j) +
                                       0x2C)) {
                        sp14 = fn_8018D20C(&sp24, (int)i);
                        material = fn_8018F340(&sp14, j);
                        int textureOffset = *(int*)((char*)material + 0x30);
                        char* list = textureOffset
                                         ? (char*)material + textureOffset
                                         : 0;
                        char* entry = list + offsetInList;
                        u32 entryOffset = *(u32*)entry;
                        data = entryOffset ? (void*)(entry + entryOffset) : 0;
                        OSReport(base + 0x168, data);
                        offsetInList += 0x34;
                        ++k;
                    }
                    ++j;
                }
                ++i;
            }
        }
    }
}