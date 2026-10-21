#pragma force_active on
extern "C" unsigned char fn_80112E90(void* arg0) {
    unsigned short* p = *(unsigned short**)((char*)arg0 + 0x30);
    return (unsigned char)((unsigned)*p & 0xFF);
}
