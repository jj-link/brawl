#include <types.h>
#include <gf/gf_module.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on
extern "C" {
void* fn_80026828(void*, void*, u32);
int strcmp(const char*, const char*);
char* strcpy(char*, const char*);
char* strncpy(char*, const char*, size_t);
char* strncat(char*, const char*, size_t);
extern char lbl_80422D00[];
}
static inline int findModule(gfModuleInfo* infos, const char* name, char* nameptr) {
    char* n = nameptr;
    gfModuleInfo* p = infos;
    int i = 0;
    do {
        if (((p->m_flags >> 5) & 1) && strcmp(n, name) == 0)
            return i;
        i++;
        p++;
        n += 0x3c;
    } while (i < 16);
    return -1;
}
static inline int findFree(gfModuleInfo* infos) {
    for (int i = 0; i < 16; i++) {
        if (!((infos[i].m_flags >> 5) & 1))
            return i;
    }
    return -1;
}
void gfModuleManager::loadModuleRequestOnImage(const char* moduleName, HeapType heapType, gfModuleHeader* moduleHeader, int* nodeSize) {
    void* heap = gfHeapManager::getHeap(heapType);
    gfModuleInfo* infos = m_moduleInfos;
    int idx = findModule(infos, moduleName, &m_moduleInfos[0].m_moduleName);
    gfModuleInfo* info;
    if (idx != -1) {
        info = &m_moduleInfos[idx];
    } else {
        idx = findFree(infos);
        info = &m_moduleInfos[idx];
        info->m_module = 0;
        info->m_heap = 0;
        info->m_buffer = 0;
        {
            gfFileIOHandle tmp;
            info->m_fileHandle = 0;
        }
        union { unsigned int v; struct { unsigned int pad:24, b7:1, b6:1, b5:1, b4:1, b3:1, b2:1, b1:1, b0:1; } b; } f;
        f.v = (u8)info->m_flags;
        info->m_moduleName = 0;
        f.b.b6 = 0;
        f.b.b3 = 0;
        *(void**)info->_12 = 0;
        f.b.b4 = f.b.b3;
        f.b.b5 = f.b.b4;
        f.b.b7 = f.b.b5;
        info->m_heap = 0;
        f.v |= 0xA4;
        info->m_flags = f.v;
        info->_24 = 0;
        strncpy(&info->m_moduleName, moduleName, 0x1F);
    }
    info->_24++;
    if ((u8)info->_24 == 1) {
        char buf[0x40];
        strcpy(buf, lbl_80422D00);
        strncat(buf, moduleName, 0x20);
        info->m_heap = heap;
        u8 f = info->m_flags;
        info->m_buffer = (int)moduleHeader;
        f = f | 0x70;
        info->m_size = (int)nodeSize;
        info->m_flags = f;
        if (*(void**)info->_12 == 0) {
            info->m_module = gfModule::create(info->m_heap, moduleHeader, info->m_size);
            info->m_flags |= 0x04;
        } else {
            info->m_module = (gfModule*)fn_80026828(*(void**)info->_12, moduleHeader, info->m_size);
            info->m_flags &= ~0x04;
        }
        {
            u8* obj = (u8*)info->m_module;
            if (!((obj[8] >> 7) & 1)) {
                obj[8] = obj[8] | 0x80;
                void** p3 = *(void***)obj;
                typedef void* (*F)(void*);
                ((F)p3[0x34 / 4])(p3);
            }
        }
        info->m_buffer = 0;
    }
}