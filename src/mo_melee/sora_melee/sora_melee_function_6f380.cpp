#include <ut/ut_list.h>
#pragma force_active on

extern "C" void fn_27_6F380(utList* list, utListNode* node) {
    if (list->isExistNode(node) == -1) {
        list->addTail(node);
    }
}
