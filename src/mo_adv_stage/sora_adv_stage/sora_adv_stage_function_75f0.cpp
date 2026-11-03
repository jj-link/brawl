#include <gf/gf_archive.h>
#include <sr/sr_common.h>
#pragma force_active on

extern unsigned int lbl_40_bss_148;
extern "C" void __dt__9gfArchiveFv(gfArchive*, int);

extern "C" void fn_40_75F0(void* self, void* image, int size) {
    gfArchive* archive = new ((Heaps::HeapType)15) gfArchive;
    archive->setFileImage(image, size, (Heaps::HeapType)17);
    *(void**)((char*)self + 0x51c) = 0;
    *(int*)((char*)self + 0x520) = 0;
    unsigned int id = *(unsigned int*)(*(char**)((char*)self + 0x524) + 0x620) >> 24;
    unsigned int* data = (unsigned int*)archive->getData(Data_Type_Misc, id, 0xfffe);
    if (data && data[0] == lbl_40_bss_148) {
        unsigned int value = data[1];
        *(void**)((char*)self + 0x51c) = (char*)data + data[4];
        *(unsigned int*)((char*)self + 0x520) = value;
    }
    if (archive) __dt__9gfArchiveFv(archive, 1);
}