#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <avr/wdt.h>

#define CLK 8
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

#define DEFAULT_BRIGHTNESS 64

uint16_t RED, GREEN, BLACK;

//
void applyBrightness(uint8_t brightness)
{
	RED = matrix.Color888(brightness, 0, 0);
	GREEN = matrix.Color888(0, brightness, 0);
	BLACK = matrix.Color888(0, 0, 0);
}

//
void clearDisplay()
{
	matrix.fillScreen(BLACK);
}

//
void showLeft(uint8_t active)
{
	clearDisplay();

	uint16_t c = active ? GREEN : RED;
	matrix.drawLine(15-7, 7, 15+7, 7, c);
	matrix.drawLine(15-7, 7, 15, 0, c);
	matrix.drawLine(15-7, 7, 15, 14, c);
}

//
void showRight(uint8_t active)
{
	clearDisplay();

	uint16_t c = active ? GREEN : RED;
	matrix.drawLine(15-7, 7, 15+7, 7, c);
	matrix.drawLine(15+7, 7, 15, 0, c);
	matrix.drawLine(15+7, 7, 15, 14, c);
}

//
void showForward(uint8_t active)
{
	clearDisplay();

	uint16_t c = active ? GREEN : RED;
	matrix.drawLine(15, 0, 15, 15, c);
	matrix.drawLine(15, 0, 15+7, 7, c);
	matrix.drawLine(15, 0, 15-7, 7, c);
}

//
void showReverse(uint8_t active)
{
	clearDisplay();

	uint16_t c = active ? GREEN : RED;
	matrix.drawLine(15, 0, 15, 15, c);
	matrix.drawLine(15, 15, 15+7, 8, c);
	matrix.drawLine(15, 15, 15-7, 8, c);
}

//
void showVeerLeft(uint8_t active)
{
	clearDisplay();

	uint16_t c1 = GREEN;
	uint16_t c2 = active ? GREEN : RED;
	matrix.drawLine(15, 0, 15, 15, c1);
	matrix.drawLine(15, 0, 15+7, 7, c1);
	matrix.drawLine(15, 0, 15-7, 7, c1);
	matrix.drawLine(15, 0, 15-7, 0, c2);
	matrix.drawLine(15-7, 7, 15-7, 0, c2);
}

//
void showVeerRight(uint8_t active)
{
	clearDisplay();

	uint16_t c1 = GREEN;
	uint16_t c2 = active ? GREEN : RED;
	matrix.drawLine(15, 0, 15, 15, c1);
	matrix.drawLine(15, 0, 15+7, 7, c1);
	matrix.drawLine(15, 0, 15-7, 7, c1);
	matrix.drawLine(15, 0, 15+7, 0, c2);
	matrix.drawLine(15+7, 7, 15+7, 0, c2);
}

//
void safeDelay(uint32_t duration)
{
	uint32_t start = millis();
	while ((millis() - start) < duration)
		wdt_reset();
}

//
void testDisplay()
{
	matrix.setTextColor(RED);
	matrix.print("ready");
	safeDelay(1000);

	showForward(0);
	safeDelay(1000);

	showVeerLeft(0);
	safeDelay(1000);

	showVeerRight(0);
	safeDelay(1000);

	showLeft(0);
	safeDelay(1000);

	showRight(0);
	safeDelay(1000);

	showReverse(0);
	safeDelay(1000);
}

//
void showDirection(char d, uint8_t active)
{
	switch(d)
	{
	case 'F': showForward(active); break;
	case 'B': showReverse(active); break;
	case 'L': showLeft(active); break;
	case 'R': showRight(active); break;
	case 'l': showVeerLeft(active); break;
	case 'r': showVeerRight(active); break;
	default: clearDisplay(); break;
	}
}

//
void setup()
{
	wdt_disable();
	wdt_enable(WDTO_4S);

	Serial.begin(9600);
	matrix.begin();
	
	applyBrightness(DEFAULT_BRIGHTNESS);
	
	//testDisplay();

	char lastDirection = 'x';
	uint8_t lastActive = 0;
	while (1)
	{
		wdt_reset();

		while (Serial.available() < 1)
			wdt_reset();
		
		char c = Serial.read();
		
		if (c == 'D')
		{
			while (Serial.available() < 2)
				wdt_reset();

			char d = Serial.read();
			uint8_t active = Serial.read() == '1';
			showDirection(d, active);
			lastDirection = d;
			lastActive = active;
		}
		else if (c == 'B')
		{
			while (Serial.available() < 3)
				wdt_reset();

			char buf[4];
			Serial.readBytes(buf, 3);
			buf[3] = 0;
			
			uint8_t brightness = atoi(buf);
			applyBrightness(brightness);
			showDirection(lastDirection, lastActive);
		}
	}
}

//
void loop() {}
