#pragma force_active on

extern "C" void free__13gfHeapManagerFPv(void*);

extern "C" int fn_27_2D66E0(void* pool, void* key) {
    if (key) {
        unsigned int i = 0;
        char* entry = (char*)pool;

        while (i < 65) {
            void* storedKey = *(void**)(entry + 0x0C);
            if (storedKey && *(int*)storedKey == *(int*)key)
                break;

            ++i;
            entry += 0x14;
        }

        if (i < 65) {
            if (*(unsigned short*)(entry + 0x0A) == 0) {
                void* prev = *(void**)entry;
                if (prev == 0) {
                    *(void**)((char*)pool + 0x51C) = *(void**)(entry + 4);
                } else {
                    *(void**)((char*)prev + 4) = *(void**)(entry + 4);
                }

                void* next = *(void**)(entry + 4);
                if (next == 0) {
                    *(void**)((char*)pool + 0x520) = *(void**)entry;
                } else {
                    *(void**)next = *(void**)entry;
                }
            }

            *(unsigned short*)(entry + 0x0A) =
                *(unsigned short*)(entry + 0x0A) + 1;
            return (int)i;
        }

        void* reused = *(void**)((char*)pool + 0x51C);
        if (reused) {
            void* next = *(void**)((char*)reused + 4);
            *(void**)((char*)pool + 0x51C) = next;

            if (next == 0) {
                *(void**)((char*)pool + 0x520) = 0;
            } else {
                *(void**)next = 0;
            }

            void* cached = *(void**)((char*)pool + 0x518);
            if (cached != 0) {
                if (cached == reused)
                    *(void**)((char*)pool + 0x518) = 0;
            }

            void* data = *(void**)((char*)reused + 0x10);
            if (data) {
                free__13gfHeapManagerFPv(data);
                *(void**)((char*)reused + 0x10) = 0;
            }

            *(unsigned short*)((char*)reused + 0x0A) = 1;
            *(void**)((char*)reused + 0x0C) = key;
            return *(unsigned short*)((char*)reused + 8);
        }
    }

    return -1;
}
