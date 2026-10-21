#pragma force_active on
struct ListNode {
    ListNode* next;
    ListNode* prev;
};

extern "C" ListNode* fn_8015C2BC(int* count, ListNode** list) {
    ListNode* first = (*list)->next;
    ListNode* cur = *list;

    while (cur != first) {
        ListNode* next = cur->next;
        ListNode* prev = cur->prev;
        next->prev = prev;
        prev->next = next;
        *count = *count - 1;
        cur->next = 0;
        cur->prev = 0;
        cur = next;
    }
    return first;
}
