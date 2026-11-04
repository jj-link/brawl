#pragma force_active on
class Class_804647D8 {
public:
    virtual void fn_8015E628();
    virtual void fn_8015E044();
    virtual void fn_8015E050();
    virtual void fn_8015E05C();
    virtual void fn_8015E068();
    virtual void fn_8015E07C();
    virtual void fn_8015E090();
    virtual void fn_8015E0A0();
    virtual void fn_8015E0B0();
    virtual void fn_8015E0C0();
    virtual void fn_8015E0C8();
    virtual void fn_8015E0D8();
    virtual void fn_8015E0E8();
    virtual void fn_8015E100();
    virtual void fn_8015E120();
    virtual void fn_8015E1D8();
    virtual void fn_8015E1E4();
    virtual void fn_8015E230();
    virtual void fn_8015E340();
    virtual int fn_8015E404();
    char pad[12];
    int active;
};
struct File {
    unsigned int magic;
    unsigned short byteOrder;
    unsigned short version;
    unsigned int size;
    unsigned short headerSize;
    unsigned short count;
};
struct Block {
    unsigned int magic;
    unsigned int size;
};
extern "C" int fn_8015C3A4(File*, unsigned int, int, int);
extern "C" void* fn_8015E7C8(File*);
extern "C" void fn_8015E020(Class_804647D8*, File*, void*);
extern "C" void fn_8015D8DC(Class_804647D8*, int);
extern "C" int fn_8015E680(Class_804647D8* self, File* file) {
    void* info = 0;
    if (self->active) return 0;
    if (file->magic == 0x52464E55) {
        Block* block = (Block*)((char*)file + file->headerSize);
        for (int i = 0; i < file->count; i++) {
            if (block->magic == 0x46494E46) {
                info = (char*)block + 8;
                break;
            }
            block = (Block*)((char*)block + block->size);
        }
    } else {
        if (file->version == 0x104) {
            if (!fn_8015C3A4(file, 0x52464E54, 0x104, 2)) return 0;
        } else {
            if (!fn_8015C3A4(file, 0x52464E54, 0x102, 2)) return 0;
        }
        info = fn_8015E7C8(file);
    }
    if (!info) return 0;
    fn_8015E020(self, file, info);
    fn_8015D8DC(self, self->fn_8015E404());
    return 1;
}