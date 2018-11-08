#include<stdio.h>
#include<wiringPi.h>
#include<softPwm.h>


struct Silnik
{
int PIN1;
int PIN2;
int pwmPIN;
};


void forward(struct Silnik *zmienna)
{
	wiringPiSetupPhys();
	pinMode((*zmienna).PIN1, OUTPUT);
	pinMode((*zmienna).PIN2, OUTPUT);
	pinMode((*zmienna).pwmPIN, OUTPUT);
	softPwmCreate((*zmienna).pwmPIN, 1,100);
	softPwmWrite((*zmienna).pwmPIN, 80);
	digitalWrite((*zmienna).PIN1, HIGH);
	digitalWrite((*zmienna).PIN2, LOW);
}


void reverse(struct Silnik *zmienna)
{
	wiringPiSetupPhys();
	pinMode((*zmienna).PIN1, OUTPUT);
	pinMode((*zmienna).PIN2, OUTPUT);
	pinMode((*zmienna).pwmPIN, OUTPUT);
	softPwmCreate((*zmienna).pwmPIN, 1,100);
	softPwmWrite((*zmienna).pwmPIN, 80);
	digitalWrite((*zmienna).PIN1, LOW);
	digitalWrite((*zmienna).PIN2, HIGH);
};





void stop(struct Silnik *zmienna)
{
	wiringPiSetupPhys();
	pinMode((*zmienna).PIN1, OUTPUT);
	pinMode((*zmienna).PIN2, OUTPUT);
	pinMode((*zmienna).pwmPIN, OUTPUT);
	digitalWrite((*zmienna).PIN1, LOW);
	digitalWrite((*zmienna).PIN2, LOW);
};



int main()
{
	struct Silnik silnik1;
	silnik1.PIN1 = 15;
	silnik1.PIN2 = 13;
	silnik1.pwmPIN = 11;
	
	struct Silnik silnik2;
	silnik2.PIN1 = 16;
	silnik2.PIN2 = 18;
	silnik2.pwmPIN = 22;

	struct Silnik silnik3;
	silnik3.PIN1 = 21;
	silnik3.PIN2 = 23;
	silnik3.pwmPIN = 19;

	struct Silnik silnik4;
	silnik4.PIN1 = 24;
	silnik4.PIN2 = 26;
	silnik4.pwmPIN = 32;

	
	forward(&silnik1);
	//reverse(&silnik2);
	reverse(&silnik4);
	//forward(&silnik4);
	delay(1000);
	stop(&silnik1);
	stop(&silnik4);
	delay(1000);
	reverse(&silnik1);
	forward(&silnik4);
	delay(1000);
	stop(&silnik1);
	stop(&silnik4);

	
return 0;
}
