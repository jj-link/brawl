#pragma force_active on

class gfTask {
public:
    enum Category {};
};

extern "C" {
extern const char lbl_27_data_17A10[];
extern const char lbl_27_data_17A18[];

gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    gfTask*, const char*, gfTask::Category, int, int, bool);
void fn_8015BF9C(void*, int);
}

extern "C" gfTask* fn_27_C152C(gfTask* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        self, lbl_27_data_17A10, static_cast<gfTask::Category>(0), 0, 0xD, true);

    char* base = reinterpret_cast<char*>(self);
    *reinterpret_cast<const char**>(base + 0x3C) = lbl_27_data_17A18;

    int count = 0;
    int offset = 0;
    do {
        fn_8015BF9C(base + offset + 0x40, 0x20);
        ++count;
        offset += 0xC;
    } while (count < 4);

    count = 0;
    int secondOffset = 0;
    do {
        fn_8015BF9C(base + secondOffset + 0x70, 0x20);
        ++count;
        secondOffset += 0xC;
    } while (count < 4);

    *reinterpret_cast<int*>(base + 0xA0) = 0;
    return self;
}
