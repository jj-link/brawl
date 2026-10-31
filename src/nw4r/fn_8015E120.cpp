#pragma force_active on

extern "C" int fn_8015E410(void*, void*, unsigned short);

extern "C" int fn_8015E120(void* arg0, unsigned short arg1) {
    void* node;
    unsigned int val;

    if (arg1 == *(unsigned short*)((char*)arg0 + 0x18)) {
        val = *(unsigned short*)((char*)arg0 + 0x1A);
        goto finish;
    }

    *(unsigned short*)((char*)arg0 + 0x18) = arg1;
    node = *(void**)((char*)arg0 + 0x14);
    node = *(void**)((char*)node + 0x10);
    goto check_node;

search_node:
    if (*(unsigned short*)node <= arg1 &&
        arg1 <= *(unsigned short*)((char*)node + 2)) {
        val = (unsigned short)fn_8015E410(arg0, node, arg1);
        *(unsigned short*)((char*)arg0 + 0x1A) = val;
        goto finish;
    }

    node = *(void**)((char*)node + 8);

check_node:
    if (node != 0) {
        goto search_node;
    }

    val = 0xFFFF;
    *(unsigned short*)((char*)arg0 + 0x1A) = val;
    val &= 0xFFFF;

finish:
    if (val != 0xFFFF) {
        *(unsigned short*)((char*)(*(void**)((char*)arg0 + 0x14)) + 2) = val;
        return 1;
    }
    return 0;
}
