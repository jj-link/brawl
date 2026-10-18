#pragma force_active on
struct SnakeSupport {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char state;
};

extern "C" {
void fn_122_AADC(void*, int);
extern unsigned char lbl_122_data_E1F4[];
}

extern "C" SnakeSupport* fn_122_177A8(SnakeSupport* self, int val) {
    fn_122_AADC(self, val);
    self->enabled = val == 0;
    self->state = 0;
    self->vtable = lbl_122_data_E1F4;
    return self;
}
