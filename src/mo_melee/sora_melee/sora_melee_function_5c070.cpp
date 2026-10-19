#pragma force_active on
extern "C" void fn_27_5C6B4();

extern "C" void fn_27_5C070(void* self) {
    fn_27_5C6B4();
    int* fields = reinterpret_cast<int*>(self);
    fields[9] = 1;
    fields[12] = 0;
    fields[10] = 0;
    fields[13] = 1;
}
