#include <gf/gf_file_io_manager.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on

void gfFileIOManager::push(gfFileIORequest* req) {
    char* queue = (char*)m_queue1;
    OSLockMutex((OSMutex*)queue);
    char* data = *(char**)(queue + 0x18);
    unsigned short count = (*(unsigned short*)(data + 2))++;
    ((gfFileIORequest**)(data + 4))[count] = req;
    OSUnlockMutex((OSMutex*)queue);
}