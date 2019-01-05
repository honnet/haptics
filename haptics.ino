// Testing Taptic engine for linear psycho-haptic traction

// Source: https://rekimotolab.files.wordpress.com/2014/03/traxionuist13.pdf
// Taptic Engine: https://en.wikipedia.org/wiki/IPhone#Taptic_Engine
// H-bridge: http://www.ti.com/lit/ds/symlink/l293.pdf

int led = 13;

// to connect to H-bridge (enable pin is not connected)
int pin_a = 0;
int pin_b = 1;

// values recommended by traxion --- TODO: control with various speed!
int duty_c = 20; // %
int period = 10; // ms

int time_a =      duty_c  * period / 100;
int time_b = (100-duty_c) * period / 100;


void setup() {
  pinMode(led, OUTPUT);

  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
}

void loop() {
  digitalWrite(pin_a, HIGH);
  digitalWrite(pin_b, LOW);
  delay(time_a);

  digitalWrite(pin_a, LOW);
  digitalWrite(pin_b, HIGH);
  delay(time_b);

  static int cpt = 0;
  if (++cpt % 10 == 0)
      digitalWrite(led, !digitalRead(led));
}

