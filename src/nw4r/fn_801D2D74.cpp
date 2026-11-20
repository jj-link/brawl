#pragma force_active on

#include <types.h>
#include <nw4r/ut/ut_LinkList.h>

struct Node {
    Node* next;
    Node* prev;
};

struct Manager {
    int field0;
    int size;
    Node head;
    int field10;
    int field14;
};

struct Object {
    u8 pad0[0x9c];
    int count1;
    int count2;
    void (*callback)(Object*, int, void*);
    void* callbackArg;
    int padac[2];
    int priority;
    int padb8[0x4b];
    Node node;
};

extern "C" void fn_801D1140(Object*);
extern "C" void fn_801D0DA4(Object*);
extern "C" int fn_801D0B68(Object*, int, int, int, int, int);
extern "C" void fn_801D16D0(Object*);
extern "C" void* fn_801BE7BC();
extern "C" void fn_801BE8A0(char*, Object*);
extern "C" BOOL OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(BOOL);
extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(char*, Node*);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char*, void**, void*);

extern "C" Object* fn_801D2D74(
    Manager* self, int a, int b, int priority, int d, int e)
{
    int r26 = d;
    int r27 = e;
    BOOL enabled = OSDisableInterrupts();

    if (self->field10 == 0) {
        int result = 0;
        if (self->field10 == 0) {
            Object* old = (Object*)((char*)self->head.next - 0x124);

            if (old->priority > priority) {
                result = 0;
            } else {
                result = old->count1 * old->count2;
                fn_801D1140(old);
                fn_801D0DA4(old);
                if (old->callback) {
                    old->callback(old, 2, old->callbackArg);
                }
            }
        }

        if (result == 0) {
            OSRestoreInterrupts(enabled);
            return (Object*)0;
        }
    }

    Object* obj = (Object*)((char*)self->field14 - 0x124);

    if (!fn_801D0B68(obj, a, b, priority, r26, r27)) {
        OSRestoreInterrupts(enabled);
        return (Object*)0;
    }

    obj->priority = (u8)priority;

    BOOL inner = OSDisableInterrupts();
    char* node = (char*)obj + 0x124;
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(
        (char*)self + 0x10, (Node*)node);

    {
        nw4r::ut::detail::LinkListImpl::Iterator it(
            reinterpret_cast<nw4r::ut::LinkListNode*>(&self->head));
        nw4r::ut::detail::LinkListImpl::Iterator stop(
            reinterpret_cast<nw4r::ut::LinkListNode*>(self->head.next));
        while (!(it == stop)) {
            nw4r::ut::detail::LinkListImpl::Iterator previous = it;
            --previous;
            Object* cur = (Object*)((char*)previous.operator->() - 0x124);
            if (cur->priority <= obj->priority) {
                break;
            }
            it = previous;
        }

        void* itNode = it.operator->();
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
            (char*)self + 4, &itNode, (void*)node);
    }

    OSRestoreInterrupts(inner);

    Node* end = &self->head;
    Node* cur2 = (Node*)node;
    while (cur2 != end) {
        Object* current = (Object*)((char*)cur2 - 0x124);
        if (current->priority <= 1) {
            break;
        }
        if (current->priority != 0xff) {
            fn_801D16D0(current);
        }
        cur2 = cur2->next;
    }

    fn_801BE8A0((char*)fn_801BE7BC(), obj);
    OSRestoreInterrupts(enabled);
    return obj;
}