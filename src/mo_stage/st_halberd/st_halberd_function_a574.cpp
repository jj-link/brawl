#pragma force_active on
extern "C" void fn_57_A574(void* object, unsigned int first, unsigned int second)
{
    unsigned int* words = static_cast<unsigned int*>(object);
    words[363] = first;
    words[365] = second;
}
