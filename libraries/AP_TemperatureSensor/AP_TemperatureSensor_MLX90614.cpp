#include <utility>
#include <stdio.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_HAL/I2CDevice.h>
#include <AP_Math/AP_Math.h>
#include "AP_TemperatureSensor_MLX90614.h"


extern const AP_HAL::HAL &hal;


void AP_TemperatureSensor_MLX90614::init(uint8_t bus)
{
    
    _dev = std::move(hal.i2c_mgr->get_device(0, MLX90614_I2CDEFAULTADDR));
    if (!_dev) {
        printf("MLX90614: Device is not ready\n");
        return;
        
    }


    WITH_SEMAPHORE(_dev->get_semaphore());

    _dev->register_periodic_callback(50 * AP_USEC_PER_MSEC,
                                     FUNCTOR_BIND_MEMBER(&AP_TemperatureSensor_MLX90614::_timer, void));
    
    printf("MLX90614: Device is ready\n");
}


void AP_TemperatureSensor_MLX90614::_timer()
{

     _crude_value = read_data(MLX90614_TOBJ1);
    //  printf("val = %d\n", _crude_value);
    
    if(_crude_value > 0)
    {

        WITH_SEMAPHORE(_dev->get_semaphore());
        
        // temp * 0.02 - 273.15 = degrees, temp * 0.02 is temperature in kelvin
        _temperature = _crude_value * 0.02 - 273.15;
        
    }
    

}



uint16_t AP_TemperatureSensor_MLX90614::read_data(uint8_t cmd) {
    uint8_t val[3];
  
    if (!_dev->transfer(&cmd, 1, val, 3))
    {
        return 0;
    }
    hal.scheduler->delay_microseconds(MLX90614_XDLY);

    return UINT16_VALUE(val[1],val[0]);
}




