#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

enum ARCNodeType { ARCNodeType_Dummy = 0 };

class gfArchive {
public:
    void* getData(ARCNodeType type, int idx, u16 flags);
};

extern "C" void fn_27_228238(void* dst, void* data);

class Stage {
public:
    void loadStageAttrParam(gfArchive* archive, int idx);
};

void Stage::loadStageAttrParam(gfArchive* archive, int idx) {
    void* data = archive->getData((ARCNodeType)1, idx, 0xFFFE);
    if (data) {
        fn_27_228238((char*)this + 0xf8, data);
    }
}
