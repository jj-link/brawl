#include <types.h>
#pragma force_active on

extern "C" void fn_801BDB00(void*, s32);

extern "C" {

struct Node {
    char pad[8];
    void* next;
};

void fn_801BD994(struct Node* self) {
    void* node = self->next;
    void* end = &self->next;
    while (node != end) {
        void* old = node;
        node = *(void**)node;
        fn_801BDB00((char*)old - 0xE4, 1);
    }
}

}
