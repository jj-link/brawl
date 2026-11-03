#include <types.h>
#pragma force_active on

typedef struct fn_Link {
    void* prev; // +0
    void* next; // +4
} fn_Link;

typedef struct fn_List {
    void* head; // +0
    void* tail; // +4
    u16 length; // +8
    u16 offset; // +A
} fn_List;

extern "C" void fn_8015C024(fn_List* list, void* target, void* node) {
    fn_Link* link;

    if (target == 0) {
        if (list->head == 0) {
            link = (fn_Link*)((u8*)node + list->offset);
            link->next = 0;
            link->prev = 0;
            list->head = node;
            list->tail = node;
            list->length++;
        } else {
            link = (fn_Link*)((u8*)node + list->offset);
            link->prev = list->tail;
            link->next = 0;
            ((fn_Link*)((u8*)list->tail + list->offset))->next = node;
            list->tail = node;
            list->length++;
        }
    } else if (target == list->head) {
        if (list->head == 0) {
            link = (fn_Link*)((u8*)node + list->offset);
            link->next = 0;
            link->prev = 0;
            list->head = node;
            list->tail = node;
            list->length++;
        } else {
            link = (fn_Link*)((u8*)node + list->offset);
            link->prev = 0;
            link->next = list->head;
            ((fn_Link*)((u8*)list->head + list->offset))->prev = node;
            list->head = node;
            list->length++;
        }
    } else {
        void* prev = ((fn_Link*)((u8*)target + list->offset))->prev;
        fn_Link* prevLink;
        link = (fn_Link*)((u8*)node + list->offset);
        prevLink = (fn_Link*)((u8*)prev + list->offset);
        link->prev = prev;
        link->next = target;
        prevLink->next = node;
        ((fn_Link*)((u8*)target + list->offset))->prev = node;
        list->length++;
    }
}
