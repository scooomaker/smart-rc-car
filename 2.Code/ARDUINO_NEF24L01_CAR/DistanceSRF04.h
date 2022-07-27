#ifndef DistanceSRF04_h
#define DistanceSRF04_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif

class DistanceSRF04
{
	public:
		DistanceSRF04();
		void begin(int echoPin, int trigPin);
		int getDistanceTime();
		int getDistanceCentimeter();
		int getDistanceInch();

		boolean isCloser(int threshold);
		boolean isFarther(int threshold);

		void setAveraging(int avg);    

	private:
		int _trigPin;
		int _echoPin;
		int _average;
		long _duration;
};
#endif
