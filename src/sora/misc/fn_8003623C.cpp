#pragma force_active on
extern "C" void* fn_8003623C(unsigned int* obj, unsigned int size) {
    unsigned char* cur = (unsigned char*)obj[6];
    unsigned int next = (unsigned int)cur + ((size + 7) & ~7u);
    obj[6] = next;
    if (next > obj[7]) {
        return 0;
    }
    return cur;
}
