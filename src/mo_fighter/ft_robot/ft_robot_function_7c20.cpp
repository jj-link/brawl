#pragma force_active on
extern "C" {
void* getInstance__9itManagerFv();
void fn_27_2A7C60(void* mgr, void* arg);

void fn_120_7C20(void* owner) {
    void* obj = *(void**)((char*)owner + 0x60);
    void* sub = *(void**)((char*)obj + 0x8);
    void* val = *(void**)((char*)sub + 0x28);
    void* mgr = getInstance__9itManagerFv();
    fn_27_2A7C60(mgr, val);
}
}
