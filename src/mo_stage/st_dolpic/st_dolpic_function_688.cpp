#pragma force_active on
enum ARCNodeType { ARC_NODE_TYPE_DUMMY = 0 };

class gfArchive {
public:
    void* getData(ARCNodeType, int, unsigned short);
};

class grFixedPathCollection {
public:
    void relocation();
};

extern "C" void fn_46_688(char* self) {
    gfArchive* archive = *(gfArchive**)(self + 0x1a0);
    void* data = archive->getData((ARCNodeType)1, 0x28, 0xFFFE);
    if (data != 0 && data != 0) {
        ((grFixedPathCollection*)data)->relocation();
        *(void**)(self + 0x758) = data;
    }
}
