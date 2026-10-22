#pragma force_active on
typedef unsigned char u8;

extern "C" {

void* fn_801D039C(void* self);
void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

void fn_801D2BF0(u8* arg0, void* arg1, unsigned int arg2) {
    unsigned int count;
    void* node;
    unsigned int i;
    void* it;

    if (arg0[0] == 0) {
        node = arg1;
        i = 0;
        count = arg2 / 300;
        if (count != 0) {
            while (i < count) {
                void* p = node;
                if (node != 0) {
                    p = fn_801D039C(node);
                }
                it = arg0 + 0x14;
                Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode((char*)(arg0 + 0x10), &it, (char*)p + 0x124);
                node = (char*)node + 0x12C;
                i++;
            }
        }
        arg0[0] = 1;
    }
}

}
