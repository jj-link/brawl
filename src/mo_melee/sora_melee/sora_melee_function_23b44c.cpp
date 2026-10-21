#include <gf/gf_archive.h>
#include <types.h>
#pragma force_active on

struct fn27ArchiveHolder {
    u8 pad[0xa0];
    gfArchive* m_archive;
};

extern "C" {
void fn_27_23B44C(fn27ArchiveHolder* holder, void** out1, int* size1, void** out2, int* size2) {
    *out1 = nullptr;
    *out2 = nullptr;
    *size1 = 0;
    *size2 = 0;
    *out1 = holder->m_archive->getData((ARCNodeType)1, 7, size1, 0xFFFE);
    *out2 = holder->m_archive->getData((ARCNodeType)2, 0, size2, 0xFFFE);
}
}
