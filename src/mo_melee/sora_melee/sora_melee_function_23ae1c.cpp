#include <gf/gf_archive.h>
#include <gf/gf_file_io.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_memory_pool.h>
#include <revolution/CX/CXCompression.h>
#pragma force_active on

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void fn_27_23AE1C();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_27_23ACD8();
    virtual void fn_27_23FB1C();
    virtual void fn_27_23FD0C();
    virtual void fn_27_23B448();
    virtual void fn_27_23ABB4();
    virtual void fn_27_23FEB4();
    virtual void fn_27_23AE0C();
    int pad40;
    unsigned char state, pad45, enabled, flag;
    char path[0x58];
    gfArchive* archive;
    char padA4[0x14];
    char* buffer;
    char* decompressed;
    char* compressed;
    char padC4[8];
    gfArchive* inner;
    char padD0[12];
    gfFileIOHandle handle;
};
extern "C" void* fn_80158BE0();
extern "C" void fn_801592A0(void*);
extern "C" void fn_801592F0(void*);
extern "C" void fn_27_23B074(gfTask*);

extern "C" void fn_27_23AE1C(gfTask* self) {
    if (self->enabled) {
        switch ((int)self->state) {
        case 0:
            if (self->flag != 1) self->state = 1;
            break;
        case 1: {
            if (!g_HeapInfos[16].m_name) {
                self->state = 5;
                break;
            }
            self->fn_27_23AE0C();
            fn_801592A0(fn_80158BE0());
            self->archive = new ((Heaps::HeapType)16) gfArchive;
            self->inner = new ((Heaps::HeapType)16) gfArchive;
            int size = gfFileIO::getFileSize(self->path);
            int freeSize = gfHeapManager::getMaxFreeSize((Heaps::HeapType)16) - 0x1800;
            char* buffer = (char*)gfHeapManager::alloc((Heaps::HeapType)16, freeSize);
            self->buffer = buffer;
            self->decompressed = buffer;
            self->compressed = buffer + freeSize - size;
            self->handle.readRequest(self->path, self->compressed, 0, 0);
            self->state = 2;
            break;
        }
        case 2:
            if (self->handle.isReady()) {
                int size = CXGetUncompressedSize(self->decompressed);
                CXUncompressLZ(self->compressed, self->decompressed);
                self->archive->setFileImage(self->decompressed, size, (Heaps::HeapType)16);
                void* data = self->archive->getData(Data_Type_Misc, 3, &size, 0xfffe);
                self->inner->setFileImage(data, size, (Heaps::HeapType)16);
                self->state = 3;
            }
            break;
        case 3:
            if (self->flag == 1) self->state = 5;
            fn_27_23B074(self);
            break;
        case 5:
            if (self->archive) delete self->archive;
            if (self->inner) delete self->inner;
            gfHeapManager::free(self->buffer);
            fn_801592F0(fn_80158BE0());
            self->inner = 0;
            self->buffer = 0;
            self->archive = 0;
            if (self->flag == 1) self->state = 6;
            else self->state = 0;
            break;
        }
    }
}