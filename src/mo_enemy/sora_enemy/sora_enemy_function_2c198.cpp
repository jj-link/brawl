#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" u32 fn_41_2C254(void*);

extern "C" void* fn_41_2C198(void* arg0, u32 arg1, u32 arg2, u32 arg3) {
    if (*(s32*)((char*)arg0 + 0x1C) == 0) {
        return 0;
    }
    
    void* node = getNode__6utListFUl((char*)arg0 + 0x14, 0);
    u32 count = 0;
    
    do {
        if (fn_41_2C254(node) == arg1) {
            if (arg2 == 0xFFFF) {
                if (count == arg3) {
                    return node;
                }
                count++;
            }
            if ((s32)arg2 == *(s32*)((char*)node + 0x21CC)) {
                if (count == arg3) {
                    return node;
                }
                count++;
            }
        }
        node = *(void**)node;
    } while (node != 0);
    
    return 0;
}
