#pragma force_active on
typedef unsigned int u32;

class soModelModuleImpl {
public:
    u32 getCorrectNodeId(unsigned long nodeId);
private:
    char pad_0000[0x8c];
    u32* m_nodeIdTable;
};

u32 soModelModuleImpl::getCorrectNodeId(unsigned long nodeId) {
    if (nodeId >= 300) {
        unsigned long idx = nodeId - 300;
        u32* table = m_nodeIdTable;
        return table[idx];
    }
    return nodeId;
}
