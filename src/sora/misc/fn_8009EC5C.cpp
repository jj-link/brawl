#include <types.h>
#pragma force_active on

struct LinkNode {
    LinkNode* next;
    u32 pad4;
    u32 flags;
};

extern "C" {
extern char lbl_8049DEDC[];
extern const float lbl_805A1E30;

void fn_8009EFCC(void* self);
void fn_8009F108(void* self, float value);

void fn_8009EC5C(float value) {
    if (value > lbl_805A1E30) {
        char* head = lbl_8049DEDC;
        LinkNode* node = *(LinkNode**)(head + 4);
        LinkNode* end = (LinkNode*)(head + 4);

        while (node != end) {
            fn_8009EFCC(node);
            if ((node->flags >> 16) & 1) {
                fn_8009F108(node, value);
            }
            node = node->next;
        }
    }
}
}
