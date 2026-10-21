#pragma force_active on
extern "C" void setDrawPrio__5ecMgrFi(void* self, int prio) {
    if (prio <= 0)
        static_cast<unsigned char*>(self)[0x80] = 0;
    else
        static_cast<unsigned char*>(self)[0x80] = 1;
}
