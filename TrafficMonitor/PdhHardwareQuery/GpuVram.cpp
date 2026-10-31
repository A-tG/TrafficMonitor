#include "stdafx.h"
#include "GpuVram.h"

CPdhGPUVram::CPdhGPUVram()
    : CPdhQuery(_T("\\GPU Adapter Memory(*)\\Dedicated Usage"))
{
}

CPdhGPUVram::~CPdhGPUVram()
{
}

bool CPdhGPUVram::GetUsedVram(unsigned long long& bytes)
{
    if (!isInitialized) return false;
    
    std::vector<CounterValueItem> valueItems;
    if (!QueryValues(valueItems) || valueItems.empty()) return false;

    int max = 0;
    for (const auto& item : valueItems)
    {
        max = item.value > max ? item.value : max;
    }

    bytes = max;
    return true;
}
