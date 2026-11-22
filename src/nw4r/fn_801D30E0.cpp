#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#include <revolution/OS/OSInterrupt.h>

#pragma force_active on

using namespace nw4r::ut;
typedef detail::LinkListImpl::Iterator Iterator;

extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(
    void*, LinkListNode*);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
    void*, Iterator, LinkListNode*);
extern "C" void fn_801D16D0(void*);

extern "C" void fn_801D30E0(char* self, char* object) {
    BOOL outer = OSDisableInterrupts();
    BOOL inner = OSDisableInterrupts();
    LinkListNode* node = (LinkListNode*)(object + 0x124);

    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(
        self + 4, node);

    Iterator end((LinkListNode*)(self + 0x14));
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
        self + 0x10, end, node);

    OSRestoreInterrupts(inner);
    BOOL inner2 = OSDisableInterrupts();

    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(
        self + 0x10, node);

    Iterator it((LinkListNode*)(self + 8));
    Iterator first(*(LinkListNode**)(self + 8));
    while (!(it == first)) {
        Iterator previous = it;
        --previous;
        if (*(int*)((char*)previous.operator->() - 0x70) >
            *(int*)(object + 0xB4)) {
            it = previous;
        } else {
            break;
        }
    }

    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
        self + 4, it, node);
    OSRestoreInterrupts(inner2);

    LinkListNode* stop = (LinkListNode*)(self + 8);
    while (node != stop) {
        int priority = *(int*)((char*)node - 0x70);
        char* current = (char*)node - 0x124;
        if (priority > 1) {
            if (priority != 0xFF)
                fn_801D16D0(current);
            node = node->GetNext();
        } else {
            break;
        }
    }

    OSRestoreInterrupts(outer);
}
