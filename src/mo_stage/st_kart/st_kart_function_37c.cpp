#pragma force_active on
typedef unsigned short u16;

enum ARCNodeType { ARC_NODE_TYPE_ONE = 1 };

class gfArchive {
public:
    void* getData(ARCNodeType type, int id, u16 index);
};

class grFixedPathCollection {
public:
    void relocation();
};

class StKartLoader {
public:
    char pad0[0x1a0];
    gfArchive* archive;
    char pad1[0x1d8 - 0x1a4];
    grFixedPathCollection* fixedPath;
};

extern "C" void fn_49_37C(StKartLoader* self) {
    self->fixedPath = 0;
    grFixedPathCollection* p = (grFixedPathCollection*)self->archive->getData(ARC_NODE_TYPE_ONE, 4, 0xFFFE);
    if (p != 0 && p != 0) {
        p->relocation();
        self->fixedPath = p;
    }
}
