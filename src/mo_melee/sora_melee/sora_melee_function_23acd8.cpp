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
    unsigned char padB8[0x14];
    void* archiveCC;
};

extern "C" {
extern unsigned char lbl_27_data_4D0E0[];
void __dt__9gfArchiveFv(void*, int);
void free__13gfHeapManagerFPv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void fn_27_23F098(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_23ACD8(Object* self, int flag) {
    if (self) {
        void* archive = self->archiveCC;
        self->vtable = lbl_27_data_4D0E0;
        if (archive) __dt__9gfArchiveFv(archive, 1);
        self->archiveCC = 0;
        if (self->archive9C) __dt__9gfArchiveFv(self->archive9C, 1);
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

        __dt__14gfFileIOHandleFv((char*)self + 0xDC, -1);
        fn_27_23F098(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
