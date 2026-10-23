#pragma force_active on
struct Stuct1 {
    char pad[0x110];
    void* resource;
    char pad2[0x23C];
    int flag;
};

extern "C" {

int fn_800390C8(void*);

int fn_800C39D8(const Stuct1* p) {
    int result = 0;
    if (p->flag == 0 && fn_800390C8(p->resource)) {
        result = 1;
    }
    return result;
}

}
