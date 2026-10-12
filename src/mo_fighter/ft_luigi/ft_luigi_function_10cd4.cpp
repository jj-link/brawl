extern "C" bool fn_27_1DA5FC(void*, unsigned int, int);

extern "C" bool fn_99_10CD4(void* object, unsigned int index, int taskId) {
    return fn_27_1DA5FC(static_cast<unsigned char*>(object) - 0x88, index, taskId);
}
