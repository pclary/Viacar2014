#ifndef VNH5019_H
#define VNH5019_H


class Motor
{
public:
    Motor(int fwdPin, int backPin, int speedPin);
    void write(float value);
    Motor& operator=(float value);
	void brake(float value = 1.f);
    
private:
    int fwdPin;
	int backPin;
	int speedPin;
};

#endif // VNH5019_H