struct LuigiInputValueView {
    unsigned char prefix[0xC];
    float value;
};

extern "C" void fn_99_108AC(LuigiInputValueView* self, float value) {
    self->value = value;
}
