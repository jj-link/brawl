#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

#define V1(n) virtual void unused##n();
#define V4(n) V1(n##a) V1(n##b) V1(n##c) V1(n##d)
#define V16(n) V4(n##a) V4(n##b) V4(n##c) V4(n##d)
#define V64(n) V16(n##a) V16(n##b) V16(n##c) V16(n##d)

struct HeapSource {
    V4(h)
    V1(h4)
    virtual u32 getHeapType();
};

struct ResourceInfo {
    u8 padding[0xE8];
    u32 value;
};

struct ResourceSource {
    u8 padding[8];
    V4(s0)
    V4(s1)
    V4(s2)
    V1(s12)
    virtual ResourceInfo* getInfo();
};

struct ResourceProvider {
    u8 padding[8];
    V4(p0)
    V1(p4)
    V1(p5)
    V1(p6)
    virtual void* getResource(u32, u32);
};

struct Modules {
    ResourceProvider* provider;
    ResourceSource* source;
    u8 padding[0xB8];
    HeapSource* heap;
};

struct Accessor {
    u8 padding[0xD8];
    Modules* modules;
};

struct CountSource {
    V1(c0)
    V1(c1)
    V1(c2)
    virtual u32 getCount();
};

struct ObjectBase {
    V64(o0)
    V16(o1)
    V16(o2)
    V16(o3)
    V4(o4)
    V4(o5)
    V4(o6)
    virtual void* getResource(u32, u32);
};

struct Object : ObjectBase {
    u8 padding04[0x88];
    CountSource* countSource;
    u8 padding90[4];
    void* allocation;
    u8 padding98[0xCC];
    u8 flagPadding : 6;
    u8 flag : 1;
    u8 lowFlag : 1;
    u8 padding165[3];
    Accessor* accessor;
    u8 state;
};

struct ResFile {
    void* data;
};

extern "C" {
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(u32);
void* fn_8019A700(void*, const u32*, const u32*, u32);
void fn_8018E808(ResFile*);
void Init__Q34nw4r3g3d7ResFileFPv(ResFile*);
void fn_8018E5D4(ResFile*, const ResFile*);
u32 fn_8018E4A4(ResFile*);

void fn_27_1C638(Object* self, u32 mode)
{
    ResFile other;
    ResFile otherCopy;
    ResFile copy;
    u32 argument;
    ResFile file;
    u32 zero;

    if (mode == 1) {
        u32 value;
        void* allocator =
            getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(
                self->accessor->modules->heap->getHeapType());

        value = self->accessor->modules->source->getInfo()->value;
        u32 count = self->countSource->getCount() + 2;

        zero = 0;
        argument = value;
        self->allocation =
            fn_8019A700(allocator, &zero, &argument, count);
    }

    if (self->state == 1) {
        file.data = self->getResource(0, 0);
        if (file.data != 0) {
            fn_8018E808(&file);
            Init__Q34nw4r3g3d7ResFileFPv(&file);
            copy = file;
            fn_8018E5D4(&file, &copy);

            if (!self->flag) {
                if (fn_8018E4A4(&file) == 1) {
                    void* data =
                        self->accessor->modules->provider->getResource(
                            0, 0xFFFF);
                    if (data != 0) {
                        other.data = data;
                        Init__Q34nw4r3g3d7ResFileFPv(&other);
                        otherCopy = other;
                        fn_8018E5D4(&file, &otherCopy);
                    }
                }
            }
        }
    }
}
}
