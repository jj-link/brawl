#pragma force_active on
class gfArchive;

namespace Heaps {
    enum HeapType { HeapType_Unk = 0 };
}

struct Owner {
    gfArchive* m_archive;
    char pad[0x14 - 0x04];
    unsigned char m_state;
};

struct EcMgr {
    char pad[0x44];
    int m_heapType;
};

extern "C" {
    extern EcMgr* g_ecMgr;
    void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
    gfArchive* __ct__9gfArchiveFv(gfArchive* self);
    void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(gfArchive* self, void* file, int size, int heap);
    void fn_80064284(Owner* self, int arg);
    void fn_80063FEC(Owner* self, void* arg);
}

extern "C" void fn_80063F40(Owner* self, void* file, int size, void* arg) {
    gfArchive* archive = (gfArchive*)__nw__FUlQ25Heaps8HeapType(0x80, g_ecMgr->m_heapType);
    if (archive != 0) {
        archive = __ct__9gfArchiveFv(archive);
    }
    self->m_archive = archive;
    if (archive == 0) {
        fn_80064284(self, 0);
        return;
    }
    setFileImage__9gfArchiveFPviQ25Heaps8HeapType(archive, file, size, g_ecMgr->m_heapType);
    self->m_state = 2;
    fn_80063FEC(self, arg);
}
