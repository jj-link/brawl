#include <string.h>
#pragma force_active on

namespace Heaps {
    enum HeapType { HeapType_StageInstance = 15 };
}

void* operator new[](unsigned long size, Heaps::HeapType heap);
void operator delete(void* p);

class grGimmick {
public:
    void setTgtNode(const char* name);
    char m_pad[0xB8];
    char* m_tgtNode;
};

void grGimmick::setTgtNode(const char* name) {
    if (name != 0) {
        int len = strlen(name);
        if (len != 0) {
            if (name != 0) {
                operator delete(m_tgtNode);
            }
            m_tgtNode = new (Heaps::HeapType_StageInstance) char[len + 1];
            memset(m_tgtNode, 0, len + 1);
            strncpy(m_tgtNode, name, len);
        }
    }
}
