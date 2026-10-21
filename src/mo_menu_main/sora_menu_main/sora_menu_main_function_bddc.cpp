#pragma force_active on
extern "C" int sprintf(char*, const char*, ...);

class gfFileIOHandle {
public:
    void readRequest(const char*, void*, int, int);
};

extern const char lbl_2_data_1238[];

extern "C" void fn_2_BDDC(char* self) {
    char buffer[0x40];
    int i = 0;
    char* base = self;
    int n;
    self += 0x4C;
    for (n = 4; n > 0; n--) {
        if (((*(unsigned char*)self) >> 7) & 1) {
            int idx;
            char* entry = *(char**)(base + 0xD8);
            char* e = base + i * 0x14;
            char* table = *(char**)entry;
            if (((*(unsigned char*)(e + 0x4C)) >> 7) & 1) {
                idx = *(int*)(e + 0x50);
            } else {
                idx = -1;
            }
            char* item = table + idx * 0x60;
            sprintf(buffer, lbl_2_data_1238, *(const char**)(item + 8));
            ((gfFileIOHandle*)(base + 0x290))->readRequest(buffer, *(void**)(base + 0x2A0 + i * 4), 0, 0);
            *(int*)(base + 0x294) = i;
            return;
        }
        self += 0x14;
        i++;
    }
}
