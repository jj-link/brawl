#include <gf/gf_archive.h>
#include <gf/gf_file_io.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_memory_pool.h>
#include <gf/gf_module.h>
#include <st/module.h>
#include <revolution/CX/CXCompression.h>
#include <revolution/OS/OSCache.h>

#pragma force_active on

extern gfModuleManager* lbl_805A0038;
extern "C" {
extern void* g_ecMgr;
unsigned int fn_27_23F524(void*);
unsigned int fn_80015530(gfArchive*, const char*, void*, int);
void fn_8005EA4C(void*, int, void*, unsigned int, int, int);
void fn_8005EB68(void*, int);
}

struct Object_vptr_3c_base {
    char pad[0x3c];
};

struct StageInfo {
    char pad[0x1a];
    unsigned short kind;
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual int slot25();
    virtual void slot26();
    virtual int slot27();
    virtual void slot28();

    StageInfo* info;
    unsigned char state;
    unsigned char pad45;
    unsigned char enabled;
    unsigned char flag;
    char path[0x40];
    const char* moduleName;
    char pad8c[8];
    int effectId;
    unsigned char skipModule;
    unsigned char special;
    char pad9a[2];
    gfArchive* archive;
    gfArchive* archive0;
    gfArchive* archive1;
    gfArchive* archive2;
    void* data0;
    void* data1;
    void* data2;
    char* allocation;
    char* cursor;
    char* fileBuffer;
    char padc4[4];
    Object_vptr_3c* other;
};

extern "C" void fn_27_23F5C0(Object_vptr_3c* self) {
    if (self->enabled != 0) {
        switch ((int)self->state) {
        case 0:
            if (self->flag == 1) {
                self->state = 6;
                break;
            }
            if (self->info->kind != 0 &&
                (self->other == 0 || self->other->slot25() != 0)) {
                self->state = 1;
            }
            break;

        case 1:
            if (g_HeapInfos[17].m_name == 0) {
                if (self->flag == 1)
                    self->state = 6;
                else
                    self->state = 0;
                break;
            }
            if (self->special == 1 &&
                self->info->kind != 0x28 &&
                self->info->kind != 0x26) {
                if (self->flag == 1)
                    self->state = 6;
                else
                    self->state = 0;
                break;
            }
            self->slot28();
            if (self->archive == 0)
                self->archive = new ((Heaps::HeapType)0x11) gfArchive;
            if (self->skipModule == 0) {
                self->moduleName = moGetStageModuleName(
                    (Stages::srStageKind)self->info->kind);
                if (self->moduleName != 0) {
                    gfModuleManager::LoadRequestResult result;
                    lbl_805A0038->setTempolaryLoadHeap((Heaps::HeapType)0x11);
                    gfModuleManager::loadModuleRequest(
                        &result, lbl_805A0038, self->moduleName,
                        (Heaps::HeapType)0x33, true, false);
                    lbl_805A0038->setTempolaryLoadHeap((Heaps::HeapType)0x11);
                }
            }
            self->state = 7;
            break;

        case 7: {
            if (self->moduleName != 0 && self->skipModule == 0 &&
                !lbl_805A0038->isLoaded(self->moduleName))
                break;

            int fileSize = gfFileIO::getFileSize(self->path);
            unsigned int size = gfHeapManager::getMaxFreeSize((Heaps::HeapType)0x11);
            size -= fn_27_23F524(self);
            self->allocation = (char*)gfHeapManager::alloc((Heaps::HeapType)0x11, size);
            self->cursor = self->allocation;
            self->fileBuffer = self->allocation + size - fileSize;
            self->archive->m_Heap = gfHeapManager::getHeap((Heaps::HeapType)0x11);
            if (fn_80015530(self->archive, self->path, self->fileBuffer, 0) == 1) {
                self->archive0 = new ((Heaps::HeapType)0x11) gfArchive;
                self->archive1 = new ((Heaps::HeapType)0x11) gfArchive;
                self->archive2 = new ((Heaps::HeapType)0x11) gfArchive;
                self->state = 2;
            } else {
                self->state = 5;
            }
            break;
        }

        case 2:
            if (self->archive->unk9) {
                void* data = self->archive->getData(Data_Type_Misc, 0, 0xfffe);
                unsigned int size = CXGetUncompressedSize(data);
                if (size > 0x20) {
                    self->data0 = self->cursor;
                    self->cursor += size;
                    CXUncompressLZ(data, self->data0);
                    DCFlushRange(self->data0, size);
                    self->archive0->setFileImage(self->data0, size, (Heaps::HeapType)0x11);
                }

                data = self->archive->getData(Data_Type_Misc, 1, 0xfffe);
                size = CXGetUncompressedSize(data);
                if (size > 0x20) {
                    self->data1 = self->cursor;
                    self->cursor += size;
                    CXUncompressLZ(data, self->data1);
                    DCFlushRange(self->data1, size);
                    self->archive1->setFileImage(self->data1, size, (Heaps::HeapType)0x11);
                }

                data = self->archive->getData(Data_Type_Misc, 2, 0xfffe);
                if (data != 0) {
                    size = CXGetUncompressedSize(data);
                    if (size > 0x20) {
                        self->data2 = self->cursor;
                        self->cursor += size;
                        CXUncompressLZ(data, self->data2);
                        DCFlushRange(self->data2, size);
                        self->archive2->setFileImage(self->data2, size, (Heaps::HeapType)0x11);
                        fn_8005EA4C(g_ecMgr, self->effectId, self->data2, size, 0, 0xff);
                    }
                }
                delete self->archive;
                self->archive = 0;
                self->state = 3;
            }
            break;

        case 3:
            if (self->slot27() != 0)
                self->state = 5;
            break;

        case 5:
            if (self->moduleName != 0)
                lbl_805A0038->destroy(self->moduleName);
            fn_8005EB68(g_ecMgr, self->effectId);
            if (self->archive != 0)
                delete self->archive;
            if (self->archive0 != 0)
                delete self->archive0;
            if (self->archive1 != 0)
                delete self->archive1;
            if (self->archive2 != 0)
                delete self->archive2;
            gfHeapManager::free(self->allocation);
            self->archive = 0;
            self->allocation = 0;
            self->archive0 = 0;
            self->archive1 = 0;
            self->archive2 = 0;
            self->data0 = 0;
            self->data1 = 0;
            self->data2 = 0;
            if (self->flag == 1)
                self->state = 6;
            else
                self->state = 0;
            break;
        }
    }
}
