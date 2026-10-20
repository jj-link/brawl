#pragma force_active on
extern "C" void fn_27_160770(int, const void*, void*, void*);

extern "C" void fn_27_385AAC(void* object, int kind, const void* vector, void* accesser)
{
    fn_27_160770(kind, vector, static_cast<unsigned char*>(object) + 4, accesser);
}
