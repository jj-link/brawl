struct LuigiIdFieldAccess {
    unsigned char reserved[0xC];
    unsigned int id;
};

extern "C" void fn_99_10998(LuigiIdFieldAccess* self, unsigned int id) {
    self->id = id;
}
