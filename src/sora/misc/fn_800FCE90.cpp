#pragma force_active on
extern "C" void fn_800BF830(void* p);

class gfTask {
public:
    void exit();
};

extern "C" void fn_800FCE90(char* self) {
    fn_800BF830(*(void**)(self + 0x44));
    ((gfTask*)*(void**)(self + 0x44))->exit();
    *(void**)(self + 0x44) = 0;
}
