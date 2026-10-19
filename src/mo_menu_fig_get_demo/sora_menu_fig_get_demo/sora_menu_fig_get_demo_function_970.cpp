#pragma force_active on
extern "C" {
void* getInstance__9itManagerFv();
void loadMenuSound__6muMenuFv(void);
}

extern "C" void fn_26_970(char* self) {
    void* inst = getInstance__9itManagerFv();
    void* p = *(void**)((char*)inst + 0x14b8);
    if (p != 0) {
        *(unsigned int*)(self + 0x1f0) = *(unsigned int*)((char*)p + 4);
    }
    loadMenuSound__6muMenuFv();
}
