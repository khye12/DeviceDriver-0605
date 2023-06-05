#include "DeviceDriver.h"

#include <exception>

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    // TODO: implement this method properly
    int firstReadTryValue= (int)(m_hardware->read(address));
    for(int tryCount = 2; tryCount <= 5; tryCount++)
    {
        int nextReadTryValue = (int)(m_hardware->read(address));
        if (firstReadTryValue == nextReadTryValue) continue;
        throw std::exception("Exception!!");
    }
    return firstReadTryValue;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}