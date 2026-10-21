#pragma force_active on
enum ARCNodeType { ARC_NODE_TYPE_A = 1, ARC_NODE_TYPE_B = 2 };

class gfArchive {
public:
    void* getData(ARCNodeType type, int idx, int* outSize, unsigned short mask);
};

class sceneStage {
public:
    char m_pad[0x1b0];
    gfArchive* m_archive;
};

extern "C" {
void fn_40_8478(sceneStage* self, void** out1, void** out2)
{
    int sz1;
    int sz2;
    *out1 = 0;
    *out2 = 0;
    *out1 = self->m_archive->getData(ARC_NODE_TYPE_A, 7, &sz1, 0xFFFE);
    *out2 = self->m_archive->getData(ARC_NODE_TYPE_B, 0, &sz2, 0xFFFE);
}
}
