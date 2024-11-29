#define rotary A0
#define LED D5
#define fullAngle 300 //300 degrees
#define ADC_REF 3.3
#define GROVE_VCC 3.3

class rotaryAngleSensor{
  public:
    rotaryAngleSensor();   
    ~rotaryAngleSensor();  
    void run(void);
};