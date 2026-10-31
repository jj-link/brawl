#include <types.h>
#include <gf/gf_archive.h>

#pragma force_active on

struct AiParameters {
    char pad[0x90];
};

struct AiInput {
    char pad0[0x30];
    s32 type;
    char pad34[4];
    void* buffer;
    u16 flags;
    char pad3E[6];
    void* script;
    char pad48[0x48];
    AiParameters parameters;
};

struct AiSelfC728 {
    char pad[0x64];
};

extern "C" {
void __ct__9gfArchiveFv(void*);
void __dt__9gfArchiveFv(void*, int);
void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void*, void*, int, int);
void free__13gfHeapManagerFPv(void*);
void* fn_80015DB4(void*, int, int, int, u16);
void fn_27_21CE78(const unsigned char*);
void fn_27_21CDD8(int*, int, int, const char*);
void fn_27_20C728(AiSelfC728*, u32);

void fn_27_1F3664(AiInput* self, void* data, int size, int flag3, int flag4) {
    if (flag4 != 0) {
        char archive1[sizeof(gfArchive)];
        __ct__9gfArchiveFv(archive1);
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(archive1, data, size, 12);
        fn_27_21CE78((const unsigned char*)fn_80015DB4(archive1, 1, 1, 0, 0xFFFE));
        __dt__9gfArchiveFv(archive1, -1);
    }

    fn_27_21CDD8((int*)&self->parameters, 0, -1, 0);

    if (self->buffer && (self->flags & 0x40)) {
        if (self->buffer) {
            free__13gfHeapManagerFPv(self->buffer);
            self->buffer = 0;
        }
        self->flags &= ~0x40;
    }

    if (self->type <= -1 || (u32)self->type >= 0x36U) {
        return;
    }

    self->buffer = data;
    if (flag3) {
        self->flags |= 0x40;
    } else {
        self->flags &= ~0x40;
    }

    if (self->buffer) {
        char archive2[sizeof(gfArchive)];
        __ct__9gfArchiveFv(archive2);
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(archive2, data, size, 12);

        void* h1 = fn_80015DB4(archive2, 1, 1, 0, 0xFFFE);
        if (h1) {
            void* h3 = fn_80015DB4(archive2, 3, 1, 0, 0xFFFE);
            fn_27_21CDD8((int*)&self->parameters, (int)h1, self->type, (const char*)h3);

            void* h2 = fn_80015DB4(archive2, 2, 1, 0, 0xFFFE);
            fn_27_20C728((AiSelfC728*)self->script, (u32)h2);
        }

        __dt__9gfArchiveFv(archive2, -1);
    }
}
}
