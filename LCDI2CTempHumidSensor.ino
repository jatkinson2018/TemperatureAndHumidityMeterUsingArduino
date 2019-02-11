#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#include <SimpleDHT.h> //Load the Simple DHT11 library

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int pinDHT11 = 7; //Declare a variable setting pinDHT11 to pin 7 on the Arduino
SimpleDHT11 dht11;  //Creating the LiquidCrystal object named LCD


void setup() {
  lcd.begin(16,2); // Declare that the LCD has 16 columns and 2 rows

  lcd.setCursor(0,0); // Set the temperature text to the first columnn, first row
  lcd.print("Temperature:"); //Print Temperature: on the LCD display

  lcd.setCursor(0,1); // Set the humidity text to the first columnn, second row
  lcd.print("Humidity:"); //Print Humidity: on the LCD display
}

void loop() {

  byte temperature = 0; //Declare a variable for temperature setting value of 0
  byte humidity = 0; //Declare a variable for Humidity setting value of 0
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) { // Use an if statement to read the values from the DHT11
    return; //Terminate and return the temperature and humidity value
  }
  
  

  lcd.setCursor(12,0); // Set the resulting temperature text to the twelfth columnn, first row
  lcd.print((int)temperature); // Print resulting temperature to the LCD
  lcd.print((char)223); //Print the ° symbol after the resulting temperature has been printed
  lcd.print("C"); // Print C to the LCD after the ° symbol

  lcd.setCursor(9,1); // Set the humidity text to the ninth columnn, second row
  lcd.print((int)humidity); // Print resulting humidity to the LCD
  lcd.print("%"); // Print % to the LCD after the resulting humidity has been printed
  
  delay(1000); // update the temperature & humidity reading by 1000ms (1 second)
}
