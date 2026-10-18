#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class MenuObject {
public:
    u8 padding[0x5C];
    virtual void destroy(int);
};

class Loader;

struct ResultTask {
    u8 padding000[0x3C];
    void* vtable;
    u8 padding040[0xC8];
    void* field108;
    void* field10C;
    void* field110;
    u8 padding114[8];
    void* field11C;
    u8 padding120[0x18];
    MenuObject* objects[32];
    void* field1B8;
    u8 padding1BC[0x3E0];
    void* field59C;
    u32 sound;
    u8 padding5A4[4];
    void* archive;
    Loader* loader;
};

extern "C" {
extern u8 lbl_34_data_70[];
extern void* g_sndSystem;
extern void* g_gfSceneRoot;

void fn_80075F1C(void*, u32, int);
void fn_800AD87C(void*, int);
void fn_8000D7B8(void*);
void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_1_406C(void*);
void __dl__FPv(void*);
void __dt__6gfTaskFv(void*, int);
}

class gfFileIOHandle {
public:
    ~gfFileIOHandle();
};

class Loader {
public:
    gfFileIOHandle handle;

    ~Loader() {
        fn_1_406C(this);
    }
};

extern "C" ResultTask* fn_34_2C0(ResultTask* self, int deleting) {
    if (self) {
        self->vtable = lbl_34_data_70;

        if (self->sound != 0xFFFFFFFF) {
            fn_80075F1C(g_sndSystem, self->sound, 0);
            self->sound = 0xFFFFFFFF;
        }

        fn_800AD87C(self->field11C, 1);

        for (int i = 0; i < 32; ++i) {
            MenuObject* object = self->objects[i];
            if (object) {
                object->destroy(1);
            }
        }

        fn_8000D7B8(g_gfSceneRoot);
        fn_800B8EDC(self->field1B8,
                   *reinterpret_cast<void**>(
                       static_cast<u8*>(self->field59C) + 0x268));

        if (self->field1B8) {
            fn_800B8A0C(self->field1B8, 1);
            self->field1B8 = 0;
        }

        self->field108 = 0;
        self->field10C = 0;
        self->field110 = 0;

        exit__6gfTaskFv(self->field59C);

        if (self->archive) {
            __dt__9gfArchiveFv(self->archive, 1);
            self->archive = 0;
        }

        if (self->loader) {
            delete self->loader;
            self->loader = 0;
        }

        __dt__6gfTaskFv(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
