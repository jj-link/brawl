#pragma force_active on
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void invoke(int);
};

extern "C" void* getNode__6utListFUl(void*, unsigned long);
extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6A660(char* self, int id) {
    char* node = (char*)getNode__6utListFUl(self + 0x14, 0);
    while (node != 0) {
        char* data = *(char**)(node + 0xC);
        char* next = *(char**)node;
        int field = *(int*)(data + 0x30);
        if (id == ((field >> 1) & 0x7F)) {
            fn_27_6F30C(node)->invoke(id);
        }
        node = next;
    }
}
