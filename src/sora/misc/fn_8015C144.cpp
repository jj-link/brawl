#pragma force_active on
struct Link {
    void* prev;
    void* next;
};
struct List {
    void* head;
    void* tail;
    unsigned short count;
    unsigned short offset;
};
extern "C" void fn_8015C144(List* list, void* object) {
    unsigned short offset = list->offset;
    Link* link = (Link*)((char*)object + offset);
    if (link->prev == 0) {
        list->head = link->next;
    } else {
        ((Link*)((char*)link->prev + offset))->next = link->next;
    }
    if (link->next == 0) {
        list->tail = link->prev;
    } else {
        ((Link*)((char*)link->next + list->offset))->prev = link->prev;
    }
    link->prev = 0;
    link->next = 0;
    list->count--;
}
