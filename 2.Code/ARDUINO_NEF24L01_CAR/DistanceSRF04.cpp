#include <Arduino.h>
#include "DistanceSRF04.h"


DistanceSRF04::DistanceSRF04()
{
}


void DistanceSRF04::begin(int echoPin, int trigPin)
{
	_trigPin=trigPin;
	_echoPin=echoPin;
	pinMode(_trigPin, OUTPUT);
	pinMode(_echoPin, INPUT);
	setAveraging(10);
}

void DistanceSRF04::setAveraging(int avg)
{
	_average=avg;
}

int DistanceSRF04::getDistanceTime()
{
	long sum = 0;
	
	for (int i=0;i<_average;i++)
	{
		digitalWrite(_trigPin, LOW);
		delayMicroseconds(2);
		digitalWrite(_trigPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(_trigPin, LOW);
		_duration = pulseIn(_echoPin, HIGH);
		sum=sum+_duration;
	}
	return(int(sum/_average));
}

int DistanceSRF04::getDistanceCentimeter()
{
	return (getDistanceTime()/29/2);
}

int DistanceSRF04::getDistanceInch()
{
	return (getDistanceTime()/74/2);
}

boolean DistanceSRF04::isCloser(int threshold)
{
	if (threshold>getDistanceCentimeter())
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

boolean DistanceSRF04::isFarther(int threshold)
{
	if (threshold<getDistanceCentimeter())
	{
		return true;
	}
	else
	{
		return false;
	}
}
