# morse for Arduino

## Example
    #include "morse.h"
    
    Morse morse(13, 100);
    
    void setup()
    {
    }
    
    void loop()
    {
        morse.sends("HELLO ARDUINO");
        delay(3000);
    }
