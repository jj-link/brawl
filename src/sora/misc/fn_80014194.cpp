#pragma force_active on
extern "C" void free__13gfHeapManagerFPv(void*);

struct Entry {
    unsigned char pad[0xd];
    unsigned char m_flag : 1;
    unsigned char m_rest : 7;
    unsigned char pad2[2];
    void* m_ptr;
};

extern "C" void fn_80014194(Entry* arg0, int arg1) {
    Entry* p = (Entry*)((char*)arg0 + arg1 * 0x10);
    if (p->m_flag) {
        free__13gfHeapManagerFPv(p->m_ptr);
        p->m_ptr = 0;
        p->m_flag = 0;
    }
}
