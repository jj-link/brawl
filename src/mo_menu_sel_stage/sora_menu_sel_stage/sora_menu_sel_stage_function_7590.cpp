#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_11_7600(void* p);
extern void* g_GameGlobal;
}

extern "C" void* fn_11_7590(void* arg) {
    unsigned char* obj = (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x3a0, 0x2a);
    if (obj != 0) {
        obj = (unsigned char*)fn_11_7600(obj);
    }
    unsigned char* gg = (unsigned char*)(*(void**)g_GameGlobal);
    if (gg[0x10] != 0) {
        obj[0x48] |= 0x80;
    }
    *(void**)(obj + 0x39c) = arg;
    *(unsigned int*)(obj + 0x40) = 0;
    return obj;
}
