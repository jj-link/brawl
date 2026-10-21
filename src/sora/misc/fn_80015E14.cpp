#include "gf/gf_archive.h"
#pragma force_active on

extern "C" void* fn_80015E34(gfArchive*, int, ARCNodeType, int, int*, unsigned short);

void* gfArchive::getData(ARCNodeType nodeType, int fileIndex, int* nodeSize, u16 archiveId) {
    return fn_80015E34(this, 0, nodeType, fileIndex, nodeSize, archiveId);
}
