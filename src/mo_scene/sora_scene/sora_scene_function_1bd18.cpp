#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__9gfArchiveFv(void*);
extern "C" void getResourcePackData__13muAdvSealTaskFPPCcPUl(const char**, u32*);
extern "C" void loadResourceMemSizeOrder__16gfResourceLoaderFQ25Heaps8HeapTypePCcP9gfArchiveUl(
    void*, int, const char*, void*, u32);

struct Loader {
    u32 field0, field4, field8, fieldC;
    u32 field10, field14, field18;
    u8 field1C;
};

extern "C" void fn_1_1BD18(void* self) {
    void* archive = __nw__FUlQ25Heaps8HeapType(0x80, 0x2B);
    if (archive) {
        archive = __ct__9gfArchiveFv(archive);
    }
    *(void**)((char*)self + 0x10) = archive;

    Loader* loader = (Loader*)__nw__FUlQ25Heaps8HeapType(0x20, 0x2B);
    if (loader) {
        loader->field0 = 0;
        loader->field4 = 0;
        loader->field8 = 0;
        loader->fieldC = 0;
        loader->field10 = 0;
        loader->field1C = (loader->field1C & 0xFFFFFF7F) | 0x40;
        loader->field18 = 0;
        loader->field14 = 0xFF;
    }
    *(Loader**)((char*)self + 0x14) = loader;

    const char* path;
    u32 size;
    getResourcePackData__13muAdvSealTaskFPPCcPUl(&path, &size);
    loadResourceMemSizeOrder__16gfResourceLoaderFQ25Heaps8HeapTypePCcP9gfArchiveUl(
        *(Loader**)((char*)self + 0x14), 0x2B, path,
        *(void**)((char*)self + 0x10), size);
}
