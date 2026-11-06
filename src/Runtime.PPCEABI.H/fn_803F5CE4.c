#pragma force_active on

typedef unsigned long u32;
typedef unsigned char u8;

struct FILE {
    u32 handle;
    u32 mode;
    struct {
        u32 io_state : 3;
        u32 : 29;
    } state;
    u8 pushback[12];
    u32 position;
    u8* buffer;
    u32 buffer_size;
    u8* buffer_ptr;
    u32 buffer_len;
    u32 buffer_alignment;
    u32 saved_buffer_len;
    u32 buffer_pos;
    int (*read_proc)(u32, u32*, int, void*);
    void* extra3c;
    void* write_proc;
    void* extra44;
    void* refcon;
};

extern int lbl_805A12E0;
extern int __flush_buffer(struct FILE*, u32*);
extern int fn_803F5C38(struct FILE*);

int _fseek(struct FILE* arg0, u32 arg1, int arg2) {
    u32 sp8;
    int (*temp_r12)(u32, u32*, int, void*);
    int var_r31;

    var_r31 = arg2;
    sp8 = arg1;
    if (((arg0->mode >> 22) & 7) != 1 || ((u8*)arg0)[0xA] != 0) {
        lbl_805A12E0 = 0x28;
        return -1;
    }
    if (arg0->state.io_state == 1 && __flush_buffer(arg0, 0) != 0) {
        ((u8*)arg0)[0xA] = 1;
        arg0->buffer_len = 0;
        lbl_805A12E0 = 0x28;
        return -1;
    }
    if (var_r31 == 1) {
        var_r31 = 0;
        sp8 += fn_803F5C38(arg0);
    }
    if (var_r31 != 2 && ((arg0->mode >> 27) & 7) != 3 && arg0->state.io_state - 2 <= 1) {
        if (sp8 >= arg0->position || sp8 < arg0->buffer_pos) {
            arg0->state.io_state = 0;
        } else {
            arg0->buffer_ptr = arg0->buffer + (sp8 - arg0->buffer_pos);
            arg0->buffer_len = arg0->position - sp8;
            arg0->state.io_state = 2;
        }
    } else {
        arg0->state.io_state = 0;
    }
    if (arg0->state.io_state == 0) {
        temp_r12 = arg0->read_proc;
        if (temp_r12 != 0 && temp_r12(arg0->handle, &sp8, var_r31, arg0->refcon) != 0) {
            ((u8*)arg0)[0xA] = 1;
            arg0->buffer_len = 0;
            lbl_805A12E0 = 0x28;
            return -1;
        }
        ((u8*)arg0)[0x9] = 0;
        arg0->position = sp8;
        arg0->buffer_len = 0;
    }
    return 0;
}
