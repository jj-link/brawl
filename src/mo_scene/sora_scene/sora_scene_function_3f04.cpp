#pragma force_active on
enum ARCNodeType {
    ARCNodeType_File = 1
};

namespace Heaps {
    enum HeapType {
        HeapType_Default = 0
    };
}

class gfArchive {
public:
    void* getData(ARCNodeType, int, int*, unsigned short);
    void setFileImage(void*, int, Heaps::HeapType);
};

struct SceneData {
    char pad[0x14];
    Heaps::HeapType heap;
    char pad18[4];
    unsigned char flag7 : 1;
    unsigned char flag6 : 1;
    unsigned char flag5 : 1;
    unsigned char rest : 5;
};

extern "C" void fn_1_3F04(SceneData* self, gfArchive* dest,
                          gfArchive* src, int index) {
    if (!self->flag5 || !self->flag7)
        return;

    int size;
    void* data = src->getData(ARCNodeType_File, index, &size, 0xFFFE);
    dest->setFileImage(data, size, self->heap);
}
