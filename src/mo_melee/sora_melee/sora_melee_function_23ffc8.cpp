#pragma force_active on

struct Object {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x5C];
    void* archive9C;
    void* archiveA0;
    void* archiveA4;
    void* archiveA8;
    void* bufferAC;
    void* bufferB0;
    void* bufferB4;
};

extern "C" {
extern unsigned char lbl_27_data_4D690[];
void __dt__9gfArchiveFv(void*, int);
void free__13gfHeapManagerFPv(void*);
void fn_27_23F098(void*, int);
void __dl__FPv(void*);
}

extern "C" Object* fn_27_23FFC8(Object* self, int flag) {
    if (self) {
        void* archive = self->archive9C;
        self->vtable = lbl_27_data_4D690;

        if (archive) __dt__9gfArchiveFv(archive, 1);
        if (self->archiveA0) __dt__9gfArchiveFv(self->archiveA0, 1);
        if (self->archiveA4) __dt__9gfArchiveFv(self->archiveA4, 1);
        if (self->archiveA8) __dt__9gfArchiveFv(self->archiveA8, 1);
        if (self->bufferAC) free__13gfHeapManagerFPv(self->bufferAC);
        if (self->bufferB0) free__13gfHeapManagerFPv(self->bufferB0);
        if (self->bufferB4) free__13gfHeapManagerFPv(self->bufferB4);

        self->archive9C = 0;
        self->archiveA0 = 0;
        self->archiveA4 = 0;
        self->archiveA8 = 0;
        self->bufferAC = 0;
        self->bufferB0 = 0;
        self->bufferB4 = 0;

        fn_27_23F098(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
