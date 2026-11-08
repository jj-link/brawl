#include <gf/gf_file_io_manager.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on
static inline bool removeRequest(gfFileIORequestQueue* queue, gfFileIORequest* req) {
    OSLockMutex((OSMutex*)queue);
    utQueue<gfFileIORequest*, 128>* requests = *(utQueue<gfFileIORequest*, 128>**)((u8*)queue + 0x18);
    u16* count = (u16*)((u8*)requests + 2);
    bool found = false;
    for (u32 i = 0; i < *count; i++) {
        if (requests->m_elements[i] == req) {
            for (i++; i < *count; i++) {
                requests->m_elements[i-1] = requests->m_elements[i];
            }
            requests->m_elements[*count - 1] = 0;
            --*count;
            found = true;
            break;
        }
    }
    OSUnlockMutex((OSMutex*)queue);
    return found;
}
bool gfFileIOManager::freeRequest(gfFileIORequest* req) {
    if (!removeRequest(m_queue1, req)) {
        removeRequest(m_queue2, req);
    }
    u8* pool = *(u8**)((u8*)this + 0x10);
    int offset = (u8*)req - *(u8**)(pool + 8);
    int index = offset / 164;
    u32* bitmap = *(u32**)(pool + 4);
    u32* word = bitmap + (index >> 5);
    word[1] &= ~(1u << (index & 31));
    req->~gfFileIORequest();
    return true;
}