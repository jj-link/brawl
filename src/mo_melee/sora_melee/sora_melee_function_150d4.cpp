#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct ResFile {
    u32 unk0;
};

extern "C" {
void fn_8018E808(ResFile*);
void Init__Q34nw4r3g3d7ResFileFPv(ResFile*);
void fn_8018E5D4(ResFile*, const ResFile*);
u32 fn_8018E4A4(ResFile*);
}

struct Provider {
    u8 padding[8];
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void* getResource(u32, u32);
};

struct Holder {
    u8 padding[0xD8];
    Provider** pp;
};

struct Owner {
    u8 padding[0x164];
    u8 flags;
    u8 padding165[3];
    Holder* holder;
};

extern "C" void fn_27_150D4(Owner* self, ResFile* file) {
    ResFile other;
    ResFile otherCopy;
    ResFile copy;

    if (file->unk0 != 0) {
        fn_8018E808(file);
        Init__Q34nw4r3g3d7ResFileFPv(file);
        copy.unk0 = file->unk0;
        fn_8018E5D4(file, &copy);

        if (!((self->flags >> 1) & 1) && fn_8018E4A4(file) == 1) {
            void* data = (*self->holder->pp)->getResource(0, 0xFFFF);
            if (data != 0) {
                other.unk0 = (u32)data;
                Init__Q34nw4r3g3d7ResFileFPv(&other);
                otherCopy.unk0 = other.unk0;
                fn_8018E5D4(file, &otherCopy);
            }
        }
    }
}
