#pragma force_active on
struct ftSnake {
};

extern "C" ftSnake* fn_122_3EA4(ftSnake* self, short flag) {
    if (self && flag > 0) {
        delete self;
    }
    return self;
}
