#pragma force_active on
extern "C" int fn_8014F490(void*, int, int);

extern "C" void fn_6_95EC(char* self) {
    int result = fn_8014F490(*reinterpret_cast<void**>(self + 0x730), 4, 0);
    if (result) {
        *reinterpret_cast<int*>(self + 0x784) = 1;
    } else {
        *reinterpret_cast<int*>(self + 0x784) = 2;
    }
}
