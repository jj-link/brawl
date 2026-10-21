#include "gf/gf_archive.h"
#pragma force_active on

extern "C" void* fn_80015E34(gfArchive*, int, ARCNodeType, int, int*, unsigned short);

void* gfArchive::getData(ARCNodeType nodeType, int fileIndex, u16 archiveId) {
    int sp8;
    return fn_80015E34(this, 0, nodeType, fileIndex, &sp8, archiveId);
}
