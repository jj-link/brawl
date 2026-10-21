#pragma force_active on
class SoHeapAllocator {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void free(void* p, unsigned short type, int tag);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" {
void* fn_80099EB8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        lbl_805A0EB8->free(arg0, *(unsigned short*)((char*)arg0 + 4), 0x25);
    }
    return arg0;
}
}
