#include <types.h>
#pragma force_active on

extern "C" {
void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

struct Obj {
    char _00[0x24];
    unsigned char m_flag; // 0x24
    char _25[3];
    unsigned int m_count; // 0x28
};

void fn_801BB2D8(char* self, char* list, unsigned int size) {
    Obj* o = (Obj*)self;
    if (o->m_flag == 0) {
        char* node = list;
        unsigned int i = 0;
        o->m_count = size / 72;
        if (o->m_count != 0) {
            while (i < o->m_count) {
                void* it = self + 0x10;
                Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(self + 0xC, &it, node + 0x40);
                node += 0x48;
                i++;
            }
        }
        o->m_flag = 1;
    }
}
}
