#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on
using namespace nw4r::ut;
class ListAccess : public detail::LinkListImpl {
public:
    using detail::LinkListImpl::Insert;
    using detail::LinkListImpl::Erase;
};
extern "C" void fn_801BD2EC(char* self);
extern "C" void fn_801CF86C(char* self) {
    OSMutex* mutex;
    fn_801BD2EC(self);
    char* list;
    int v = *(unsigned char*)(self + 0x74) + *(int*)(self + 0x40);
    int y = v > 127 ? 127 : (v < 0 ? 0 : v);
    list = *(char**)(self + 0x924);
    mutex = (OSMutex*)(list + 0x10);
    OSLockMutex(mutex);
    LinkListNode* node = (LinkListNode*)(self + 0xb8);
    ((ListAccess*)(list + 4))->Erase(node);
    detail::LinkListImpl::Iterator it(*(LinkListNode**)(list + 8));
    while (!(it == detail::LinkListImpl::Iterator((LinkListNode*)(list + 8)))) {
        int a = *(unsigned char*)((char*)it.operator->() - 0x44) + *(int*)((char*)it.operator->() - 0x78);
        int x = a > 127 ? 127 : (a < 0 ? 0 : a);
        if (y < x) break;
        ++it;
    }
    ((ListAccess*)(list + 4))->Insert(it, node);
    OSUnlockMutex(mutex);
}
