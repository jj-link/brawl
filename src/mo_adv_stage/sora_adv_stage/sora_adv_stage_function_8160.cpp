#include <gf/gf_archive.h>
#include <sr/sr_common.h>
#pragma force_active on

struct StageInfo {
    char pad[0x618];
    unsigned int value;
};
struct Stage {
    char pad0[0x1a4];
    gfArchive* mainArchive;
    char pad1[8];
    gfArchive* extraArchive;
    char pad2[0xd4];
    gfArchive* archives[162];
    gfArchive* common;
    gfArchive* special;
    char pad3[0xc];
    StageInfo* info;
};
extern "C" void fn_40_8160(Stage* self, gfArchive** out1, gfArchive** out2, gfArchive** out3, gfArchive** out4, int index) {
    int size1, size2, size3, size4;
    *out1 = 0;
    *out2 = 0;
    *out3 = 0;
    *out4 = 0;
    int idx = index * 2;
    int idx1 = idx + 1;
    gfArchive* a = self->archives[idx1];
    if (!a) {
        int flag;
        if (index == 0x17 || index == 0x1c || (index >= 0x1f && index <= 0x23))
            flag = 1;
        else
            flag = 0;
        void* data;
        if (flag)
            data = self->extraArchive->getData(Data_Type_Misc, idx1, &size1, 0xfffe);
        else
            data = self->mainArchive->getData(Data_Type_Misc, idx1, &size1, 0xfffe);
        a = new ((Heaps::HeapType)15) gfArchive;
        a->setFileImage(data, size1, (Heaps::HeapType)17);
        self->archives[idx1] = a;
    }
    gfArchive* b = self->archives[idx];
    if (!b) {
        int flag;
        if (index == 0x17 || index == 0x1c || (index >= 0x1f && index <= 0x23))
            flag = 1;
        else
            flag = 0;
        void* data;
        if (flag)
            data = self->extraArchive->getData(Data_Type_Misc, idx, &size2, 0xfffe);
        else
            data = self->mainArchive->getData(Data_Type_Misc, idx, &size2, 0xfffe);
        b = new ((Heaps::HeapType)15) gfArchive;
        b->setFileImage(data, size2, (Heaps::HeapType)17);
        self->archives[idx] = b;
    }
    if (!self->common) {
        void* data = self->extraArchive->getData(Data_Type_Misc, 300, &size3, 0xfffe);
        self->common = new ((Heaps::HeapType)15) gfArchive;
        self->common->setFileImage(data, size3, (Heaps::HeapType)17);
    }
    *out3 = self->common;
    int flag;
    if (index == 0x17 || index == 0x1c || (index >= 0x1f && index <= 0x23))
        flag = 1;
    else
        flag = 0;
    if (flag) {
        unsigned int id = (self->info->value + 19) % 20 + 200;
        if (!self->special) {
            void* data = self->extraArchive->getData(Data_Type_Misc, id, &size4, 0xfffe);
            self->special = new ((Heaps::HeapType)15) gfArchive;
            self->special->setFileImage(data, size4, (Heaps::HeapType)17);
        }
        *out4 = self->special;
    }
    *out1 = a;
    *out2 = b;
}