#pragma force_active on
extern void fn_80378018(void*);

struct fn_80373924_s {
    char _000[0x14];
    int _14;
    char _18[4];
    int _1C;
    char _20[4];
    int (*_24)(void*);
};

int fn_80373924(void* arg0) {
    struct fn_80373924_s* self = (struct fn_80373924_s*)arg0;
    if (self == 0) {
        return 1;
    }
    if (self->_24 == 0) {
        return 1;
    }
    self->_1C++;
    self->_24(self);
    self->_1C--;
    if (self->_14 && self->_1C == 0) {
        fn_80378018(self);
        return 0;
    }
    return 1;
}
