#include <gf/gf_file_io_handle.h>
#include <types.h>
#pragma force_active on
extern "C" {
extern const char lbl_13_data_44[];
void fn_13_134C(void*, char*, char*, char*, int, int);
}
struct Entry { int kind; int mode; };
struct Obj {
    char pad[0xb0];
    int type;
    int count1;
    Entry entries1[3];
    int count2;
    Entry entries2[2];
    int unused;
    gfFileIOHandle handles[10];
};
extern "C" void fn_13_950(Obj* self) {
    char a[64], b[32], c[32];
    self->handles[1].readRequest(lbl_13_data_44, (HeapType)0x2b, 0, 0);
    if (self->type == 1) {
        int mode;
        switch (self->type) {
        case 0: mode = self->entries1[0].mode; break;
        case 1: mode = 0; break;
        default: mode = 4; break;
        }
        fn_13_134C(self, a, b, c, self->entries1[0].kind, mode);
        self->handles[2].readRequest(a, (HeapType)0x2a, 0, 0);
    } else {
        int count = self->type >= 2 ? -1 : self->count1;
        for (int i = 0; i < count; i++) {
            int mode;
            if (i < 0 && i >= (self->type >= 2 ? -1 : self->count1)) {
                mode = 4;
            } else {
                switch (self->type) {
                case 0: mode = self->entries1[i].mode; break;
                case 1: mode = 0; break;
                default: mode = 4; break;
                }
            }
            fn_13_134C(self, a, b, c, self->entries1[i].kind, mode);
            self->handles[i + 2].readRequest(a, (HeapType)0x2a, 0, 0);
        }
    }
    int count = self->type >= 2 ? -1 : self->count2;
    for (int i = 0; i < count; i++) {
        int mode;
        if (i < 0 && i >= (self->type >= 2 ? -1 : self->count2)) {
            mode = 4;
        } else {
            switch (self->type) {
            case 0:
            case 1: mode = self->entries2[i].mode; break;
            default: mode = 4; break;
            }
        }
        fn_13_134C(self, a, b, c, self->entries2[i].kind, mode);
        self->handles[i + 6].readRequest(a, (HeapType)0x2a, 0, 0);
    }
}
