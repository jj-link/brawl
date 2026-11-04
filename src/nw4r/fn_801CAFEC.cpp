#include <nw4r/ut/ut_LinkList.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on
using namespace nw4r::ut;
extern "C" {
void fn_801CABC8(int*);
void* fn_801CABE8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_8015C2BC(void*, LinkListNode**);
void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(void*, LinkListNode**, LinkListNode*);
}
struct List { unsigned int size; LinkListNode* next; LinkListNode* prev; };
struct Object { char pad[12]; List list; char pad2[0x30]; OSMutex mutex; };
extern "C" void fn_801CAFEC(Object* self) {
    if (self->list.size >= 2) {
        OSMutex* mutex = &self->mutex;
        OSLockMutex(mutex);
        List lists[128];
        __construct_array(lists, (void (*)(void*))fn_801CABC8, (void (*)(void*))fn_801CABE8, 12, 128);
        List* current;
        while (self->list.size != 0) {
            current = (List*)self->list.next;
            LinkListNode* node = (LinkListNode*)current;
            LinkListNode* it = node;
            fn_8015C2BC(&self->list, &it);
            int value = *(unsigned char*)((char*)node - 0x54) + *(int*)((char*)node - 0x88);
            int index;
            index = value > 127 ? 127 : (value < 0 ? 0 : value);
            List* list = &lists[index];
            LinkListNode* end = (LinkListNode*)((char*)list + 4);
            Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(list, &end, node);
        }
        current = lists;
        LinkListNode* node;
        for (int i = 0; i < 128; i++, current++) {
            if (current->size != 0) {
                while (current->size != 0) {
                    node = current->next;
                    LinkListNode* it = node;
                    fn_8015C2BC(current, &it);
                    LinkListNode* end = (LinkListNode*)&self->list.next;
                    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(&self->list, &end, node);
                }
            }
        }
        __destroy_arr(lists, (void (*)(void*, int))fn_801CABE8, 12, 128);
        OSUnlockMutex(mutex);
    }
}