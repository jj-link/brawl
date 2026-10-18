#pragma force_active on
extern "C" int sprintf(char*, const char*, ...);

class gfFileIOHandle {
public:
    void readRequest(const char*, void*, int, int);
};

extern const char lbl_2_data_1238[];

extern "C" void fn_2_CA90(void* self) {
    char buffer[0x40];
    int index = *(int*)((char*)self + 0x248);
    void* file = *(void**)((char*)self + 0xD8);
    int slot = *(int*)((char*)self + 0x244);
    void* entry = *(void**)file;
    void* item = (char*)entry + index * 0x60;
    const char* name = *(const char**)((char*)item + 8);

    sprintf(buffer, lbl_2_data_1238, name);

    void* target = *(void**)((char*)self + 0x2A0 + slot * 4);
    ((gfFileIOHandle*)((char*)self + 0x290))->readRequest(buffer, target, 0, 0);
}
