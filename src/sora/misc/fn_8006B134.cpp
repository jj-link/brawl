#pragma force_active on
typedef unsigned long u32;

struct Message {
    void getPrintIndexData(void* arg0, unsigned long arg1, char** arg2, unsigned long* arg3);
};

void Message::getPrintIndexData(void* arg0, unsigned long arg1, char** arg2, unsigned long* arg3) {
    char* base = (char*)this;
    u32 idx = (u32)arg0;
    u32 off0 = idx * 4;
    u32 off1 = (idx + 1) * 4;
    u32 start = *(u32*)(base + off0);
    u32 end = *(u32*)(base + off1);
    *(u32*)arg2 = end - start;
    *(char**)arg1 = base + start;
}
