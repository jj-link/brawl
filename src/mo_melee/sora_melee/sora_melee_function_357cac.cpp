#pragma force_active on
extern "C" void* getInstance__9itManagerFv();
extern "C" void fn_27_2A7C60(void* mgr, void* arg);
extern "C" void fn_27_1FF0C(void* arg);
extern "C" void fn_27_1FFCC(void* arg);

struct Object {
    void* unused;
    void* unk;
    void* data;
};

extern "C" void fn_27_357CAC(void* unused, Object* object, void* arg) {
    fn_27_2A7C60(getInstance__9itManagerFv(), *(void**)((char*)object->data + 0x28));
    fn_27_1FF0C(arg);
    fn_27_1FFCC(arg);
}
